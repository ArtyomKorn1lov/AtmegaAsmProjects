#ifndef USER_LIST_H
#define USER_LIST_H
#include <Arduino.h>

struct UserList
{
    User *items;
    int length;
};

#endif