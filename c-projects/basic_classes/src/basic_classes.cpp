#include <Arduino.h>
#include "core/core.h"
#include "user/user.hpp"

// Note: Atmega328p не поддерживает throw exception без танцев с бубном, я опускаю это в рамках данной демонстрации
void processClassesExample() 
{
    printFormatValue(F("Class values:"));

    UserService service = UserService(UserFactory());
    UserList list = service.initPersons();

    printFormatValue(F("Original values:"));
    service.printPersons(list);

    list = service.addPerson(
        list,
        "Mike",
        "mike@mail.com",
        "+79467213765",
        "L. A., Carolina st. 69"
    );
    list = service.updatePerson(
        list,
        0,
        "Grace",
        "grace@mail.com",
        "+79375783210",
        "New York, test st. 45",
        Group::MANAGER
    );
    list = service.deactivePerson(
        list,
        0
    );
    list = service.deletePerson(
        list,
        1
    );

    printFormatValue(F("Updated values:"));
    service.printPersons(list);

    free(list.items);
    list.~UserList();
}