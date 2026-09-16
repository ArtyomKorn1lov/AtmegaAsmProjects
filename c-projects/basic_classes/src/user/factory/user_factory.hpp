#ifndef USER_FACTORY_HPP
#define USER_FACTORY_HPP
#include <Arduino.h>
#include "../enum/enum.hpp"
#include "../dto/dto.hpp"

class UserFactory
{
public:
    UserFactory();
    ~UserFactory();
    Person *createPerson(
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
        String avatarName,
        String avatarCode,
        uint8_t avatarWidth,
        uint8_t avatarHeigth,
        int salesVolume,
        int price,
        int dealCount,
        int leadCount,
        int constPrice,
        int otherExpenses
    );
};

#endif