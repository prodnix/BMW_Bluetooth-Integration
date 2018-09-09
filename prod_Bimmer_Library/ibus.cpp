#include "Arduino.h"
#include "ibus.h"

#define debugSerial Serial
#define ibusSerial  Serial2

ibus::ibus() {
  struct IbusPacket InPacket;
  struct IbusPacket OutPacket;
}

byte ibus::checkIbus() {
  if (ibusSerial.available() >= 3) {
    InPacket.Source = ibusSerial.read();
    InPacket.Length = ibusSerial.read() - 2;
    InPacket.Destination = ibusSerial.read();
    if (ibusSerial.readBytes(InPacket.Data, InPacket.Length) == InPacket.Length) {
      while (ibusSerial.available() == 0) {
      }
      InPacket.Checksum = ibusSerial.read();
      if (getChecksum(1) == InPacket.Checksum) {
        return(0);
      }
      else {
        debugSerial.println("Ibus Bad Checksum");
        debugSerial.print("Ibus Checksum : ");
        debugSerial.println(getChecksum(1), HEX);
        return(2);
      }
    } else {
      debugSerial.println("Ibus Not enough Data");
      return(2);
    }
  } else {
    return(1);
  }
}

byte ibus::getChecksum(bool io) {
  if (io == 1){
    int XOR = 0;
    XOR = XOR ^ InPacket.Source;
    XOR = XOR ^ InPacket.Length + 2;
    XOR = XOR ^ InPacket.Destination;
    for (int i = 0; i < InPacket.Length; i++)
    {
      XOR = XOR ^ InPacket.Data[i];
    }
    return(XOR);
  } else {

  }
}
