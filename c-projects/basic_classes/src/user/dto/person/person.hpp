#ifndef PERSON_HPP
#define PERSON_HPP
#include <Arduino.h>
#include "../../enum/enum.hpp"
#include "../avatar/avatar.hpp"
#include "../statistic/statistic.hpp"

class Person
{
private:
    int id;
    String code;
    String xmlId;

public:
    String name;
    String phone;
    String email;
    String address;
    int age;
    bool isActive;
    Group group;
    Avatar avatar;
    Statistic statistic;
    Person(
        int id,
        String code,
        String xmlId,
        String name,
        String phone,
        String email,
        String address,
        int age,
        bool isActive,
        Group group,
        Avatar avatar,
        Statistic statistic
    );
    ~Person();
    int getId();
    String getCode();
    String getXmlId();
};

#endif