#include <Arduino.h>
#include "core/core.h"

void executeChar()
{
    char symbol = 'K';
    Serial.print( "Input char: ");
    Serial.println(symbol);
    symbol = 'p';
    Serial.print("New char: ");
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
        String label = "String creation error";
        printFormatValue(label);
        label.~String();
        return;
    }
    stringConcat(&string, &stringLength, &stringCapacity, "Hello");
    Serial.print("Original string: ");
    Serial.println(string);
    stringAddChar(&string, &stringLength, &stringCapacity, '!');
    Serial.print("Add char to string: ");
    Serial.println(string);
    stringInsertChar(&string, &stringLength, &stringCapacity, ' ', 5);
    Serial.print("Insert char in string: ");
    Serial.println(string);
    stringReplaceChar(&string, &stringLength, &stringCapacity, '?', 6);
    Serial.print("Replace char in string: ");
    Serial.println(string);
    stringRemoveChar(string, &stringLength, 6);
    Serial.print("Remove char from string: ");
    Serial.println(string);
    stringConcat(&string, &stringLength, &stringCapacity, "world!");
    Serial.print("Concat strings: ");
    Serial.println(string);
    stringClear(string, &stringLength);
    Serial.print("String cleared ");
    Serial.println(string);
    stringFree(&string, &stringLength, &stringCapacity);
}

void executeString()
{
    String string = "Hello";
    Serial.print("Original string: ");
    Serial.println(string);
    string += '!';
    Serial.print("Add char to string: ");
    Serial.println(string);
    string = string.substring(0, 5) + ' ' + string.substring(5);
    Serial.print("Insert char in string: ");
    Serial.println(string);
    string.setCharAt(6, '?');
    Serial.print("Replace char in string: ");
    Serial.println(string);
    string.remove(6, 1);
    Serial.print("Remove char from string: ");
    Serial.println(string);
    string.concat("world!");
    Serial.print("Concat strings: ");
    Serial.println(string);
    string = "";
    Serial.print("String cleared ");
    Serial.println(string);
    string.~String();
}

void processStringExample()
{
    String label = "String and char values";
    printFormatValue(label);
    label = "Char:";
    printFormatValue(label);
    executeChar();
    label = "Dynamic chars string:";
    printFormatValue(label);
    executeDynamicCharsString();
    label = "String by class:";
    printFormatValue(label);
    executeString();
    label.~String();
}