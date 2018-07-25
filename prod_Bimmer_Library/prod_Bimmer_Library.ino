#include "ibus.h"
#include "bm64.h"
#include "circularBuffer.h"
#include "ibus_commands.h"
#include "bt_commands.h"
//#include "data_store.h"


#define debugSerial Serial
#define btSerial    Serial1
#define ibusSerial  Serial2
#define testSerial  Serial3

const byte P1_5 = 11;
const byte P3_6 = 6;
const byte P2_0Pin = 7;
const byte EANPin = 5;
const byte btResetPin = 10;
const byte buttonPin = 9;
const byte MFBPin = 8;
const byte ledPin = 13;
volatile byte state = HIGH;

// DIL Switches
const byte DIL1 = 41;
const byte DIL2 = 39;
const byte DIL3 = 37;
const byte DIL4 = 35;
const byte DIL5 = 33;
const byte DIL6 = 31;
const byte DIL7 = 29;
const byte DIL8 = 27;

ibus Ibus;
bm64 BM64;

//########################################################################

void setup() {
  
  debugSerial.begin(115200);
  btSerial.begin(115200);
  ibusSerial.begin(9600, SERIAL_8E1);
  
  pinMode(btResetPin, OUTPUT);
  pinMode(P1_5, OUTPUT);
  pinMode(P3_6, OUTPUT);
  pinMode(MFBPin, OUTPUT);
  pinMode(P2_0Pin, OUTPUT);
  pinMode(EANPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(btResetPin, HIGH);
  digitalWrite(MFBPin, HIGH);
  digitalWrite(P2_0Pin, HIGH);
  digitalWrite(EANPin, LOW);
  digitalWrite(P1_5, 1);
  digitalWrite(P3_6, 0);
  digitalWrite(ledPin, 0);

  pinMode(DIL1, INPUT_PULLUP);
  pinMode(DIL2, INPUT_PULLUP);
  pinMode(DIL3, INPUT_PULLUP);
  pinMode(DIL4, INPUT_PULLUP);
  pinMode(DIL5, INPUT_PULLUP);
  pinMode(DIL6, INPUT_PULLUP);
  pinMode(DIL7, INPUT_PULLUP);
  pinMode(DIL8, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  
  delay(100);

  if (digitalRead(DIL1) == 0) {
    digitalWrite(btResetPin, 0);
    delay(5);
    digitalWrite(EANPin, digitalRead(DIL2));
    digitalWrite(P2_0Pin, digitalRead(DIL3));
    digitalWrite(MFBPin, digitalRead(DIL4));
    delay(500);
    digitalWrite(btResetPin, 1);
    //debugSerial.println("Serial Passthrough Enabled");
    
    while (digitalRead(DIL1) == 0) {
      if (btSerial.available()) {
        debugSerial.write(btSerial.read());
      }
      if (debugSerial.available()) {
        btSerial.write(debugSerial.read());
      }
    }
    digitalWrite(btResetPin, 0);
    digitalWrite(MFBPin, HIGH);
    digitalWrite(P2_0Pin, HIGH);
    digitalWrite(EANPin, HIGH);
    delay(500);
    digitalWrite(btResetPin, 1);
  }
  
  /*if (digitalRead(DIL8) == 0) {
    //debugSerial.println("IBus Serial Passthrough Enabled");
    while (digitalRead(DIL8) == 0) {
      if (ibusSerial.available()) {
        debugSerial.write(ibusSerial.read());
      }
      if (debugSerial.available()) {
        ibusSerial.write(debugSerial.read());
      }
    }
  }*/
  
  delay(500);
  btSerial.write(POWER_BUTTON_PRESS, 7);
  delay(250);
  btSerial.write(POWER_BUTTON_RELEASE, 7);
  
  debugSerial.println(F("prods BMW Interface Started."));
}

//########################################################################

void loop() {
  if(Ibus.checkIbus()) {
    Ibus.searchIbus();
  }
  BM64.checkbtSerial();
}