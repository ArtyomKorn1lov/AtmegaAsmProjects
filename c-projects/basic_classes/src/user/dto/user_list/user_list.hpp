#ifndef USER_LIST_HPP
#define USER_LIST_HPP
#include <Arduino.h>
#include "../person/person.hpp"

class UserList
{
public:
    Person **items;
    int length;
    UserList(
        Person **items,
        int length
    );
    ~UserList();
};

#endif