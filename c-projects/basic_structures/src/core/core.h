#ifndef CORE_H
#define CORE_H
#include <Arduino.h>

// Функции, структуры и константы работы со строками
#include "string/string.h"

// Функции работы с печатью последовательного порта
void printFormatValue(int value);
void printFormatValue(char value);
void printFormatValue(uint8_t value);
void printFormatValue(bool value);
void printFormatValue(String value);
void printFormatValue(const __FlashStringHelper *value);

// Функции работы с памятью
int getFreeRam();

#endif