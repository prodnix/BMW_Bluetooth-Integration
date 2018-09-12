#ifndef ibus_h
#define ibus_h
#include "Arduino.h"

struct IbusPacket {
  public:
    byte Source;
    byte Length;
    byte Destination;
    byte Data[32];
    byte Checksum;
};

class ibus
{
  public:
    ibus();
    byte checkIbus();
    void Dump();
    struct IbusPacket InPacket;
    struct IbusPacket OutPacket;
    //void sendIbusCommand(const byte message[], byte size);

  private:
  byte getChecksum(bool io);
};

#endif
