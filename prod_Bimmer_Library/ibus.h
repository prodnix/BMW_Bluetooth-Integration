#ifndef ibus_h
#define ibus_h
#include "Arduino.h"


class ibus
{
  public:
    ibus();
    byte ibusInByte[256];
    byte checkIbus();
    //void sendIbusCommand(const byte message[], byte size);
    
  private:
  byte getCheckSumIbus(bool io, int len);
};

#endif