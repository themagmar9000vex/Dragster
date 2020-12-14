#include "robot_config.h"
#include "drive_train.h"

int display(){
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(mono20);
  while(1==1){
    Brain.Screen.printAt(20,5,"LMotor1 - RPM/Temp: %f ",DT.L1RPMTemp());
    Brain.Screen.printAt(20,25,"LMotor2 - RPM/Temp: %f ",DT.L2RPMTemp());
    Brain.Screen.printAt(20,45,"LMotor3 - RPM/Temp: %f ",DT.L3RPMTemp());
    Brain.Screen.printAt(20,65,"LMotor4 - RPM/Temp: %f ",DT.L4RPMTemp()); 
    Brain.Screen.printAt(20,85,"RMotor1 - RPM/Temp: %f ",DT.R1RPMTemp());
    Brain.Screen.printAt(20,105,"RMotor2 - RPM/Temp: %f ",DT.R2RPMTemp());
    Brain.Screen.printAt(20,125,"RMotor3 - RPM/Temp: %f ",DT.R3RPMTemp());
    Brain.Screen.printAt(20,145,"RMotor4 - RPM/Temp: %f ",DT.R4RPMTemp());
    vex::task::sleep(25);                     
  }
  return(0);
}

int teleOP(){
  while(1==1){
    DT.MoveDriveTrain(ControllerA.Axis3.value(), ControllerA.Axis2.value());

    if(ControllerA.ButtonA.pressing()){
      DT.StopHold();
    }

    if(ControllerA.ButtonB.pressing()){
      DT.StopCoast();
    }
    vex::task::sleep(25);      
  } 
  return(0);
}

int main() {
  vex::task brain(display);
  brain.setPriority(10);

  DT.setSpeed(100);
  DT.ForwardMeters(30);

  DT.ForwardDecayingSpeed();
}
