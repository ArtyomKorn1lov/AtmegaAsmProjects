#ifndef STRING_HELPER_H
#define STRING_HELPER_H
#include <Arduino.h>

extern const uint8_t STRING_BLOCK_SIZE;
extern const uint8_t TERMINAL_NULL;
bool stringInit(char **string, uint16_t *length, uint16_t *capacity);
bool stringAddChar(char **string, uint16_t *length, uint16_t *capacity, char symbol);
bool stringConcat(char **string, uint16_t *length, uint16_t *capacity, char *appendString);
bool stringInsertChar(char **string, uint16_t *length, uint16_t *capacity, char symbol, uint16_t index);
bool stringReplaceChar(char **string, uint16_t *length, uint16_t *capacity, char symbol, uint16_t index);
bool stringRemoveChar(char *string, uint16_t *length, uint16_t index);
bool stringShrink(char **string, uint16_t length, uint16_t *capacity);
void stringClear(char *string, uint16_t *length);
void stringFree(char **string, uint16_t *length, uint16_t *capacity);
bool stringSet(char **string, uint16_t *length, uint16_t *capacity, char *newString);

#endif