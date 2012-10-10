/*
 * nunchuck_lines sketch
 * sends data to Processing to draw line that follows nunchuck movement
 */

#include <Wire.h> // initialize wire

const int vccPin = A3;   // +v provided by pin 17
const int gndPin = A2;   // gnd provided by pin 16

const int dataLength = 6;          // number of bytes to request
static byte rawData[dataLength];   // array to store nunchuck data

enum nunchuckItems { joyX, joyY, accelX, accelY, accelZ, btnZ, btnC };

void setup() {  
  pinMode(gndPin, OUTPUT); // set power pins to the correct state
  pinMode(vccPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  digitalWrite(vccPin, HIGH);
  delay(100);  // wait for things to stabilize        

  Serial.begin(9600);
  nunchuckInit();
}

void loop(){
  nunchuckRead();
      Serial.print(getValue(joyX));
      Serial.print(", ");
      Serial.print(getValue(joyY));
      Serial.print(", ");
      Serial.print(getValue(accelX));
      Serial.print(", ");
      Serial.print(getValue(accelY));
      Serial.print(", ");
      Serial.print(getValue(accelZ));
      Serial.print(", ");
      Serial.print(getValue(btnZ));
      Serial.print(", ");
      Serial.print(getValue(btnC));
      Serial.println();

  delay(100); // the time in milliseconds between redraws
}


