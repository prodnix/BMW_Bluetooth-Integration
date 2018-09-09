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
    //debugSerial.println(InPacket.Source, HEX);
    InPacket.Length = ibusSerial.read() - 2;
    //debugSerial.println(InPacket.Length, HEX);
    InPacket.Destination = ibusSerial.read();
    //debugSerial.println(InPacket.Destination, HEX);
    if (ibusSerial.readBytes(InPacket.Data, InPacket.Length) == InPacket.Length) {
      for (int i = 0; i < InPacket.Length; i++) {
        //debugSerial.println(InPacket.Data[i], HEX);
      }
      //debugSerial.println("Ibus Message recieved");
      while (ibusSerial.available() == 0) {
        //debugSerial.println("No Serial data Available");
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
