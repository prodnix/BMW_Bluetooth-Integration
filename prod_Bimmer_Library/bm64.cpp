#include "Arduino.h"
#include "bm64.h"
#include "bt_data_store.h"

#define debugSerial Serial
#define btSerial    Serial1

bm64::bm64() {
  struct BM64Packet InPacket;
  struct BM64Packet OutPacket;
}

byte bm64::checkbtSerial() {
  if (btSerial.available() >= 5) {
    if (btSerial.read() == 0 && btSerial.read() == 0xAA) {
      InPacket.Length1 = btSerial.read();
      InPacket.Length2 = btSerial.read();
      InPacket.Length = InPacket.Length1 + InPacket.Length2;
      while (btSerial.available() <= InPacket.Length) {
        //debugSerial.println("No Serial data Available");
      }
      if (btSerial.readBytes(InPacket.Data, InPacket.Length) == InPacket.Length) {
        while (btSerial.available() == 0) {
          //debugSerial.println("No Serial data Available");
        }
        InPacket.Checksum = btSerial.read();
        if (getChecksum(1) == InPacket.Checksum) {
          if (InPacket.Data[0] != 0x00) {
            sendACK(InPacket.Data[0]);
          }
          return(0);
        } else {
          //btSerial.flush();
          debugSerial.println("BT Bad Checksum!!");
          Debug();
          Reset();
          return(2);
        }
      } else {
        //btSerial.flush();
        debugSerial.println("BT Not enough data in buffer!");
        Debug();
        Reset();
        return(2);
      }
    } else {
      //btSerial.flush();
      debugSerial.println("BT Wake and AA wrong!");
      Debug();
      Reset();
      return(2);
    }
  } else {
    return(1);
  }
}


byte bm64::getChecksum(bool io) {
  if (io == 1){
    byte SUM = InPacket.Length;
    for (int i = 0 ; i < InPacket.Length; i++) {
      SUM = SUM + InPacket.Data[i];
    }
    byte flip = ~SUM;
    return(flip + 1);
  } else {

  }
}

void bm64::sendACK(byte event) {
  byte c = event + 22;
  c = ~c + 1;
  byte ACK[] = { 0xAA, 0x00, 0x02, 0x14, event, c };
  btSerial.write(ACK, 6);
}

void bm64::Debug() {
  debugSerial.print("BT Packet = ");
  debugSerial.print(InPacket.Length1);
  debugSerial.print(",");
  debugSerial.print(InPacket.Length2);
  debugSerial.print(",");
  for (int i = 0; i < InPacket.Length; i++) {
    debugSerial.print(InPacket.Data[i], HEX);
    debugSerial.print(",");
  }
  debugSerial.print(" Checksum = ");
  debugSerial.println(InPacket.Checksum, HEX);
  debugSerial.print("Checksum in algo = ");
  debugSerial.println(getChecksum(1), HEX);
  debugSerial.print("Length = ");
  debugSerial.println(InPacket.Length);
}

void bm64::Reset() {
  InPacket.Length1 = 0;
  InPacket.Length2 = 0;
  InPacket.Length = 0;
  //InPacket.Data[];
  InPacket.Checksum = 0;
}
