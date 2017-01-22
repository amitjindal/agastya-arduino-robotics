/*
 * Light Sensing Robot Source Code
 * 
 * (c) Copyrights Agastya Jindal, 2017. All rights reserved.
 */

// Define Pin Constants
int MOTOR_1_N = 2;  // Motor 1 Negative with UNO Pin 2
int MOTOR_1_P = 3;  // Motor 1 Positive with UNO Pin 3
int MOTOR_2_N = 4;  // Motor 2 Negative with UNO Pin 4
int MOTOR_2_P = 5;  // Motor 2 Positive with UNO Pin 5

int LHS_IR = 6;  // Infra Red Sensor 1
int RHS_IR = 7;  // Infra Red Sensor 2

void setup() {
  // Setup of Pin Config
  // Motors as output
  pinMode(MOTOR_1_N, OUTPUT);
  pinMode(MOTOR_1_P, OUTPUT);
  
  pinMode(MOTOR_2_N, OUTPUT);
  pinMode(MOTOR_2_P, OUTPUT);
  // Read from sensors
  pinMode(LHS_IR, INPUT);
  pinMode(RHS_IR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lhsValue = digitalRead(LHS_IR);
  int rhsValue = digitalRead(RHS_IR);

  if (lhsValue == HIGH) {
    digitalWrite(MOTOR_1_N, LOW);
    digitalWrite(MOTOR_1_P, HIGH);
  } else {
    digitalWrite(MOTOR_1_N, LOW);
    digitalWrite(MOTOR_1_P, LOW);    
  }

  if (rhsValue == HIGH) {
    digitalWrite(MOTOR_2_N, HIGH);
    digitalWrite(MOTOR_2_P, LOW);
  } else {
    digitalWrite(MOTOR_2_N, LOW);
    digitalWrite(MOTOR_2_P, LOW);    
  }
  delay(200); // Slow it down
}

