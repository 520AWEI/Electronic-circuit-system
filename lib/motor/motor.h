#ifndef MOTOR_H
#define MOTOR_H
#include "constDef.h"
class motor {
private:
    // int portA, portB;
public:
  int portA, portB;
    motor(){portA=12;portB=11;};
    motor(int _A, int _B);
    void spin(double percent, dir dir);
    void spin_2(double percent);
};

#endif // MOTOR_H