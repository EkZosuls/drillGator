//#define MOTOR_PLUS 3
//#define MOTOR_MINUS 9
#define CURRENT_SENSOR 0
#define OFF_THRESHOLD 75
#define MIN_FLOW 0
#define MAX_FLOW 150

#include <AccelStepper.h>
#define STEPS 100

AccelStepper stepper(AccelStepper::FULL4WIRE, 8, 9, 10, 11);

void setup() {
    stepper.setMaxSpeed(1000);
    stepper.setSpeed(50);  
    Serial.begin(9600);
    Serial.println("Drillgator 1.0 Zosuls 2023");

}

void loop() {
  int enableFlag = 1;
  int currentSensorCounts = 0;
  int motorDrive = 0;
  int motorDriveDuty = 0;
  unsigned long dwellTime = 0;
  currentSensorCounts = analogRead(CURRENT_SENSOR);
//Serial.println(currentSensorCounts);
  if((currentSensorCounts > OFF_THRESHOLD) && (currentSensorCounts < 1024)){
    if(enableFlag == 0){
      stepper.enableOutputs();
      enableFlag = 1;
      }
    motorDriveDuty = map(currentSensorCounts, OFF_THRESHOLD, 1023, MIN_FLOW, MAX_FLOW);
    //motorDriveDuty = motorDriveDuty/2;
    dwellTime = 2000000/(1+motorDriveDuty);
    stepper.setSpeed(motorDriveDuty);
    //stepper.enableOutputs();
    delayMicroseconds(10);
    stepper.runSpeed();
    //delayMicroseconds(dwellTime);
     //stepper.disableOutputs(); 
    
   
    //Serial.println(motorDriveDuty);
    }

  else{
    stepper.disableOutputs(); 
    enableFlag = 0;
    }
//delayMicroseconds(10000);
}
