// // 主程序
// #include <Arduino.h>

// Car car;

// void setup() { Serial.begin(9600); }

// void loop() {}

/**
 * @Pr0ximah
 * @date 23.09.04
 * @brief debug模式测试代码
 */
#include <Arduino.h>

#include "car.h"

bool firstTime_flag = true;
bool start = false;

void setup() { Serial.begin(9600); }

void loop() {
    // delay(1000);
    // if (Serial.readString() == "START") {
    //     start = true;
    // }

    // if (start) {
    //     if (firstTime_flag) {
    //         Car car;
    //         car.autoRun();
    //         firstTime_flag = false;
    //     }
    // }

    Car car;
    car.autoRun();

}

//测试代码
// int motorA1pin = 9; //左轮电机 Motor1A
// int motorB1pin = 10; //左轮电机 Motor1B
// int motorA2pin = 5; //右轮电机 Motor2A
// int motorB2pin = 12; //右轮电机 Motor2B
// int i;


// void setup() {
//   //Declaring Motor pin as output
//   pinMode(motorA1pin, OUTPUT);
//   pinMode(motorB1pin, OUTPUT);
//   pinMode(motorA2pin, OUTPUT);
//   pinMode(motorB2pin, OUTPUT);
// }



// void loop() {
//   //小车加速前进,持续 12.8s
//   for(i=0; i<=255; i++) {
//     digitalWrite(motorB1pin,LOW);
//     digitalWrite(motorB2pin,LOW);
//     analogWrite(motorA1pin, i);
//     analogWrite(motorA2pin, i);
//     delay(50);
//   }

//   //小车加速后退,持续 12.8s
//   for(i=0; i<=255; i++) {
//     digitalWrite(motorB1pin,HIGH);
//     digitalWrite(motorB2pin,HIGH);
//     analogWrite(motorA1pin, 255-i);
//     analogWrite(motorA2pin, 255-i);
//     delay(50);
//   }

//   //小车加速右转,持续 12.8s
//   for(i=0; i<=255; i++) {
//     digitalWrite(motorB1pin,LOW);
//     digitalWrite(motorB2pin,HIGH);
//     analogWrite(motorA1pin, i);
//     analogWrite(motorA2pin, 255-i);
//     delay(50);
//   }

//   //小车加速左转,持续 12.8s
//   for(i=0; i<=255; i++) {
//     digitalWrite(motorB1pin,HIGH);
//     digitalWrite(motorB2pin,LOW);
//     analogWrite(motorA1pin, 255-i);
//     analogWrite(motorA2pin, i);
//     delay(50);
//   }
  
//   //小车停止，持续 1s
//   digitalWrite(motorB1pin,LOW);
//   digitalWrite(motorB2pin,LOW);
//   analogWrite(motorA1pin, 0);
//   analogWrite(motorA2pin, 0);
//   delay(1000);
// }
// //}