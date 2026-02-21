#ifndef BLINK_LED_H;
#define BLINK_LED_H;
#include <Arduino.h>;

void blinkLed(int pin) {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

#endif