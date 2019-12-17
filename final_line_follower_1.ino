//ARDUINO LINE FOLLOWER CAR Based On Arduino Motor Driver Shield
//You have to install the AFMotor library before uploading the sketch
//First download the AFMotor Zip file then open Arduino IDE 
//go to sketch >> Include library >> ADD .Zip file >> Select the downloaded AFMotor Zip File >> open 
// Created by DIY Builder
// You Can modify the sketch according to your need.

const int trigPin = A5;
const int echoPin = A4;
float duration, distance;

#include<AFMotor.h> //Include Adafruit Motor Driver Shield Library
//create motor obejects
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

#define LEFT_SENSOR A0 // connect the Left sensor with analog pin A0
#define RIGHT_SENSOR A1 // connect the Right sensor with analog pin A1

void setup() {

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

Serial.begin(9600);
  
pinMode(RIGHT_SENSOR, INPUT); // initialize Right sensor as an inut
pinMode(LEFT_SENSOR, INPUT); // initialize Left sensor as as input

}

void loop() { 

 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);

if(distance>12.00)
{
 
  
if(analogRead(RIGHT_SENSOR)<=35 && analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the directionc
{
  motor1.run(FORWARD); // run motor1 clockwise
  motor1.setSpeed(120); // set motor1 speed 50 percent
  motor2.run(FORWARD); // run motor2 clockwise
  motor2.setSpeed(120); // set motor2 speed 50 percent
  motor3.run(FORWARD); // run motor3 clockwise
  motor3.setSpeed(120); // set motor3 speed 50 percent
  motor4.run(FORWARD); // run motor4 clockwise
  motor4.setSpeed(120); // set motor4 speed 50 percent
}
 else if(!analogRead(RIGHT_SENSOR)<=35 && analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the direction
 {
  motor1.run(FORWARD); // run motor1 clockwise
  motor1.setSpeed(255); // set motor1 speed 100 percent
  motor2.run(FORWARD); // run motor2 clockwise
  motor2.setSpeed(255); // set motor2 speed 100 percent
  motor3.run(BACKWARD); // run motor3 anti-clockwise
  motor3.setSpeed(255); // set motor3 speed 100 percent
  motor4.run(BACKWARD); // run motor4 anti-clockwise
  motor4.setSpeed(255); // set motor4 speed 100 percent
  
}
 else if(analogRead(RIGHT_SENSOR)<=35 && !analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the direction
 {
  motor1.run(BACKWARD); // run motor1 anti-clockwise
  motor1.setSpeed(255); // set motor1 speed 100 percent
  motor2.run(BACKWARD); // run motor2 anti-clockwise
  motor2.setSpeed(255); // set motor2 speed 100 percent
  motor3.run(FORWARD);  // run motor3 clockwise
  motor3.setSpeed(255); // set motor3 speed 100 percent
  motor4.run(FORWARD);  // run motor4 clockwise
  motor4.setSpeed(255); // set motor4 speed 100 percent
}
else if(!analogRead(RIGHT_SENSOR)<=35 && !analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the direction
{
  //stop all the motors
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 }
}
else{
   //stop all the motors
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 }
}
