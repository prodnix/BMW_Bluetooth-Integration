#include "Arduino.h"
#include "bm64.h"
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
    debugSerial.print("BM64=");
    debugSerial.print(i, HEX);
    debugSerial.print(" : ");
    BTBuffer.Debug();
  }
  
  if (BTBuffer.Available() > 1 && BTBuffer.Read(0) == 0x00 && BTBuffer.Read(1) == 0xAA) {   // Removing 0x00 wake byte.
    BTBuffer.Out(1);
    debugSerial.print("BM64:Wake Out");
    BTBuffer.Debug();
  }
  
  if (BTBuffer.Available() > 4) {
    byte length = BTBuffer.Read(1) + BTBuffer.Read(2) + 4;
    if (length <= BTBuffer.Available()) {
      if (getCheckSumBT(1, length) == BTBuffer.Read(length - 1)) {
        debugSerial.println("BM64:Checksum Good.");
        BTBuffer.Out(length);
      } else {
        debugSerial.println("BM64:Checksum BAD!!!!!");
        BTBuffer.Reset();
      }
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