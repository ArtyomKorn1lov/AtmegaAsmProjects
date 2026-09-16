#include <Arduino.h>
#include "dto/char_string.h"
#include "string_helper.h"

bool charStringInit(CharString **string)
{
    *string = (struct CharString *)calloc(1, sizeof(CharString));
    return stringInit(&(*string)->value, &(*string)->length, &(*string)->capacity);
}

bool charStringAddChar(CharString **string, char symbol)
{
    return stringAddChar(&(*string)->value, &(*string)->length, &(*string)->capacity, symbol);
}

bool charStringConcat(CharString **string, char *appendString)
{
    return stringConcat(&(*string)->value, &(*string)->length, &(*string)->capacity, appendString);
}

bool charStringInsertChar(CharString **string, char symbol, uint16_t index)
{
    return stringInsertChar(&(*string)->value, &(*string)->length, &(*string)->capacity, symbol, index);
}

bool charStringReplaceChar(CharString **string, char symbol, uint16_t index)
{
    return stringReplaceChar(&(*string)->value, &(*string)->length, &(*string)->capacity, symbol, index);
}

bool charStringRemoveChar(CharString **string, uint16_t index)
{
    return stringRemoveChar((*string)->value, &(*string)->length, index);
}

bool charStringShrink(CharString **string)
{
    return stringShrink(&(*string)->value, (*string)->length, &(*string)->capacity);
}

void charStringClear(CharString **string)
{
    stringClear((*string)->value, &(*string)->length);
}

void charStringFree(CharString **string)
{
    stringFree(&(*string)->value, &(*string)->length, &(*string)->capacity);
    free(*string);
    *string = nullptr;
}

void charStringSet(CharString **string, char *newString)
{
    stringSet(&(*string)->value, &(*string)->length, &(*string)->capacity, newString);
}