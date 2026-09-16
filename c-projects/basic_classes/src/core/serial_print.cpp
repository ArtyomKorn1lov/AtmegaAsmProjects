#include <Arduino.h>

void printFormatValue(int value)
{
    Serial.println(F("----"));
    Serial.println(value);
    Serial.println(F("----"));
}

void printFormatValue(char value)
{
    Serial.println(F("----"));
    Serial.println(value);
    Serial.println(F("----"));
}

void printFormatValue(uint8_t value)
{
    Serial.println(F("----"));
    Serial.println(value);
    Serial.println(F("----"));
}

void printFormatValue(bool value)
{
    Serial.println(F("----"));
    Serial.println(value);
    Serial.println(F("----"));
}

void printFormatValue(String value)
{
    Serial.println(F("----"));
    Serial.println(value);
    Serial.println(F("----"));
}

void printFormatValue(const __FlashStringHelper *value)
{
    Serial.println(F("----"));
    Serial.println(value);
    Serial.println(F("----"));
}