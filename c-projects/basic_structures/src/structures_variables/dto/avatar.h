#ifndef AVATAR_H
#define AVATAR_H
#include <Arduino.h>
#include "../../core/core.h"

struct Avatar
{
    int id;
    struct CharString *name;
    int8_t width;
    int8_t heigth;
};

#endif