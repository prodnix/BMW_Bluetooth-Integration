#include "Arduino.h"
#include "circularBuffer.h"

#define debugSerial Serial

circularBuffer::circularBuffer(unsigned int size) {
  _size = size;
  _buffer[_size];
}

byte circularBuffer::In(byte i) {
  _buffer[_head] = i;
  _head = (_head + 1) % _size;
  return(_head);
}

byte circularBuffer::Out(byte o) {
  _tail = (_tail + o) % _size;
}

byte circularBuffer::Read(byte index) {
  return(_buffer[(_tail + index) % _size]);
}

byte circularBuffer::Available() {
  byte a = _head - _tail;
  return(a % _size);
}

void circularBuffer::Debug() {
  debugSerial.print("tail:");
  debugSerial.print(_tail);
  debugSerial.print(" head:");
  debugSerial.print(_head);
  debugSerial.print(" available:");
  debugSerial.println(Available());
}