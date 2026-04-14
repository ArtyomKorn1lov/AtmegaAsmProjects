#include "blink_led.h";

const int WORK_PIN = 12;

void setup() {
  pinMode(WORK_PIN, OUTPUT);
}

void loop() {
  blinkLed(WORK_PIN);
}