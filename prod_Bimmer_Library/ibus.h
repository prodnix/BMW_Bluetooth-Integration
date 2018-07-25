#ifndef ibus_h
#define ibus_h
#include "Arduino.h"


class ibus
{
  public:
    ibus();
    bool checkIbus();
    void searchIbus();
    void processIbusCommand(int len);
    byte getCheckSumIbus(bool io, int len);
    void sendIbusCommand(const byte message[], byte size);
    
  private:
};

#endif