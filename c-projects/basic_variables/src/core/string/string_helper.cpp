#include <Arduino.h>

extern const uint8_t STRING_BLOCK_SIZE = 8;
extern const uint8_t TERMINAL_NULL = '\0';

uint16_t stringCalculateCapacity(uint16_t size)
{
    return (size + STRING_BLOCK_SIZE - 1) / STRING_BLOCK_SIZE * STRING_BLOCK_SIZE;
}

bool stringReserve(char **string, uint16_t *capacity, uint16_t requiredSize)
{
    if (requiredSize <= *capacity)
    {
        return true;
    }
    uint16_t newCapacity = stringCalculateCapacity(requiredSize);
    char *allocatedString = (char *)realloc(*string, newCapacity);
    if (allocatedString == nullptr)
    {
        return false;
    }
    *string = allocatedString;
    *capacity = newCapacity;
    return true;
}

bool stringInit(char **string, uint16_t *length, uint16_t *capacity)
{
    *string = (char *)calloc(STRING_BLOCK_SIZE, sizeof(char));
    if (*string == nullptr)
    {
        return false;
    }
    *length = 0;
    *capacity = STRING_BLOCK_SIZE;
    return true;
}

bool stringAddChar(char **string, uint16_t *length, uint16_t *capacity, char symbol)
{
    uint16_t requiredSize = *length + 2;
    bool resultReserve = stringReserve(string, capacity, requiredSize);
    if (!resultReserve)
    {
        return false;
    }
    (*string)[*length] = symbol;
    (*length)++;
    (*string)[*length] = TERMINAL_NULL;
    return true;
}

bool stringConcat(char **string, uint16_t *length, uint16_t *capacity, char *appendString)
{
    uint16_t appendStringLength = strlen(appendString);
    uint16_t requiredSize = *length + appendStringLength + 1;
    bool resultReserve = stringReserve(string, capacity, requiredSize);
    if (!resultReserve)
    {
        return false;
    }
    memcpy(*string + *length, appendString, appendStringLength + 1);
    *length += appendStringLength;
    return true;
}

bool stringInsertChar(char **string, uint16_t *length, uint16_t *capacity, char symbol, uint16_t index)
{
    if (index > *length)
    {
        return false;
    }
    uint16_t requiredSize = *length + 2;
    bool resultReserve = stringReserve(string, capacity, requiredSize);
    if (!resultReserve)
    {
        return false;
    }
    memmove(*string + index + 1, *string + index, *length - index + 1);
    (*string)[index] = symbol;
    (*length)++;
    return true;
}

bool stringReplaceChar(char **string, uint16_t *length, uint16_t *capacity, char symbol, uint16_t index)
{
    if (index > *length)
    {
        return false;
    }
    (*string)[index] = symbol;
    return true;
}

bool stringRemoveChar(char *string, uint16_t *length, uint16_t index)
{
    if (index >= *length)
    {
        return false;
    }
    memmove(string + index, string + index + 1, *length - index);
    (*length)--;
    return true;
}

bool stringShrink(char **string, uint16_t length, uint16_t *capacity)
{
    uint16_t requiredSize = length + 1;
    uint16_t newCapacity = stringCalculateCapacity(requiredSize);
    if (newCapacity == *capacity)
    {
        return true;
    }
    char *allocatedString = (char *)realloc(*string, newCapacity);
    if (allocatedString == nullptr)
    {
        return false;
    }
    *string = allocatedString;
    *capacity = newCapacity;
    return true;
}

void stringClear(char *string, uint16_t *length)
{
    *length = 0;
    string[0] = TERMINAL_NULL;
}

void stringFree(char **string, uint16_t *length, uint16_t *capacity)
{
    free(*string);
    *string = nullptr;
    *length = 0;
    *capacity = 0;
}

bool stringSet(char **string, uint16_t *length, uint16_t *capacity, char *newString) {
    stringClear(*string, length);
    return stringConcat(string, length, capacity, newString);
}