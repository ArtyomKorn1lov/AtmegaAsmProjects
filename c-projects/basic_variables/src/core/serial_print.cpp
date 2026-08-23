#include <Arduino.h>

String separator = "----";

void printFormatValue(int value)
{
    Serial.println(separator);
    Serial.println(value);
    Serial.println(separator);
}

void printFormatValue(char value)
{
    Serial.println(separator);
    Serial.println(value);
    Serial.println(separator);
}

void printFormatValue(uint8_t value)
{
    Serial.println(separator);
    Serial.println(value);
    Serial.println(separator);
}

void printFormatValue(bool value)
{
    Serial.println(separator);
    Serial.println(value);
    Serial.println(separator);
}

void printFormatValue(String value)
{
    Serial.println(separator);
    Serial.println(value);
    Serial.println(separator);
}