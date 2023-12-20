#include "car.h"
#include <Arduino.h>
car::car(int a1,int a2,int b1,int b2){
    _PortMotorA1=a1;
    _PortMotorA2=a2;
    _PortMotorB1=b1;
    _PortMotorB2=b2;
    leftMotor=motor(_PortMotorA1,_PortMotorA2);
    rightMotor=motor( _PortMotorB1,_PortMotorB2);
}
///@todo 测定t,v
void car::rotate(double v,int direction,int t){
    v=v*255/100;
    if(direction==0){
    this->leftMotor.spin(0,forward);
    this->rightMotor.spin(255-v,reverse);
    delay(t);
    this->leftMotor.spin(0,forward);
    this->rightMotor.spin(0,forward);
    }
    else{
        this->leftMotor.spin(0,forward);
        this->rightMotor.spin(v,forward);
        delay(t);
        this->leftMotor.spin(0,forward);
        this->rightMotor.spin(0,forward);
    }
}

void car::adjust(){
    double avg=0;
    int lst[testTimes];
    double max=0,mins=1023;
    for(int i=0;i<testTimes;i++){
        max=0;
        mins=1023;
        for(int j=0;j<stepTimes;j++){
            double tmp=analogRead(A6);
            // Serial.println(tmp);
            delayMicroseconds(13);
            if(tmp>max){
                max=tmp;
            }
            else if(tmp<mins){
                mins=tmp;
            }
            lst[i]=max-mins;
        }
    }
    for(int k=0;k<testTimes;k++){
            avg+=lst[k];
        }
    avg/=testTimes;
    this->fengValue=avg;
}

void car::findDir(){
    this->adjust();
    double lastValue=this->fengValue;
    rotate(100,0,rotatetime/20);//转18°
    this->adjust();
    if(lastValue<this->fengValue){
        lastValue=this->fengValue;
    }
    else if(lastValue==this->fengValue){
        lastValue=this->fengValue;
        rotate(100,1,rotatetime/40);
    }
    else if(lastValue>this->fengValue){
        this->stop();
        rotate(100,0,rotatetime/2);//转180
        this->adjust();
        lastValue=this->fengValue;
    }
    for(int i=0;i<findTimes;i++){
        rotate(100,0,rotatetime/20);
        this->adjust();
        if(lastValue<this->fengValue){
            lastValue=this->fengValue;
            continue;
        }
        if(lastValue>=this->fengValue){
            this->stop();
            rotate(100,1,rotatetime/40);
            return;
        }
    }
}

void car::move(double v,dir direction,int t){
    this->leftMotor.spin(v,direction);
    this->rightMotor.spin(v,direction);
    delay(t);
    this->leftMotor.spin(0,direction);
    this->rightMotor.spin(0,direction);
}

void car::test(){
    // analogWrite(12,255);
    // digitalWrite(5,HIGH);
    this->leftMotor.spin(100,forward);//电机电压小于127V时不转动
    this->rightMotor.spin(50,reverse);
}

void car::stop(){
     this->leftMotor.spin(0,forward);
    this->rightMotor.spin(0,forward);
}