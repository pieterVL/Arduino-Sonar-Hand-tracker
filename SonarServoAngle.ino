#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 20
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
void setup() {
  Serial.begin(9600);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
 
void loop() {
  delay(200);
  /*Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");*/
  int sonarval = sonar.ping_cm();
  int val = map(sonarval, 1,16,50,130);
  Serial.print(sonarval);
  Serial.print("   ");
  Serial.println(val);
  if(sonarval > 0){
    //int val = map(sonarval, 1,16,50,130);
    myservo.write(val);//50-130
  }
}
