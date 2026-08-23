#ifndef CORE_H
#define CORE_H
#include <Arduino.h>

// Функции работы с печатью последовательного порта
void printFormatValue(int value);
void printFormatValue(char value);
void printFormatValue(uint8_t value);
void printFormatValue(bool value);
void printFormatValue(String value);

// Функции, структуры и константы работы со строками
#include "string/string.h"

#endif