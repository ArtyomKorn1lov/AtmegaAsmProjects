#include <Arduino.h>
#include "core/core.h"

const uint8_t FIRST_CONST = 4;
const uint8_t SECOND_CONST = 8;

uint8_t addition(uint8_t firstValue, uint8_t secondValue)
{
    return firstValue + secondValue;
}

uint8_t subtraction(uint8_t firstValue, uint8_t secondValue)
{
    return firstValue - secondValue;
}

uint8_t multiply(uint8_t multiplied, uint8_t factor)
{
    return multiplied * factor;
}

uint8_t division(uint8_t dividend, uint8_t divisor)
{
    return dividend / divisor;
}

uint8_t modulo(uint8_t dividend, uint8_t divisor)
{
    return dividend % divisor;
}

uint8_t calculateSimpleMathExample(uint8_t x, uint8_t y)
{
    return (x * FIRST_CONST) / y;
}

uint8_t calculateMediumMathExample(uint8_t x, uint8_t y, uint8_t z, uint8_t a, uint8_t b, uint8_t c)
{
    return ((x - 5) * (y / 2) + z) / ((a - 11) * (b / c));
}

uint8_t calculateHighMathExample(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t x, uint8_t y, uint8_t z)
{
    return ((a * b) + (c * SECOND_CONST - d / c)) / ((x + y + z) * FIRST_CONST) - (z * z * z) / (x * x + a * y + c * y);
}

void calculateBytes()
{
    printFormatValue(F("Byte values:"));
    Serial.println(addition(111, 58));
    Serial.println(subtraction(255, 187));
    Serial.println(multiply(34, 7));
    Serial.println(division(243, 28));
    Serial.println(modulo(231, 13));
    Serial.println(calculateSimpleMathExample(12, 8));
    Serial.println(calculateMediumMathExample(17, 21, 34, 5, 9, 1));
    Serial.println(calculateHighMathExample(56, 2, 13, 8, 17, 21, 7));
}