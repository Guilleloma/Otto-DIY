#include <Servo.h>
#include <math.h>
Servo rightServo;
Servo leftServo;


long ultrasound_distance_1() {
   long duration, distance;
   digitalWrite(8,LOW);
   delayMicroseconds(2);
   digitalWrite(8, HIGH);
   delayMicroseconds(10);
   digitalWrite(8, LOW);
   duration = pulseIn(9, HIGH);
   distance = duration/58;
   return distance;
}

int rightSpeed = 0;
int leftSpeed = 0;
void motorControl(int rightSpeed, int leftSpeed, int stepDelay) {
rightServo.write(90 + rightSpeed);  leftServo.write(90 - leftSpeed);
delay(stepDelay*1000);}

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  rightServo.write(90);
leftServo.write(90);
delay(1000);
leftServo.attach(2);
rightServo.attach(3);
  pinMode( 13 , OUTPUT);

}

void loop() {
    if (ultrasound_distance_1() < 5) {
      tone(  13,261,125);
       delay(125);
      motorControl (-20, 20, 1 );
    }
    if (ultrasound_distance_1() >= 5) {
      tone(  13, 659 ,500);
       delay(500);
      motorControl (-20, -20, 1 );
    }

}