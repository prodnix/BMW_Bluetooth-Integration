#ifndef bm64_h
#define bm64_h
#include "Arduino.h"

struct BM64Packet {
  public:
    byte Length1;
    byte Length2;
    unsigned int Length;
    byte Data[250];
    byte Checksum;
};

class bm64
{
  public:
    bm64();
    byte checkbtSerial();
    void sendACK (byte event);
    void Debug();
    struct BM64Packet InPacket;
    struct BM64Packet OutPacket;
    
  private:
    byte getChecksum(bool io);
    void Reset();
    int c;
};

#endif