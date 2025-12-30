
#include "Arduino.h"
#include <SoftwareSerial.h>

const int trigPin = 3;
const int echoPin = 2;
const int rxBlue = 4;
const int txBlue = 5;

SoftwareSerial BTSerial(rxBlue, txBlue);

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  BTSerial.begin(9600);
}

void loop() {

  long duration, inches, cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  BTSerial.print(inches);
  BTSerial.print("/");
  BTSerial.print(cm/2);
  BTSerial.print("/");
  BTSerial.print(cm);
  BTSerial.println("/");
  Serial.print(inches);
  Serial.print("/");
  Serial.print(cm/2);
  Serial.print("/");
  Serial.print(cm);
  Serial.println("/");
  delay(1000);
}

long microsecondsToInches(long microseconds) {

  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {

  return microseconds / 29 / 2;
}
