#ifndef circularBuffer_h
#define circularBuffer_h
#include "Arduino.h"


class circularBuffer
{
  public:
    circularBuffer(unsigned int size);
    void In(byte in);                       // 1 Byte to be added to buffer at head.
    void Out(byte out);                     // How many bytes to remove from Buffer.
    byte Available();                       // Returns number of bytes in buffer.
    byte Read(byte index);                  // Returns byte from index relative to tail.
    void Debug();                           // Prints head, tail and available bytes to debug serial.
    void Reset();                           // Reset head and tail to 0.
    
  private:
    byte head_;                             // Position of head in buffer array.
    byte tail_;                             // Position of tail in buffer array.
    unsigned int size_;                     // Size of buffer array.
    byte buffer_[];                         // Contents of buffer.
};

#endif