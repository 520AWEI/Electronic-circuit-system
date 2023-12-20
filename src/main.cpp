#include <Arduino.h>
#include "car.h"
bool flag=1;
void setup() {
    // pinMode(10, OUTPUT);
    // pinMode(9, OUTPUT);
    // pinMode(11, OUTPUT);
    // pinMode(12, OUTPUT);
    Serial.begin(9600);

    // analogWrite(12,255);
    // digitalWrite(5,LOW);
}
car myCar(12,11,9,10);
void loop() {
    if(flag){
        //test
        // myCar.test();
        // delay(10000);
        // myCar.stop();
        // flag=0;

        // myCar.findDir();
        // myCar.move(50,forward,1000);
        // flag=0;

        // test for rotate
        // myCar.rotate(100,0,1126);//一圈
        // delay(1000);
        // // myCar.rotate(100,1,1126);
        // for(int i=0;i<20;i++){
        //     myCar.rotate(100,0,875/20);
        //     delay(100);
        // }
        // delay(1000);
        // myCar.rotate(100,1,1126/2);
        // flag=0;

        // test for adjust
        for(int i=0;i<=100;i++){
            myCar.adjust();
            Serial.println(myCar.fengValue);
            delay(1000);
        }
        flag=0;
    }
    delay(10);
}