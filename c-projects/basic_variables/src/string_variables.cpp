#include <Arduino.h>
#include "core/core.h"

void executeChar()
{
    char symbol = 'K';
    Serial.print(F("Input char: "));
    Serial.println(symbol);
    symbol = 'p';
    Serial.print(F("New char: "));
    Serial.println(symbol);
}

void executeDynamicCharsString()
{
    char *string = nullptr;
    uint16_t stringLength = 0;
    uint16_t stringCapacity = 0;
    bool isStringInit = stringInit(&string, &stringLength, &stringCapacity);
    if (!isStringInit)
    {
        printFormatValue(F("String creation error"));
        return;
    }
    stringConcat(&string, &stringLength, &stringCapacity, "Hello");
    Serial.print(F("Original string: "));
    Serial.println(string);
    stringAddChar(&string, &stringLength, &stringCapacity, '!');
    Serial.print(F("Add char to string: "));
    Serial.println(string);
    stringInsertChar(&string, &stringLength, &stringCapacity, ' ', 5);
    Serial.print(F("Insert char in string: "));
    Serial.println(string);
    stringReplaceChar(&string, &stringLength, &stringCapacity, '?', 6);
    Serial.print(F("Replace char in string: "));
    Serial.println(string);
    stringRemoveChar(string, &stringLength, 6);
    Serial.print(F("Remove char from string: "));
    Serial.println(string);
    stringConcat(&string, &stringLength, &stringCapacity, "world!");
    Serial.print(F("Concat strings: "));
    Serial.println(string);
    stringClear(string, &stringLength);
    Serial.print(F("String cleared "));
    Serial.println(string);
    stringFree(&string, &stringLength, &stringCapacity);
}

void executeString()
{
    String string = "Hello";
    Serial.print(F("Original string: "));
    Serial.println(string);
    string += '!';
    Serial.print(F("Add char to string: "));
    Serial.println(string);
    string = string.substring(0, 5) + ' ' + string.substring(5);
    Serial.print(F("Insert char in string: "));
    Serial.println(string);
    string.setCharAt(6, '?');
    Serial.print(F("Replace char in string: "));
    Serial.println(string);
    string.remove(6, 1);
    Serial.print(F("Remove char from string: "));
    Serial.println(string);
    string.concat("world!");
    Serial.print(F("Concat strings: "));
    Serial.println(string);
    string = "";
    Serial.print(F("String cleared "));
    Serial.println(string);
    string.~String();
}

void processStringExample()
{
    printFormatValue(F("String and char values"));
    printFormatValue(F("Char:"));
    executeChar();
    printFormatValue(F("Dynamic chars string:"));
    executeDynamicCharsString();
    printFormatValue(F("String by class:"));
    executeString();
}