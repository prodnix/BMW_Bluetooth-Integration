#include "ibus.h"
#include "bm64.h"
#include "data_store.h"
#include "bt_commands.h"
#include "ibus_commands.h"


#define debugSerial Serial
#define btSerial    Serial1
#define ibusSerial  Serial2
//#define testSerial  Serial3

const byte P1_5 = 11;
const byte P3_6 = 6;
const byte P2_0Pin = 7;
const byte EANPin = 5;
const byte btResetPin = 10;
const byte MFBPin = 8;
const byte ledPin = 13;

byte rtCount = 0;

bm64 BM64;
ibus Ibus;


//########################################################################

void setup() {
  
  debugSerial.begin(115200);
  btSerial.begin(115200);
  ibusSerial.begin(9600, SERIAL_8E1);
  
  pinMode(btResetPin, OUTPUT);
  pinMode(P1_5, OUTPUT);
  pinMode(P3_6, OUTPUT);
  pinMode(MFBPin, OUTPUT);
  pinMode(P2_0Pin, OUTPUT);
  pinMode(EANPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(btResetPin, HIGH);
  digitalWrite(MFBPin, HIGH);
  digitalWrite(P2_0Pin, HIGH);
  digitalWrite(EANPin, LOW);
  digitalWrite(P1_5, 1);
  digitalWrite(P3_6, 0);
  digitalWrite(ledPin, 0);
  
  delay(100);
  
  btSerial.write(POWER_BUTTON_PRESS, 7);
  delay(250);
  btSerial.write(POWER_BUTTON_RELEASE, 7);
  
  debugSerial.println("prods BMW Interface Started.");
  
  /*while (1) {
    if (ibusSerial.available() > 0) {
      debugSerial.print(ibusSerial.read(), HEX);
      debugSerial.print(";");
    }
  }*/
}

//########################################################################

void loop() {
  if (!Ibus.checkIbus()) {
    debugSerial.println("Ibus Message Recieved!!!!!");
  }
  
  if (!BM64.checkbtSerial()) {
    btMessageHandler();
  }
}

void btMessageHandler() {
  switch (BM64.InPacket.Data[0]) {
    case 0x00:
      debugSerial.print("ACK Received : ");
      debugSerial.println(ACK_RESPONSE[BM64.InPacket.Data[2]]);
      break;

    case 0x01:
      debugSerial.println(BTM_STATUS[BM64.InPacket.Data[1]]);
      switch (BM64.InPacket.Data[1]) {
        case 0x06:
          btSerial.write(A2DP_FULL_VOL, 11);
          debugSerial.println("Full Volume");
          break;
      }
      break;

    case 0x0A:
      debugSerial.print("Signal Strength : ");
      debugSerial.println(BM64.InPacket.Data[2]);
      break;

    case 0x1C:
      debugSerial.println(AT_CMD_RSP[BM64.InPacket.Data[2]]);
      break;

    case 0x22:
      debugSerial.println("Mobile Serial Received");
      break;

    case 0x0D:
      debugSerial.println(CHARGING_STATUS[BM64.InPacket.Data[1]]);
      break;
    
    case 0x2D:
      debugSerial.print(SAMPLE_RATE[BM64.InPacket.Data[1]]);
      debugSerial.print(" Sample Rate, ");
      debugSerial.println(SAMPLE_RATE_MODE[BM64.InPacket.Data[2]]);
      break;

    case 0x18:
      debugSerial.print("Version Reported : ");
      debugSerial.print(BM64.InPacket.Data[2]);
      debugSerial.print(".");
      debugSerial.println(BM64.InPacket.Data[3]);
      break;

    case 0x1A:
      break;

    case 0x1B:
      switch(BM64.InPacket.Data[1]) {
        case 0x00:
          if (BM64.InPacket.Data[2] != 1) {
            debugSerial.println("Mute or switch off amp.");
          } else {
            debugSerial.println("Unmute or switch on amp.");
          }
          break;
        case 0x01:
          debugSerial.println(AUX_LINE_DETECT[BM64.InPacket.Data[2]]);
          break;
        case 0x02:
          if (BM64.InPacket.Data[2] != 1) {
            debugSerial.println("BTM FW Update");
          } else {
            debugSerial.println("MCU FW Update");
          }
          break;
        case 0x03:
          debugSerial.println("EEPROM Update Successful");
          break;
        case 0x04:
          if (BM64.InPacket.Data[2] != 1) {
            debugSerial.println("A2DP Stop");
          } else {
            debugSerial.println("A2DP Start");
          }
          break;
        case 0x06:
          if (BM64.InPacket.Data[2] != 1) {
            debugSerial.println("Volume Up");
          } else {
            debugSerial.println("Volume Down");
          }
          break;
      }
      break;

    default:
      for (int i = 0; i < BM64.InPacket.Length; i++) {
        debugSerial.print(BM64.InPacket.Data[i], HEX);
        debugSerial.print(", ");
      }
      debugSerial.println();
  }
}

void ibusMessageHandler() {
  
  switch (Ibus.InPacket.Source) {
    case 0x50:
      switch (Ibus.InPacket.Destination) {
        case 0x68:
          
        break;
      }
    break;
    
    case 0x44:
      
    break;
  }
  
  
  
  
  
  
  
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
  
    
    //btSerial.write(INIT_HF_HS_PROFILE_CONNECTION, sizeof(INIT_HF_HS_PROFILE_CONNECTION));
    //btSerial.write(VOICE_DIAL, sizeof(VOICE_DIAL));
    //btSerial.write(FW_VER, sizeof(FW_VER));
    //btSerial.write(FAST_ENTER_PAIRING_MODE, sizeof(FAST_ENTER_PAIRING_MODE));
    //btSerial.write(NON_CONNECTABLE_MODE, sizeof(NON_CONNECTABLE_MODE));
    //btSerial.write(MASTER_RESET, sizeof(MASTER_RESET));
    //btSerial.write(NORMAL_PAIRING_MODE, sizeof(NORMAL_PAIRING_MODE));
    //btSerial.write(PAIRING_MODE, sizeof(PAIRING_MODE));
    
  
}