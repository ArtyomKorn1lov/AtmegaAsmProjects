#include <Arduino.h>
#include "core/core.h"
#include "structures_variables/structures_variables.h"

void processStructExample() {
    printFormatValue(F("Structure values:"));
    UserList *userList = (struct UserList *)calloc(1, sizeof(UserList));
    *userList = usersCreate();
    CharString *title = (struct CharString *)calloc(1, sizeof(CharString));
    if (!charStringInit(&title)) 
    {
        Serial.println(F("Error allocate memory string of title"));
        return;
    }
    charStringSet(&title, "Original users:");
    usersPrint(*userList, *title);
    appendUser(&userList);
    deactivateById(&userList, 2);
    removeById(&userList, 1);
    updateById(&userList, 3);
    charStringSet(&title, "Updated users:");
    usersPrint(*userList, *title);
    usersFree(&userList);
    charStringFree(&title);
}