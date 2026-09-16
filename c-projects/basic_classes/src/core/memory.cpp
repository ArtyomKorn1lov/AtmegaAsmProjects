#include <Arduino.h>

extern int __heap_start;
extern void *__brkval;

int getFreeRam()
{
    int stackVariable;

    if (__brkval == nullptr) {
        return (int)&stackVariable - (int)&__heap_start;
    }

    return (int)&stackVariable - (int)__brkval;
}