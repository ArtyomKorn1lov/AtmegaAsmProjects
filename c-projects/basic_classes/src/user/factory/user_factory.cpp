#include <Arduino.h>
#include "../enum/enum.hpp"
#include "../dto/dto.hpp"
#include "user_factory.hpp"

UserFactory::UserFactory()
{
}

UserFactory::~UserFactory()
{
}

Person *UserFactory::createPerson(
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
)
{
    return new Person(  
        id,
        code,
        xmlId,
        name,
        phone,
        email,
        address,
        age,
        isActive,
        group,
        Avatar(
          avatarName,
          avatarCode,
          avatarWidth,
          avatarHeigth
        ),
        Statistic(
          salesVolume,
          price,
          dealCount,
          leadCount,
          constPrice,
          otherExpenses
        )
    );
}