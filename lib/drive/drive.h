/**
 * @Pr0ximah
 * @date 23.06.25
 * @file drive.h
 * @brief 实现DriveControl类，可以设定坐标，让小车移动到对应的位置
 * @note 坐标系定义如下:
 * /\ y
 * ||
 * ||
 * ||
 * ||        x
 * [] =======>
 * 角度定义为车头方向与y轴正向的偏移角度，逆时针为正向
 */

#ifndef DRIVE_H
#define DRIVE_H

#include "PID.h"
#include "constDef.h"
#include "point.h"
#include "portDefnew.h"

// 封装的移动控制，可以设置目标点，小车移动到对应位置
class DriveControl {
public:
    Point posCur;         // 世界坐标系
    float motorSpeed[4];  // 电机转速(percent)---0-LF/1-LB/2-RF/3-RB 
    PID motorLowSpeedPID[4];   // 电机低转速PID
    PID motorHighSpeedPID[4];  // 电机高转速PID

public:
    DriveControl();

    // 最顶层的移动控制，依赖定位实现
    // ------------------------------
    // 移动到目标点
    void gotoPoint(Point p);
    void gotoPoint(float x, float y);
    // 停车
    void stop();
    // ------------------------------

    // 控制小车平移和旋转，封装的移动控制
    // -------------------------------------
    // speed: 速度, pTar: 目标点
    void move(float speed, Vector vec);
    void move(float speed, double x, double y);
    // speed: 速度（>0逆时针转，<0顺时针转）, angleTar: 目标角度(deg)
    void rotate(float speed, float angleTar);
    // -------------------------------------

    // 测试函数
    // -------------------------------------
    // 电机PID测试函数
    void motorPIDTest(int i);

    // 电机电压percent转速映射自动测试函数
    void motorVoltVelTest(int i);
    void moveForwordByTime(double t,double V);
    // -------------------------------------

private:
    // pos初始化，建立新的世界坐标系
    void posInit();

    // 更新车体各信息状态
    void statusUpdate();

    // 电机旋转方向
    enum motorDir { FWD, BCK };

    // speed: 前进速度(百分制);  angleTar: 目标方向(弧度制)
    void driveByAngle(float speed, float angleTar);

    // speed: 旋转速度(百分制[-100, 100])
    void rotateByDir(float speed);

    // 更新位置数据
    void posUpdate();

    // 电机转速PID控制线程函数
    void motorSpeedUpdate();

    // 电机转速到电压percent映射函数
    double motorVelToVoltPercent(double vel);
    void setSpeed();
};

#endif  // DRIVE_H