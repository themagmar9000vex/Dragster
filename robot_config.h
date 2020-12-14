#include "vex.h"
#include "vex_imu.h"
using namespace vex;
vex::brain       Brain;

vex::motor LMotor1(vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor LMotor2(vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor LMotor3(vex::PORT12, vex::gearSetting::ratio18_1, true);
vex::motor LMotor4(vex::PORT13, vex::gearSetting::ratio18_1, false);
vex::motor RMotor1(vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor RMotor2(vex::PORT15, vex::gearSetting::ratio18_1, true);
vex::motor RMotor3(vex::PORT16, vex::gearSetting::ratio18_1, false);
vex::motor RMotor4(vex::PORT17, vex::gearSetting::ratio18_1, true);

vex::controller ControllerA = vex::controller();
