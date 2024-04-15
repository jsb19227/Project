#include <Arduino.h>
#include <Stepper.h>

#include "pinout.h"

int stepsPerRevolution = 2038;
float current_angle = 0.0, target_angle = 0.0, error = 0.0, Kp = 1.0, Kd = 0.0, degree_increment = 0.75;
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void moveStepper() {
  float new_angle = Kp * (target_angle - current_angle) + Kd * (target_angle - current_angle - error);
  new_angle *= degree_increment;
  myStepper.step(new_angle * stepsPerRevolution / 360);
  current_angle += new_angle;
  error = target_angle - current_angle;
}

float compute_angle()
{
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(20);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  target_angle = 90;
  moveStepper();
  delay(1000);
  target_angle = 0;
  moveStepper();
  delay(1000);
}