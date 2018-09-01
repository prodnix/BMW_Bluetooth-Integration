#include "ibus.h"
#include "bm64.h"


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

const byte POWER_BUTTON_PRESS [7] = { 0xAA , 0x00 , 0x03 , 0x02 , 0x00 , 0x51 , 0xAA };
  
const byte POWER_BUTTON_RELEASE [7] = { 0xAA , 0x00 , 0x03 , 0x02 , 0x00 , 0x52 , 0xA9 };

bm64 BM64;
ibus Ibus;


//########################################################################

void setup() {
  
  debugSerial.begin(9600);
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
  delay(1000);
  while (ibusSerial.available()) {
    byte i = ibusSerial.read();
  }
  
}

//########################################################################

void loop() {
  Ibus.checkIbus();
  BM64.checkbtSerial();
}

/*void processIbusCommand(int len) {
  
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
    
  
}*/