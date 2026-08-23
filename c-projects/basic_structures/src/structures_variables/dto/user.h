#ifndef USER_H
#define USER_H
#include <Arduino.h>

struct User
{
    int id;
    bool isAdmin;
    enum Status status;
    struct Person *person;
};

#endif