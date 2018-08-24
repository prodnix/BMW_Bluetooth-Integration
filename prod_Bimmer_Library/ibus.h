#ifndef ibus_h
#define ibus_h
#include "Arduino.h"


class ibus
{
  public:
    ibus();
    byte checkIbus();
    
  private:
  byte getCheckSumIbus(bool io, int len);
};

#endif