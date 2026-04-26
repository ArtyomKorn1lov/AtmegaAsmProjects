#include <Arduino.h>;

const int PWM_PIN = 3;
const int PWM_SERIAL_DIVIDER = 5;
const int MAX_PWM_VALUE = 255;

int pwmValue = 0;
int fadeAmount = 1;

void setupPins() {
  Serial.begin(9600);
  pinMode(PWM_PIN, OUTPUT);
}

void runPWM() {
  analogWrite(PWM_PIN, pwmValue);
  if ((pwmValue % PWM_SERIAL_DIVIDER) == 0) {
    Serial.println(pwmValue);
  }
  pwmValue = pwmValue + fadeAmount;
  if (pwmValue <= 0 || pwmValue >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}