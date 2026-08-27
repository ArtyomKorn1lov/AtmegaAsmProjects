#include <Arduino.h>
#include "core/core.h"

const int BYTES_4 = 32;
const int BYTES_8 = 64;

int additionValues(int firstValue, int secondValue)
{
    return firstValue + secondValue;
}

int subtraction(int firstValue, int secondValue)
{
    return firstValue - secondValue;
}

int multiply(int multiplied, int factor)
{
    return multiplied * factor;
}

int division(int dividend, int divisor)
{
    return dividend / divisor;
}

int modulo(int dividend, int divisor)
{
    return dividend % divisor;
}

int calculateSimpleMathExample(int x, int y)
{
    return (x * BYTES_8) / y;
}

int calculateMediumMathExample(int x, int y, int z, int a, int b, int c)
{
    return ((x - 5) * (y / 37) + z) / ((a - 41) * (b / c));
}

int calculateHighMathExample(int a, int b, int c, int d, int x, int y, int z)
{
    return ((a * b) + (c * BYTES_8 - d / c)) / ((x + y + z) * BYTES_4) - (z * z * z) / (x * x + a * y + c * y);
}

void calculateIntegers()
{
    printFormatValue(F("Integer values:"));
    Serial.println(additionValues(24535, 7546));
    Serial.println(subtraction(14546, 24535));
    Serial.println(multiply(3000, 15));
    Serial.println(division(23534, 345));
    Serial.println(modulo(10037, 103));
    Serial.println(calculateSimpleMathExample(13531, 337));
    Serial.println(calculateMediumMathExample(15, 326, -11, 155, 1112, 126));
    Serial.println(calculateHighMathExample(14, 225, 327, 1513, 22, 67, 3456));
}