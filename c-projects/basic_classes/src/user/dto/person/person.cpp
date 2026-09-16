#include <Arduino.h>
#include "../../enum/enum.hpp"
#include "../avatar/avatar.hpp"
#include "../statistic/statistic.hpp"
#include "person.hpp"

Person::Person(
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
)
    : id(id),
      code(code),
      xmlId(xmlId),
      name(name),
      phone(phone),
      email(email),
      address(address),
      age(age),
      isActive(isActive),
      group(group),
      avatar(avatar),
      statistic(statistic)
{
}

Person::~Person()
{
}

int Person::getId()
{
    return id;
}

String Person::getCode()
{
    return code;
}

String Person::getXmlId()
{
    return xmlId;
}