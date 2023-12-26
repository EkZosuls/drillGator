#define MOTOR_PLUS 3
#define MOTOR_MINUS 9
#define CURRENT_SENSOR 0
#define OFF_THRESHOLD 75
#define MIN_FLOW 100
#define MAX_FLOW 200

void setup() {
  // put your setup code here, to run once:
pinMode(MOTOR_PLUS, OUTPUT);
pinMode(MOTOR_MINUS, OUTPUT);
digitalWrite(MOTOR_PLUS, LOW);
digitalWrite(MOTOR_MINUS, LOW);
Serial.begin(9600);

}

void loop() {
int currentSensorCounts = 0;
int motorDrive = 0;
int motorDriveDuty = 0;
currentSensorCounts = analogRead(CURRENT_SENSOR);
Serial.println(currentSensorCounts);
  if((currentSensorCounts > OFF_THRESHOLD) && (currentSensorCounts < 1024)){
    motorDriveDuty = map(currentSensorCounts, OFF_THRESHOLD, 1023, MIN_FLOW, MAX_FLOW);
    analogWrite( MOTOR_PLUS, motorDriveDuty);
    Serial.println(motorDriveDuty);
    }

  else{
    digitalWrite(MOTOR_PLUS, LOW);
    digitalWrite(MOTOR_MINUS, LOW);
    }
delayMicroseconds(10000);
}
