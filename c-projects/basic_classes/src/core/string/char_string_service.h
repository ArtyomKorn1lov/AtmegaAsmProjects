#ifndef CHAR_STRING_SERVICE_H
#define CHAR_STRING_SERVICE_H
#include <Arduino.h>
#include "dto/char_string.h"
#include "string_helper.h"

bool charStringInit(CharString **string);
bool charStringAddChar(CharString **string, char symbol);
bool charStringConcat(CharString **string, char *appendString);
bool charStringInsertChar(CharString **string, char symbol, uint16_t index);
bool charStringReplaceChar(CharString **string, char symbol, uint16_t index);
bool charStringRemoveChar(CharString **string, uint16_t index);
bool charStringShrink(CharString **string);
void charStringClear(CharString **string);
void charStringFree(CharString **string);
void charStringSet(CharString **string, char *newString);

#endif