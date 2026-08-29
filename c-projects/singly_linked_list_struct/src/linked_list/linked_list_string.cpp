#include <Arduino.h>
#include "../core/core.h"
#include "string_list.h"

StringList *initLinkedListString()
{
    StringList *list = nullptr;
    return list;
}

StringList *getLastItemLinkedListString(StringList *list)
{
    if (list == nullptr)
    {
        return nullptr;
    }
    StringList *tmpList = list;
    while (tmpList->next != nullptr)
    {
        tmpList = tmpList->next;
    }
    return tmpList;
}

int lengthLinkedListString(StringList *list)
{
    int length = 0;
    StringList *tmpList = list;
    while (tmpList != nullptr)
    {
        length++;
        tmpList = tmpList->next;
    }
    return length;
}

StringList *getItemLinkedListString(StringList *list, int index)
{
    if (list == nullptr || index < 0)
    {
        return nullptr;
    }
    StringList *tmpList = list;
    int counter = 0;
    while (tmpList != nullptr)
    {
        if (counter == index)
        {
            return tmpList;
        }
        tmpList = tmpList->next;
        counter++;
    }
    return nullptr;
}

void addItemLinkedListString(StringList **list, CharString *value)
{
    StringList *lastNode = getLastItemLinkedListString(*list);
    if (lastNode == nullptr)
    {
        *list = (StringList *)calloc(1, sizeof(StringList));
        (*list)->value = value;
        (*list)->next = nullptr;
        return;
    }
    StringList *newItem = (StringList *)calloc(1, sizeof(StringList));
    newItem->value = value;
    newItem->next = nullptr;
    lastNode->next = newItem;
}

void removeItemLinkedListString(StringList **list, int index)
{
    StringList *node = getItemLinkedListString(*list, index);
    if (node == nullptr)
    {
        return;
    }
    if (index == 0)
    {
        StringList *nextNode = getItemLinkedListString(*list, index + 1);
        nextNode != nullptr ? *list = nextNode : *list = nullptr;
    }
    else
    {
        StringList *prevNode = getItemLinkedListString(*list, index - 1);
        prevNode->next = node->next;
    }
    charStringFree(&node->value);
    free(node);
}

void updateItemLinkedListString(StringList *list, int index, CharString *value)
{
    StringList *node = getItemLinkedListString(list, index);
    if (node == nullptr)
    {
        return;
    }
    charStringFree(&node->value);
    node->value = value;
}

void insertItemLinkedListString(StringList **list, int index, CharString *value)
{
    StringList *node = getItemLinkedListString(*list, index);
    if (node == nullptr)
    {
        *list = (StringList *)calloc(1, sizeof(StringList));
        (*list)->value = value;
        (*list)->next = nullptr;
        return;
    }
    StringList *newItem = (StringList *)calloc(1, sizeof(StringList));
    newItem->value = value;
    if (index == 0)
    {
        newItem->next = (*list);
        *list = newItem;
        return;
    }
    StringList *nextNode = node->next;
    if (nextNode == nullptr)
    {
        newItem->next = nullptr;
        node->next = newItem;
        return;
    }
    newItem->next = nextNode;
    node->next = newItem;
}

void destructLinkedListString(StringList **list)
{
    if (*list == nullptr)
    {
        return;
    }
    charStringFree(&(*list)->value);
    if ((*list)->next == nullptr)
    {
        free(list);
        return;
    }
    StringList *tmpList = (*list)->next;
    free(list);
    while (tmpList->next != nullptr)
    {
        charStringFree(&tmpList->value);
        StringList *tmpNode = tmpList->next;
        free(tmpList);
        tmpList = tmpNode;
    }
    charStringFree(&tmpList->value);
    free(tmpList);
}