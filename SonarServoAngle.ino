#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN  12
#define ECHO_PIN     11

const byte MAX_DISTANCE=30;
const byte INDENT=2;
const double SERVO_DISTANCE=7;

byte  min_angle,
      max_angle;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
void setup() {
  Serial.begin(9600);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
   calcAngles();
   myservo.write(90);
   delay(1050);
}
 
void loop() {
  delay(300);
  int sonarval = sonar.ping_cm();
  int val = map(sonarval, INDENT, MAX_DISTANCE, min_angle, max_angle);
  
  Serial.print("Sonar");Serial.print("\t");
  Serial.print(INDENT);Serial.print("\t");
  Serial.print(sonarval);Serial.print("\t");
  Serial.print(MAX_DISTANCE); Serial.print("\t");

  Serial.print("Angle");Serial.print("\t");
  Serial.print(min_angle);Serial.print("\t");
  Serial.print(val);Serial.print("\t");
  Serial.println(max_angle);
  if(sonarval > 0){    
    myservo.write(val);
  }
}
void calcAngles(){
    double rad = atan((MAX_DISTANCE-INDENT)/2.0/SERVO_DISTANCE);
    byte deg = round(rad * 57296 / 1000);
    //Serial.print(deg);
    min_angle = 90-deg;
    max_angle = 90+deg;
}
