#include <Arduino.h>
// #include "constDef.h"
#include "motor.h"

motor m1(9, 10);
motor m2(12, 5);
void setup() {
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(12, OUTPUT);
    // digitalWrite(10,HIGH);
    // analogWrite(9,0);
    analogWrite(12,255);
    digitalWrite(5,HIGH);
}

void loop() {
    // m1.spin(100, reverse);
    // m2.spin(100, forward);
    delay(10);
}