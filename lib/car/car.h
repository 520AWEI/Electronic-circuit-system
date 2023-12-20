#ifndef CAR_H
#define CAR_H
#include "constDef.h"
#include "motor.h"

class car {
private:
    int _PortMotorA1;
    int _PortMotorB1;
    int _PortMotorA2;
    int _PortMotorB2;
    motor leftMotor,rightMotor;
public:
    double fengValue=0;
    car(int a1,int a2,int b1,int b2);
    void rotate(double v,int direction,int t);//direction==0 顺时针 direction==1 逆时针
    void adjust();
    void findDir();
    void move(double v,dir direction,int t);
    void test();
    void stop();
};

#endif // CAR_H