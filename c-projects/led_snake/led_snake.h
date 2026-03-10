#ifndef LED_SNAKE_H;
#define LED_SNAKE_H;
#include <Arduino.h>;

const int LED_PINS[8] = {2, 4, 6, 7, 8, 9, 11, 13};
const int TONE_PIN = 3;
const float FREQUENCY_LIST[8] = {261.63, 277.18, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};

void setupPins() {
  for (int item : LED_PINS) {
    pinMode(item, OUTPUT);
  }
  pinMode(TONE_PIN, OUTPUT);
}

void runSnake() {
  for (int count = 0; count < 8; count++) {
    int itemLed = LED_PINS[count];
    int itemFrequency = FREQUENCY_LIST[count];
    digitalWrite(itemLed, HIGH);
    tone(TONE_PIN, itemFrequency);
    delay(1000);
    digitalWrite(itemLed, LOW);
    noTone(TONE_PIN);
  }
}

#endif