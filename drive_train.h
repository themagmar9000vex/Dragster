class DriveTrain {
  private:
  //Motors for the drivetrain
    vex::motor L1 = LMotor1;
    vex::motor L2 = LMotor2;
    vex::motor L3 = LMotor3;
    vex::motor L4 = LMotor4;
    vex::motor R1 = RMotor1;
    vex::motor R2 = RMotor2;
    vex::motor R3 = RMotor3;
    vex::motor R4 = RMotor4;    

  //variables for the drive trian
    double DTSpeed;
    double diameterofWheel;
    double degreePerInch;
    double gearRatio;
    double circumferenceofWheel;

  public:

  //Function To Set The Speed
    void setSpeed(double speed){
      DTSpeed = speed;
    }

  //RPM and temperature values for all of the motors
    double L1RPMTemp(){
      return L1.velocity(vex::velocityUnits::rpm), L1.temperature(vex::percentUnits::pct);
    }
    double L2RPMTemp(){
      return L2.velocity(vex::velocityUnits::rpm), L2.temperature(vex::percentUnits::pct);
    }
    double L3RPMTemp(){
      return L3.velocity(vex::velocityUnits::rpm), L4.temperature(vex::percentUnits::pct);
    }

    double L4RPMTemp(){
      return L4.velocity(vex::velocityUnits::rpm), L4.temperature(vex::percentUnits::pct);
    }   

    double R1RPMTemp(){
      return R1.velocity(vex::velocityUnits::rpm), R1.temperature(vex::percentUnits::pct);
    }
    double R2RPMTemp(){
      return R2.velocity(vex::velocityUnits::rpm), R2.temperature(vex::percentUnits::pct);
    }
    double R3RPMTemp(){
      return R3.velocity(vex::velocityUnits::rpm), R4.temperature(vex::percentUnits::pct);
    }

    double R4RPMTemp(){
      return R4.velocity(vex::velocityUnits::rpm), R4.temperature(vex::percentUnits::pct);
    }     


//Functions to set the robot to spin forwards and backwards
    void Forwards(){
      L1.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      L2.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      L3.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      L4.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      R1.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      R2.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      R3.spin(vex::directionType::fwd,DTSpeed,vex::pct);
      R4.spin(vex::directionType::fwd,DTSpeed,vex::pct);             
    }

    void Backwards(){
      L1.spin(vex::directionType::rev,DTSpeed,vex::pct);
      L2.spin(vex::directionType::rev,DTSpeed,vex::pct);
      L3.spin(vex::directionType::rev,DTSpeed,vex::pct);
      L4.spin(vex::directionType::rev,DTSpeed,vex::pct);
      R1.spin(vex::directionType::rev,DTSpeed,vex::pct);
      R2.spin(vex::directionType::rev,DTSpeed,vex::pct);
      R3.spin(vex::directionType::rev,DTSpeed,vex::pct);
      R4.spin(vex::directionType::rev,DTSpeed,vex::pct);       
    }

    void MoveDriveTrain(double speedLeft, double speedRight){
      L1.spin(vex::directionType::fwd,speedLeft,vex::pct);
      L2.spin(vex::directionType::fwd,speedLeft,vex::pct);
      L3.spin(vex::directionType::fwd,speedLeft,vex::pct);
      L4.spin(vex::directionType::fwd,speedLeft,vex::pct);  
      R1.spin(vex::directionType::fwd,speedRight,vex::pct);
      R2.spin(vex::directionType::fwd,speedRight,vex::pct);
      R3.spin(vex::directionType::fwd,speedRight,vex::pct);
      R4.spin(vex::directionType::fwd,speedRight,vex::pct);             
    }

//Functions to stop the robot with either coast or hold
    void StopHold(){
      L1.stop(vex::brakeType::hold);
      L2.stop(vex::brakeType::hold);
      L3.stop(vex::brakeType::hold);
      L4.stop(vex::brakeType::hold);
      R1.stop(vex::brakeType::hold);
      R2.stop(vex::brakeType::hold);
      R3.stop(vex::brakeType::hold);
      R4.stop(vex::brakeType::hold);
    }

    void StopCoast(){
      L1.stop(vex::brakeType::coast);
      L2.stop(vex::brakeType::coast);
      L3.stop(vex::brakeType::coast);
      L4.stop(vex::brakeType::coast);
      R1.stop(vex::brakeType::coast);
      R2.stop(vex::brakeType::coast);
      R3.stop(vex::brakeType::coast);
      R4.stop(vex::brakeType::coast);
    }


//Function to reset the rotation
    void ResetPosition(){
      L1.resetRotation();
      L2.resetRotation();
      L3.resetRotation();
      L4.resetRotation();
      R1.resetRotation();
      R2.resetRotation();
      R3.resetRotation();
      R4.resetRotation();                            
    }

//Function that moves the robot forwards a certain nsumber of meters
    void ForwardMeters(double meters){
      double inches = meters * 39.3701;
      double rotations = (inches / circumferenceofWheel) * 360;
      ResetPosition();
      double rotTraveled = abs(L1.rotation(vex::rotationUnits::deg));

      while(rotTraveled < rotations){
        Forwards();
        rotTraveled = abs(L1.rotation(vex::rotationUnits::deg));
      }
      StopCoast();
    }    

//Function that goes forward decreases the speed every second
    void ForwardDecayingSpeed(){


      for(int x=0;x<10;x++){
        int Decay = 10 * x;
        setSpeed(100 - Decay);
        Forwards();
        wait(1000, vex::msec);
      }

      StopCoast();
    }

//Constructor & Deconstructor
  DriveTrain(){
    diameterofWheel = 4;
    DTSpeed = 100;
    gearRatio = 25/1;
    circumferenceofWheel = diameterofWheel * 3.14159265359;
  } 
  ~DriveTrain() {}
} DT;