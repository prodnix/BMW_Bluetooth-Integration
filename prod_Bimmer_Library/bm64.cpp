#include "Arduino.h"
#include "bm64.h"
#include "ibus_commands.h"
#include "bt_commands.h"
#include "data_store.h"
#include "circularBuffer.h"

#define debugSerial Serial
#define btSerial Serial1
#define ibusSerial Serial2

circularBuffer BTBuffer(256);

bm64::bm64() {
}

void bm64::checkbtSerial() {
  while (btSerial.available() > 0) {
    byte i = btSerial.read();
    BTBuffer.In(i);
  }
  if (BTBuffer.Available() > 1 && BTBuffer.Read(0) == 0x00 && BTBuffer.Read(1) == 0xAA) {
    BTBuffer.Out(1);
  }
  if (BTBuffer.Available() > 4) {
    searchbtSerial();
  }
}

void bm64::searchbtSerial() {
  byte length = BTBuffer.Read(1) + BTBuffer.Read(2) + 4;
  //debugSerial.println(length);
  if (length <= BTBuffer.Available()) {
    //debugSerial.println("Found complete message");
    if (getCheckSumBT(1, length) == BTBuffer.Read(length - 1)) {
      //debugSerial.print("BT: Checksum Good: ");
      //BTBuffer.Debug();
      btSerialMessageHandler(length);
      BTBuffer.Out(length);
    } else {
      debugSerial.println("BT: Checksum BAD!!!!! ");
      BTBuffer.Debug();
      BTBuffer.Dump();
      BTBuffer.Reset();
    }
    
  }
}

byte bm64::getCheckSumBT(bool io, int len) {
  if (io == 1){
    int SUM = 0;  
    for (int i = 1 ; i < len - 1; i++) 
    { SUM = SUM + BTBuffer.Read(i); }
    byte flip = ~SUM;
    return(flip + 1);
  }
}

void bm64::btSerialMessageHandler(byte len) {
  switch (BTBuffer.Read(3)) {
    case 0x00:
      debugSerial.print("ACK Received : ");
      debugSerial.println(ACK_RESPONSE[BTBuffer.Read(5)]);
      break;

    case 0x01:
      debugSerial.println(BTM_STATUS[BTBuffer.Read(4)]);
      switch (BTBuffer.Read(4)) {
        case 0x06:
          btSerial.write(A2DP_FULL_VOL, 11);
          debugSerial.println("Full Volume");
          break;
      }
      break;

    case 0x0A:
      debugSerial.print("Signal Strength : ");
      debugSerial.println(BTBuffer.Read(5));
      break;

    case 0x1C:
      debugSerial.println(AT_CMD_RSP[BTBuffer.Read(5)]);
      break;

    case 0x22:
      debugSerial.println("Mobile Serial Received");
      break;

    case 0x0D:
      debugSerial.println(CHARGING_STATUS[BTBuffer.Read(4)]);
      break;
    
    case 0x2D:
      debugSerial.print(SAMPLE_RATE[BTBuffer.Read(4)]);
      debugSerial.print(" Sample Rate, ");
      debugSerial.println(SAMPLE_RATE_MODE[BTBuffer.Read(5)]);
      break;

    case 0x18:
      debugSerial.print("Version Reported : ");
      debugSerial.print(BTBuffer.Read(5));
      debugSerial.print(".");
      debugSerial.println(BTBuffer.Read(6));
      break;

    case 0x1A:
      break;

    case 0x1B:
      switch(BTBuffer.Read(4)) {
        case 0x00:
          if (BTBuffer.Read(5) != 1) {
            debugSerial.println("Mute or switch off amp.");
          } else {
            debugSerial.println("Unmute or switch on amp.");
          }
          break;
        case 0x01:
          debugSerial.println(AUX_LINE_DETECT[BTBuffer.Read(5)]);
          break;
        case 0x02:
          if (BTBuffer.Read(5) != 1) {
            debugSerial.println("BTM FW Update");
          } else {
            debugSerial.println("MCU FW Update");
          }
          break;
        case 0x03:
          debugSerial.println("EEPROM Update Successful");
          break;
        case 0x04:
          if (BTBuffer.Read(5) != 1) {
            debugSerial.println("A2DP Stop");
          } else {
            debugSerial.println("A2DP Start");
          }
          break;
        case 0x06:
          if (BTBuffer.Read(5) != 1) {
            debugSerial.println("Volume Up");
          } else {
            debugSerial.println("Volume Down");
          }
          break;
      }
      break;

    default:
      for (int i = 0; i < len; i++) {
        debugSerial.print(BTBuffer.Read(i), HEX);
        debugSerial.print(", ");
      }
      debugSerial.println();
  }
  if (BTBuffer.Read(3) != 0x00) {
    sendACK(BTBuffer.Read(3));
  }
}

void bm64::sendACK (byte event) {
  byte c = event + 22;
  c = ~c + 1;
  byte ACK[] = { 0xAA, 0x00, 0x02, 0x14, event, c };
  btSerial.write(ACK, 6);
  /*debugSerial.print("ACK Sent: 0xAA, 0x00, 0x02, 0x14, 0x"); 
  debugSerial.print(event, HEX);
  debugSerial.print(", 0x");
  debugSerial.println(c, HEX);*/
}
