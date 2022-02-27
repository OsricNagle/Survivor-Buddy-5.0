#include "C:\Users\osric\Documents\GitHub\Survivor-Buddy-4.0\arduino\motorMovement\VarSpeedServo.cpp"
// #include <Servo.h>

int servo = 4;
int feedback = A2;
int base_1 = 3;
int baseFeedback = A1;
int base_2 = 2;

VarSpeedServo test;
VarSpeedServo base1;
VarSpeedServo base2;
// Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);

  pinMode(servo, OUTPUT);
  pinMode(feedback, INPUT);
  pinMode(base_1, OUTPUT);
  pinMode(baseFeedback, INPUT);
  pinMode(base_2, OUTPUT);

  test.attach(servo);
  test.attachFeedback(feedback);
  // myServo.attach(regularServo);
  
  // test.calibrate();
  base1.attach(base_1);
  base1.attachFeedback(baseFeedback);
  base2.attach(base_2);
  base1.calibratePair(&base2);
}


// testing methods:
// 1. test smaller increments between 0 and 90
// 2. delay(1000) and then call wait(), see how it 
// 3. only use one call to the feedback, and do the delta w/ the previously recorded feedback val
// 4. only print out one feedback value per loop and then print out values, see if there are any 
// 5. Add a longer delay() statement to impairmentCheck()
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Move to 0");
  base1.write(60);
  base2.write(120);
  // myServo.write(0);
  base1.wait();
  // delay(500);
  // Serial.println("Position: " + String(analogRead(feedback)));
//  Serial.println("Move to 45");
//  test.write(45);
//  test.wait();
  Serial.println("Move to 90");
  base1.write(90);
  base2.write(90);
  // myServo.write(90);
  base1.wait();
  // delay(500);
  // Serial.println("Position: " + String(analogRead(feedback)));

//  test.write(180);
//  Serial.println("Position: " + String(analogRead(feedback)));
//  delay(1000);
}
