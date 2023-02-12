/*
Rajj YT
Video Link :-
https://youtu.be/jgrq5OuFrKo

Servo Library :-
https://github.com/arduino-libraries/Servo

L293d Sheild Library :-
https://github.com/adafruit/Adafruit-Motor-Shield-library

Circuit Link :-
https://github.com/usmanrajj/RC-Mobile-Lifter
*/
#include <Servo.h>          // Add this Servo Motor Library
#include <AFMotor.h>        // Add L293d sheild Library

AF_DCMotor motor1(1, MOTOR34_1KHZ);  // create motor object with pin 4 and 1kHz frequency
AF_DCMotor motor2(2, MOTOR34_1KHZ);  // create motor object with pin 3 and 1kHz frequency
AF_DCMotor motor3(3, MOTOR34_1KHZ);  // create motor object with pin 5 and 1kHz frequency
AF_DCMotor motor4(4, MOTOR34_1KHZ);  // create motor object with pin 6 and 1kHz frequency

Servo servo1;  // create servo object
Servo servo2;  // create servo object

char usman;
char condition;

int angle1=90;
int angle2=90;

int SPEED=100;

void rc();
void servo_motor();
void left();
void right();
void forward();
void backward();
void Stop();

void setup() { 
  Serial.begin(9600);
  servo1.attach(10);         // attach servo1 to pin 9
  servo2.attach(9);        // attach servo2 to pin 10
  servo1.write(angle1);
  servo2.write(angle2);
}
void loop() {
  if (Serial.available())
  usman = Serial.read();  // read incoming byte
  else 
  usman='D';

  if (usman=='X')
    condition='X';
  else if(usman=='x')
    condition='x';
  if(condition=='X')
    servo_motor();
  else
    rc();
  }
void rc(){
  speed();                  // Check Speed
switch (usman) {
  case 'F':
    forward();
    break;
  case 'B':
    backward();
  break;
  case 'L':
    left();
    break;
  case 'R':
    right();
  break;
  case 'S':
    Stop();
  }
}
void forward()
{
  motor1.setSpeed(SPEED); //Define maximum velocity
  motor1.run(FORWARD);  //rotate the motor clockwise
  motor2.setSpeed(SPEED); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  motor3.setSpeed(SPEED); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(SPEED); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}
void backward()
{
  motor1.setSpeed(SPEED); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(SPEED); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(SPEED); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(SPEED); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(SPEED); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(SPEED); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(SPEED); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(SPEED); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(SPEED); //Define maximum velocity
  motor1.run(FORWARD);  //rotate the motor clockwise
  motor2.setSpeed(SPEED); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  motor3.setSpeed(SPEED); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(SPEED); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void Stop()
{
  motor1.setSpeed(0);  //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0);  //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0);  //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0);  //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
void speed(){
if(usman == '0') {
SPEED = 0;
}
else if(usman == '1') {
SPEED = 23;
}
else if(usman == '2') {
SPEED = 46;
}
else if(usman == '3') {
SPEED = 69;
}
else if(usman == '4') {
SPEED = 92;
}
else if(usman == '5') {
SPEED = 115;
}
else if(usman == '6') {
SPEED = 139;
}
else if(usman == '7') {
SPEED = 162;
}
else if(usman == '8') {
SPEED = 185;
}
else if(usman == '9') {
SPEED = 208;
}
else if(usman == '10') {
SPEED = 231;
}
else if(usman == 'q') {
SPEED = 255;
}
}
void servo_motor(){
  Stop();
  switch(usman){
    case 'F':
      if (angle1<=180)
      { 
        servo1.write(++angle1);
      }
    break;
    case 'B':
      if (angle1>=0)
      { 
        servo1.write(--angle1);
      }
    break;
    case 'L':
      if (angle2<=180)
      {
        servo2.write(++angle2);
      }
    break;
    case 'R':
      if (angle2>=0)
      {
        servo2.write(--angle2);
      }
    break;
  }
}