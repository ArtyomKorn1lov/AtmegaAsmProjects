#include "../../core/core.h"
#include "../enum/enum.hpp"
#include "../dto/dto.hpp"
#include "../factory/factory.hpp"
#include "user_service.hpp"

UserService::UserService(UserFactory factory)
    : factory(factory)
{
}

UserService::~UserService()
{
}

UserList UserService::initPersons()
{
    int length = 2;
    Person **items = (Person **)calloc(length, sizeof(Person *));

    items[0] = factory.createPerson(
        1,
        "user-id-1",
        "57231266-acfb-40b2-80ff-d5e0b71ebc84",
        "John",
        "+79463674623",
        "mail@mail.com",
        "Moscow, lebedeva st. 15",
        32,
        true,
        Group::ADMIN,
        "Large Photo",
        "large-photo",
        40,
        40,
        100,
        120,
        15,
        30,
        1500,
        500
    );

    items[1] = factory.createPerson(
        2,
        "user-id-2",
        "1d7e5621-d926-4e68-95d7-24bf16e936c9",
        "Steve",
        "+7999999999",
        "test@mail.com",
        "St. Peterburg, test st. 16",
        29,
        true,
        Group::MANAGER,
        "Large Photo",
        "large-photo",
        40,
        40,
        30,
        200,
        10,
        17,
        750,
        0
    );

    return UserList(items, length);
}

UserList UserService::addPerson(
    UserList list,
    String name,
    String email,
    String phone,
    String address
)
{
    int newLength = list.length + 1;
    Person **newItems = (Person **)realloc(list.items, newLength * sizeof(Person *));
    list.items = newItems;

    list.items[newLength - 1] = factory.createPerson(
        3,
        "user-id-3",
        "7027831e-bfe3-4623-a095-ee18f2b23707",
        name,
        phone,
        email,
        address,
        35,
        true,
        Group::DEFAULT_USER,
        "Small Photo1",
        "small-photo",
        20,
        20,
        15,
        150,
        5,
        8,
        230,
        50
    );

    list.length = newLength;

    return list;
}

UserList UserService::updatePerson(
    UserList list,
    int index,
    String name,
    String email,
    String phone,
    String address,
    Group group
)
{
    Person item = findByIndex(list, index);

    item.name = name;
    item.email = email;
    item.phone = phone;
    item.address = address;
    item.group = group;

    item.avatar.setName("Small Photo 2");
    item.avatar.setWidth(25);
    item.avatar.setHeight(25);

    *list.items[index] = item;
    return list;
}

UserList UserService::deactivePerson(
    UserList list,
    int index
)
{
    Person item = findByIndex(list, index);

    item.isActive = false;

    *list.items[index] = item;
    return list;
}

UserList UserService::deletePerson(
    UserList list,
    int index
)
{
    if (index < 0 || index >= list.length) {
        return list;
    }
    delete list.items[index];
    int moveCount = list.length - index - 1;
    if (moveCount > 0) 
    {
        memmove(list.items + index, list.items + index + 1, moveCount * sizeof(Person *));
    }
    list.length--;
    return list;
}

void UserService::printPersons(UserList list)
{
    for (int count = 0; count < list.length; count++)
    {
        Person item = *list.items[count];
        Serial.print(F("User: "));
        Serial.println(item.getId());
        Serial.print(F("Code: "));
        Serial.println(item.getCode());
        Serial.print(F("XmlId: "));
        Serial.println(item.getXmlId());
        Serial.print(F("Name: "));
        Serial.println(item.name);
        Serial.print(F("Phone: "));
        Serial.println(item.phone);
        Serial.print(F("Address: "));
        Serial.println(item.address);
        Serial.print(F("Age: "));
        Serial.println(item.age);
        Serial.print(F("Active: "));
        Serial.println(item.isActive ? "true" : "false");
        Serial.println(F("Avatar: "));
        Serial.print(F("Name:"));
        Serial.println(item.avatar.getName());
        Serial.print(F("Code: "));
        Serial.println(item.avatar.getCode());
        Serial.print(F("Width: "));
        Serial.println(item.avatar.getWidth());
        Serial.print(F("Heigh: "));
        Serial.println(item.avatar.getHeight());
        Serial.println(F("User statistic: "));
        Serial.print(F("Revenue: "));
        Serial.println(item.statistic.revenue());
        Serial.print(F("AverageBill: "));
        Serial.println(item.statistic.averageBill());
        Serial.print(F("Conversion: "));
        Serial.println(item.statistic.conversion());
        Serial.print(F("Income: "));
        Serial.println(item.statistic.income());
        Serial.print(F("Profitability: "));
        Serial.println(item.statistic.profitability());
        Serial.print(F("LTV: "));
        Serial.println(item.statistic.ltv());
    }
}


Person UserService::findByIndex(
    UserList list,
    int index
)
{
    for (uint8_t count = 0; count < list.length; count++)
    {
        if (count == index) {
            return *list.items[count];
        }
    }
}