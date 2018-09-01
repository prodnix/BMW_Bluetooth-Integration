#include "Arduino.h"
#include "circularBuffer.h"

#define debugSerial Serial

circularBuffer::circularBuffer(unsigned int size) {
  size_ = size;
  buffer_[size_];
  head_ = 0;
  tail_ = 0;
}

void circularBuffer::In(byte in) {
  buffer_[head_] = in;
  head_ = (head_ + 1) % size_;
}

void circularBuffer::Out(byte out) {
  if (tail_ == head_) {
    debugSerial.println("Buffer Flip!");
    tail_ = 0;
    head_ = 0;
  } else {
    tail_ = (tail_ + out) % size_;
  }
}

byte circularBuffer::Read(byte index) {
  return(buffer_[(tail_ + index) % size_]);
}

byte circularBuffer::Available() {
  byte a = head_ - tail_;
  return(a % size_);
}

void circularBuffer::Debug() {
  //byte *ptail_ = tail_;
  debugSerial.print("tail:");
  debugSerial.print(tail_);
  //debugSerial.print("@");
  //debugSerial.print(&tail_, DEC);
  debugSerial.print(" head:");
  debugSerial.print(head_);
  //debugSerial.print("@");
  //debugSerial.print(&head_, DEC);
  debugSerial.print(" available:");
  debugSerial.println(Available());
}

void circularBuffer::Reset() {
  head_ = 0;
  tail_ = 0;
  //debugSerial.println("Buffer Reset!!!");
}
