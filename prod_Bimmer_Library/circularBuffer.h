#ifndef circularBuffer_h
#define circularBuffer_h
#include "Arduino.h"


class circularBuffer
{
  public:
    circularBuffer(unsigned int size);
    byte In(byte i);
    byte Out(byte o);
    byte Available();
    byte Read(byte index);
    void Debug();
  
  private:
    byte _head = 0;
    byte _tail = 0;
    unsigned int _size;
    byte _buffer[];
};

#endif