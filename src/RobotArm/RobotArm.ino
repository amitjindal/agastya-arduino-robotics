/*
 * Robot Arm Source Code
 * 
 * (c) Copyrights Agastya Jindal, 2017. All rights reserved.
 */

// Define Pin Constants
//int MOTOR_1_N = 2;  // Motor 1 Negative with UNO Pin 2
//int MOTOR_1_P = 3;  // Motor 1 Positive with UNO Pin 3
int MOTOR_2_N = 4;  // Motor 2 Negative with UNO Pin 4
int MOTOR_2_P = 5;  // Motor 2 Positive with UNO Pin 5

int OPEN_SW = 2;  // Infra Red Sensor 1
int CLOSE_SW = 3;  // Infra Red Sensor 2

void setup() {
  // Setup of Pin Config
  // Motors as output
  
  pinMode(MOTOR_2_N, OUTPUT);
  pinMode(MOTOR_2_P, OUTPUT);
  // Read from sensors
  pinMode(OPEN_SW, INPUT);
  pinMode(CLOSE_SW, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(MOTOR_2_N, LOW);
  //digitalWrite(MOTOR_2_P, LOW);
  
  int openSwValue = digitalRead(OPEN_SW);
  int closeSwValue = digitalRead(CLOSE_SW);

  if (openSwValue == LOW) {
    digitalWrite(MOTOR_2_N, LOW);
    digitalWrite(MOTOR_2_P, HIGH);
  } else if (closeSwValue == LOW) {
    digitalWrite(MOTOR_2_N, HIGH);
    digitalWrite(MOTOR_2_P, LOW);
  } else {
    digitalWrite(MOTOR_2_N, LOW);
    digitalWrite(MOTOR_2_P, LOW);
  }
}

