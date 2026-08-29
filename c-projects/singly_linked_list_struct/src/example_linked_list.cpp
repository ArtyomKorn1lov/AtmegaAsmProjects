#include <Arduino.h>
#include "core/core.h"
#include "linked_list/linked_list.h"

void createItems(StringList **list)
{
    CharString *createdString = nullptr;
    charStringInit(&createdString);
    charStringSet(&createdString, "Hello ");
    addItemLinkedListString(list, createdString);
    createdString = nullptr;
    charStringInit(&createdString);
    charStringSet(&createdString, "world");
    addItemLinkedListString(list, createdString);
    createdString = nullptr;
    charStringInit(&createdString);
    charStringSet(&createdString, "!");
    addItemLinkedListString(list, createdString);
}

void printItems(StringList *list)
{
    int length = lengthLinkedListString(list);
    Serial.print(F("Length: "));
    Serial.println(length);
    for (int count = 0; count < length; count++)
    {
        StringList *item = getItemLinkedListString(list, count);
        Serial.print(F("Index: "));
        Serial.println(count);
        Serial.print(F("Value: "));
        Serial.println(item->value->value);
    }
}

void processLinkedList()
{
    printFormatValue(F("Singly linked list struct:"));
    StringList *list = initLinkedListString();
    createItems(&list);
    printFormatValue(F("Original list:"));
    printItems(list);

    CharString *string = nullptr;
    charStringInit(&string);
    charStringSet(&string, "Test");
    addItemLinkedListString(&list, string);
    removeItemLinkedListString(&list, 2);
    string = nullptr;
    charStringInit(&string);
    charStringSet(&string, "John");
    insertItemLinkedListString(&list, 1, string);
    removeItemLinkedListString(&list, 1);
    string = nullptr;
    charStringInit(&string);
    StringList *item = getItemLinkedListString(list, 0);
    charStringConcat(&string, item->value->value);
    charStringConcat(&string, " world!");
    updateItemLinkedListString(list, 0, string);

    printFormatValue(F("Edited list:"));
    printItems(list);

    destructLinkedListString(&list);
    printFormatValue(F("Desctruct successfully!"));
}