#include "Arduino.h"
#include "ibus.h"
#include "circularBuffer.h"

#define debugSerial Serial
#define btSerial    Serial1
#define ibusSerial  Serial2

circularBuffer IbusBuffer(256);

ibus::ibus() {
}

byte ibus::checkIbus() {
  while (ibusSerial.available() > 0) {
    byte i = ibusSerial.read();
    IbusBuffer.In(i);
    debugSerial.print("IBUS=");
    debugSerial.print(i, HEX);
    debugSerial.print(" : ");
    IbusBuffer.Debug();
  }
  
  if (IbusBuffer.Available() > 4) {
    byte ibusLength = IbusBuffer.Read(1) + 2;
    debugSerial.println(ibusLength);
    if (ibusLength > IbusBuffer.Available()) {
      return (0);
    }
    if (getCheckSumIbus(1, ibusLength) == IbusBuffer.Read(ibusLength - 1)) {
      debugSerial.println(F("IBUS : Good Command"));
      IbusBuffer.Out(ibusLength);
      return(ibusLength);
    } else {
      debugSerial.println(F("IBUS : Bad Command"));
      IbusBuffer.Reset();
      return(0);
    }
  }
  return(0);
}

byte ibus::getCheckSumIbus(bool io, int len) {
  if (io == 1){
    int XOR = 0;  
    for (int i = 0; i < len - 1; i++) 
    {
      XOR = XOR ^ IbusBuffer.Read(i);
    }
    return(XOR);
  } else {
    
  }
}