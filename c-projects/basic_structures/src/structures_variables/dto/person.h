#ifndef PERSON_H
#define PERSON_H
#include <Arduino.h>
#include "../../core/core.h"

struct Person
{
    struct CharString *xmlId;
    struct CharString *name;
    struct CharString *phone;
    struct CharString *email;
    int8_t age;
    struct Avatar *avatar;
};

#endif