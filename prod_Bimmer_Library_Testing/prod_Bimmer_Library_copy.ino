#include "ibus.h"
#include "bm64.h"


#define debugSerial Serial
#define btSerial    Serial1
#define ibusSerial  Serial2
#define testSerial  Serial3

const byte P1_5 = 11;
const byte P3_6 = 6;
const byte P2_0Pin = 7;
const byte EANPin = 5;
const byte btResetPin = 10;
const byte MFBPin = 8;
const byte ledPin = 13;

const byte POWER_BUTTON_PRESS [7] = { 0xAA , 0x00 , 0x03 , 0x02 , 0x00 , 0x51 , 0xAA };

const byte POWER_BUTTON_RELEASE [7] = { 0xAA , 0x00 , 0x03 , 0x02 , 0x00 , 0x52 , 0xA9 };

bm64 BM64;
ibus Ibus;


//########################################################################

void setup() {

  debugSerial.begin(9600);
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

  delay(100);

  btSerial.write(POWER_BUTTON_PRESS, 7);
  delay(250);
  btSerial.write(POWER_BUTTON_RELEASE, 7);

  debugSerial.println("prods BMW Interface Started.");
  delay(1000);
  while (ibusSerial.available()) {
    byte i = ibusSerial.read();
  }

}

//########################################################################

void loop() {
  Ibus.checkIbus();
  BM64.checkbtSerial();
}
