#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Односвязный список строк
#include "string_list.h"

// Односвязный список строк - функции
StringList *initLinkedListString();
StringList *getLastItemLinkedListString(StringList *list);
int lengthLinkedListString(StringList *list);
StringList *getItemLinkedListString(StringList *list, int index);
void addItemLinkedListString(StringList **list, CharString *value);
void removeItemLinkedListString(StringList **list, int index);
void updateItemLinkedListString(StringList *list, int index, CharString *value);
void insertItemLinkedListString(StringList **list, int index, CharString *value);
void destructLinkedListString(StringList **list);

#endif