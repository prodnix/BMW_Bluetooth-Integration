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
  digitalWrite(P1_5, HIGH);
  digitalWrite(P3_6, LOW);
  digitalWrite(ledPin,LOW);

  delay(1000);

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
    ibusMessageHandler();
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
    case 0x50: // ####################################### Source = MFL
      switch (Ibus.InPacket.Destination) {
        case 0x68:
          if (Ibus.InPacket.Data[0] == 0x3B) {
            switch (Ibus.InPacket.Data[1]) {
              case 0x01:
              debugSerial.println(F("MFL Up Pressed"));
              btSerial.write(NEXT_SONG, sizeof(NEXT_SONG));
              break;
              case 0x21:
              break;
              case 0x08:
              debugSerial.println(F("MFL Down Pressed"));
              btSerial.write(PREV_SONG, sizeof(PREV_SONG));
              break;
              case 0x28:
              break;
            }
          } else {
            if (Ibus.InPacket.Data[1] == 0x11) {
              debugSerial.println(F("MFL VOL_UP Pressed"));
            } else {
              debugSerial.println(F("MFL VOL_DOWN Pressed"));
            }
          }
        break;
        case 0xC8:
          switch(Ibus.InPacket.Data[0]) {
            case 0x01:
            if (rtCount > 2) {
              debugSerial.println(F("R/T Pressed"));
              btSerial.write(PLAY_PAUSE, sizeof(PLAY_PAUSE));
              //btSerial.write(A2DP_FULL_VOL, 11);
              ibusSerial.write(CLOWN_FLASH, 7);
            } else {
              rtCount++;
            }
            break;
            case 0x32:
              if (Ibus.InPacket.Data[1] == 0x11) {

              } else {

              }
            break;
            case 0x3B:
            if (Ibus.InPacket.Data[1] == 0x80) {
              debugSerial.println(F("MFL Voice Pressed"));
              btSerial.write(ASSISTANT, sizeof(ASSISTANT));
            } else {
              //Voice Release
            }
            break;
          }
        break;
        case 0xB0:

        break;
      }
    break;
    case 0x44: // ####################################### Source = Keys
      if (Ibus.InPacket.Destination == 0xBF) {
        switch (Ibus.InPacket.Data[0]) {
          case 0x74:
          if (Ibus.InPacket.Data[1] == 0x00 && Ibus.InPacket.Data[2] == 0xFF) {
            debugSerial.println(F("Key Out"));
            btSerial.write(DISCONNECT, sizeof(DISCONNECT));
          }
          else if (Ibus.InPacket.Data[1] == 0x04 && Ibus.InPacket.Data[2] == 0x04){
            debugSerial.println("Key In");
            btSerial.write(PAIR_LAST_DEVICE, sizeof(PAIR_LAST_DEVICE));
          }
          else {
            debugSerial.print("Unknown Key In/Out Command : ");
            ibusDump();
          }
        }
      } else {
        debugSerial.print("Unknown Command  : ");
        ibusDump();
      }
    break;
    case 0x80: // ####################################### Source = Ignition
      if (Ibus.InPacket.Destination == 0xBF) {
        switch (Ibus.InPacket.Data[0]) {
          case 0x11:
            switch (Ibus.InPacket.Data[1]) {
              case 0x00:  // Ignition Off
              break;
              case 0x01:  // Ignition pos1
                rtCount = 0;
              break;
              case 0x04:  // Ignition pos2
              break;
              default:
                debugSerial.print("Unknown Ignition Command : ");
                ibusDump();
            }
        }
      } else {
        debugSerial.print("Unknown Command  : ");
        ibusDump();
      }
    break;

    default:
      debugSerial.print("Disregarded Message :");
      ibusDump();
  }
}

void ibusDump() {
  debugSerial.print("Source:");
  debugSerial.print(Ibus.InPacket.Source, HEX);
  debugSerial.print(" Destination:");
  debugSerial.print(Ibus.InPacket.Destination, HEX);
  debugSerial.print("  Data:");
  for (int i = 0; i < Ibus.InPacket.Length; i++) {
    debugSerial.print(Ibus.InPacket.Data[i], HEX);
    debugSerial.print(":");
  }
  debugSerial.println();
}
