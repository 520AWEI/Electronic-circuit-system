#include "drive.h"
#include <Arduino.h>
#include <math.h>
#include "portDefnew.h"
void DriveControl::stop() {
    for (int i = 0; i < 4; i++) {
        motorSpeed[i] = 0;
        motorLowSpeedPID[i].reset();
        motorHighSpeedPID[i].reset();
    }
    this->setSpeed();
}

void DriveControl::setSpeed(){
    analogWrite(port_motor_L_F,motorSpeed[0]);
    analogWrite(port_motor_L_B,motorSpeed[1]);
    analogWrite(port_motor_R_F,motorSpeed[2]);
    analogWrite(port_motor_R_B,motorSpeed[3]);
}
void DriveControl ::moveForwordByTime(double t,double V){
    double timenow=0;
    double v_1, v_2;
    v_1=V;
    v_2=V;
    ///@todo
    //归一化
    if(V>=0){
    motorSpeed[0] = v_1;
    motorSpeed[1] = 0;
    motorSpeed[2] =v_2;
    motorSpeed[3] =0;
    }
    else{
    motorSpeed[0] = 0;
    motorSpeed[1] = -v_1;
    motorSpeed[2] =0;
    motorSpeed[3] =-v_2;
    }
    while(timenow<=t){
        delay(10);
        timenow+=10/1000;
    }
    this->stop();
}