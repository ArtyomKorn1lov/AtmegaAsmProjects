#ifndef STRING_LIST_H
#define STRING_LIST_H

#include "../core/core.h"

struct StringList
{
    CharString *value;
    StringList *next;
};

#endif