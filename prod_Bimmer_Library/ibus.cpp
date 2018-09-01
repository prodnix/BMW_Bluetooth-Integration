#include "Arduino.h"
#include "ibus.h"
#include "circularBuffer.h"

#define debugSerial Serial
#define btSerial    Serial1
#define ibusSerial  Serial2

circularBuffer IbusBuffer(256);

ibus::ibus() {
//ibusInByte[256];
}

byte ibus::checkIbus() {
  while (ibusSerial.available() > 0) {
    byte i = ibusSerial.read();
    IbusBuffer.In(i);
  }
  
  if (IbusBuffer.Available() > 4) {
    if (IbusBuffer.Read(1) == 0) {
      IbusBuffer.Reset();
    }
    byte ibusLength = IbusBuffer.Read(1) + 2;
    if (ibusLength > IbusBuffer.Available()) {
      return (0);
    }
    if (getCheckSumIbus(1, ibusLength) == IbusBuffer.Read(ibusLength - 1)) {
      debugSerial.print("Ibus: Good Command: ");
      //IbusBuffer.Debug();
      for (int i = 0; i < ibusLength - 1; i++) {
        ibusInByte[i] = IbusBuffer.Read(i);
      }
      IbusBuffer.Out(ibusLength);
      return(ibusLength);
    } else {
      debugSerial.print("Ibus: Bad Command: ");
      IbusBuffer.Debug();
      IbusBuffer.Dump();
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

/*void ibus::sendIbusCommand(const byte message[], byte size) {
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
*/