#ifndef bm64_h
#define bm64_h
#include "Arduino.h"


class bm64
{
  public:
    bm64();
    void checkbtSerial();

  private:
    byte getCheckSumBT(bool io, int len);
};

#endif