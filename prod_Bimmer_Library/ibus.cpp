#include "Arduino.h"
#include "ibus.h"
#include "ibus_commands.h"
#include "bt_commands.h"
#include "circularBuffer.h"

#define debugSerial Serial
#define btSerial    Serial1
#define ibusSerial  Serial2

int ibusReceived = 0;
int ibusLength = 0;
byte ibusInByte[64];
byte rtCount = 0;

//circularBuffer IbusBuffer(256);

ibus::ibus() {
}

bool ibus::checkIbus() {
  if (ibusSerial.available()) {
    while (ibusSerial.available() > 0) {
      ibusInByte[ibusReceived] = ibusSerial.read();
      ibusReceived++;
    }
    return(1);
  } else {
    return(0);
  }
}

void ibus::searchIbus() {
  ibusLength = ibusInByte[1] + 2;
  if (ibusLength == ibusReceived) {
    int checkSum = getCheckSumIbus(1, ibusLength);
    /*debugSerial.print("checksum = ");
    debugSerial.println(checkSum, HEX);*/
    if (checkSum == ibusInByte[ibusLength - 1]) {
      //debugSerial.println(F("Found Good Command"));
      processIbusCommand(ibusLength);
      for (int i = 0; i < ibusReceived; i++) {
        ibusInByte[i] = ibusInByte[ibusLength + i];
      }
      ibusReceived = ibusReceived - ibusLength;
      ibusLength = 0;
    } else {
      debugSerial.println(F("Bad Command"));
      for (int i = 0; i < ibusReceived; i++) {
        ibusInByte[i] = ibusInByte[i + 1];
      }
      ibusReceived--;
    }
  }
}

void ibus::processIbusCommand(int len) {
  
  if(memcmp_P(ibusInByte, IGNITION_POS1, 6) == 0 ) {
    rtCount = 0;
    debugSerial.println(F("Ignition 1"));
    btSerial.write(PAIR_LAST_DEVICE, sizeof(PAIR_LAST_DEVICE));
  }
  if(memcmp_P(ibusInByte, IGNITION_POS2, 6) == 0 ) {
    debugSerial.println(F("Ignition 2"));
  }
  if(memcmp_P(ibusInByte, KEY_OUT, 7) == 0 ) {
    debugSerial.println(F("Key Out"));
    btSerial.write(DISCONNECT, sizeof(DISCONNECT));
  }
  if(memcmp_P(ibusInByte, MFL_RT_PRESS, 5) == 0 ) {
    if (rtCount > 2) {
      debugSerial.println(F("R/T Pressed"));
      btSerial.write(PLAY_PAUSE, sizeof(PLAY_PAUSE));
      //btSerial.write(A2DP_FULL_VOL, 11);
      ibusSerial.write(CLOWN_FLASH, 7);
    } else {
      rtCount++;
    }
  }
  if(memcmp_P(ibusInByte, MFL_UP, 6) == 0 ) {
    debugSerial.println(F("MFL Up Pressed"));
    btSerial.write(NEXT_SONG, sizeof(NEXT_SONG));
    //buttonProcess(3, 1);
  }
  if(memcmp_P(ibusInByte, MFL_UP_RELEASE, 6) == 0 ) {
    debugSerial.println(F("MFL Up Released"));
    //buttonProcess(3, 0);
  }
  if(memcmp_P(ibusInByte, MFL_DOWN, 6) == 0 ) {
    debugSerial.println(F("MFL Down Pressed"));
    btSerial.write(PREV_SONG, sizeof(PREV_SONG));
    //buttonProcess(2, 1);
  }
  if(memcmp_P(ibusInByte, MFL_DOWN_RELEASE, 6) == 0 ) {
    debugSerial.println(F("MFL Down Released"));
    //buttonProcess(2, 0);
  }
  if(memcmp_P(ibusInByte, MFL_SEND_END_PRESS, 6) == 0 ) {
    debugSerial.println(F("MFL Voice Pressed"));
    btSerial.write(ASSISTANT, sizeof(ASSISTANT));
    //buttonProcess(0, 1);
  }
  if(memcmp_P(ibusInByte, MFL_SEND_END_PRESS_RELEASE, 6) == 0 ) {
    debugSerial.println(F("MFL Voice Released"));
    //buttonProcess(0, 0);
  }
  if(memcmp_P(ibusInByte, MFL_VOL_UP, 6) == 0 ) {
    debugSerial.println(F("MFL VOL_UP Pressed"));
    //buttonProcess(2, 0);
  }
  if(memcmp_P(ibusInByte, MFL_VOL_DOWN, 6) == 0 ) {
    debugSerial.println(F("MFL VOL_DOWN Pressed"));
    //buttonProcess(2, 0);
  }
  
    /*
    btSerial.write(INIT_HF_HS_PROFILE_CONNECTION, sizeof(INIT_HF_HS_PROFILE_CONNECTION));
    btSerial.write(VOICE_DIAL, sizeof(VOICE_DIAL));
    btSerial.write(FW_VER, sizeof(FW_VER));
    btSerial.write(FAST_ENTER_PAIRING_MODE, sizeof(FAST_ENTER_PAIRING_MODE));
    btSerial.write(NON_CONNECTABLE_MODE, sizeof(NON_CONNECTABLE_MODE));
    btSerial.write(MASTER_RESET, sizeof(MASTER_RESET));
    btSerial.write(NORMAL_PAIRING_MODE, sizeof(NORMAL_PAIRING_MODE));
    btSerial.write(PAIRING_MODE, sizeof(PAIRING_MODE));
    */
  
}

byte ibus::getCheckSumIbus(bool io, int len)
{
  if (io == 1){
    int XOR = 0;  
    for (int i = 0; i < len - 1; i++) 
    {
      XOR = XOR ^ ibusInByte[i];
    }
    return(XOR);
  } else {
    
  }
}

void ibus::sendIbusCommand(const byte message[], byte size) {
  byte messageNew[size];
  //debugSerial.print("Generated : ");
  for (int i = 0; i < size; i++) {
    messageNew[i] = pgm_read_byte(&message[i]);
    debugSerial.print(messageNew[i], HEX);
    debugSerial.print(", ");
  }

  debugSerial.println("Sending Command");
  digitalWrite(21, LOW);
  ibusSerial.write(messageNew, size);
}