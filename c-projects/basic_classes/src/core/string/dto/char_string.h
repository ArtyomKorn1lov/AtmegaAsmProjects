#ifndef CHAR_STRING_H
#define CHAR_STRING_H
#include <Arduino.h>

struct CharString
{
    char *value;
    uint16_t length;
    uint16_t capacity;
};

#endif