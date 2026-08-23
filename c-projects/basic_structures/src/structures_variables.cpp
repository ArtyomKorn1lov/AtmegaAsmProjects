#include <Arduino.h>
#include "core/core.h"
#include "structures_variables/structures_variables.h"

void processStructExample() {
    String label = "Structures values 1:";
    printFormatValue(label);
    UserList *userList = (struct UserList *)calloc(1, sizeof(UserList));
    *userList = usersCreate();
    usersPrint(*userList);
    usersFree(&userList);
    
    label = "Structures values 2:";
    printFormatValue(label);
    userList = (struct UserList *)calloc(1, sizeof(UserList));
    *userList = usersCreate();
    usersPrint(*userList);
    usersFree(&userList);

    label = "Structures values 3:";
    printFormatValue(label);
    userList = (struct UserList *)calloc(1, sizeof(UserList));
    *userList = usersCreate();
    usersPrint(*userList);
    usersFree(&userList);
}