#include <Arduino.h>
#include "../core/core.h"
#include "enums/enums.h"
#include "dto/dto.h"
#include "enums/enums.h"

UserList usersCreate()
{
    int length = 3;
    User *createdUsers = (User *)calloc(length, sizeof(User));
    UserList emptyUserList = {
        .items = nullptr,
        .length = 0,
    };

    if (createdUsers == nullptr)
    {
        Serial.println(F("Error allocate memory of Users"));
        return emptyUserList;
    }

    struct User *createdUser = nullptr;
    struct Person *createdPerson = nullptr;
    struct Avatar *createdAvatar = nullptr;

    createdUser = &createdUsers[0];
    createdUser->id = 1;
    createdUser->isAdmin = true;
    createdPerson = (struct Person *)calloc(1, sizeof(Person));
    if (createdPerson == nullptr)
    {
        Serial.println(F("Error allocate memory of create User 1"));
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) || !charStringInit(&createdPerson->name) || !charStringInit(&createdPerson->phone) || !charStringInit(&createdPerson->email))
    {
        Serial.println(F("Error allocate memory strings of create Person 1"));
        return;
    }
    charStringSet(&createdPerson->xmlId, "2fb52009-ad38-430a-a41d-645603a249fa");
    charStringSet(&createdPerson->name, "John");
    charStringSet(&createdPerson->phone, "+79043564367");
    charStringSet(&createdPerson->email, "admin@mail.com");
    createdPerson->age = 31;
    createdAvatar = (struct Avatar *)calloc(1, sizeof(Avatar));
    if (createdAvatar == nullptr)
    {
        Serial.println(F("Error allocate memory of create Avatar 1"));
        return;
    }
    createdAvatar->id = 1;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println(F("Error allocate memory strings of create User 1"));
        return;
    }
    charStringSet(&createdAvatar->name, "Admin");
    createdAvatar->width = 40;
    createdAvatar->heigth = 40;
    createdPerson->avatar = createdAvatar;
    createdUser->person = createdPerson;
    createdUser->status = Status::ACTIVE;

    createdUser = &createdUsers[1];
    createdUser->id = 2;
    createdUser->isAdmin = false;
    createdPerson = (struct Person *)calloc(1, sizeof(Person));
    if (createdPerson == nullptr)
    {
        Serial.println(F("Error allocate memory of create Person 2"));
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) || !charStringInit(&createdPerson->name) || !charStringInit(&createdPerson->phone) || !charStringInit(&createdPerson->email))
    {
        Serial.println(F("Error allocate memory strings of create User 2"));
        return;
    }
    charStringSet(&createdPerson->xmlId, "fc15af99-9bc7-49c3-adff-0c3ed6869a65");
    charStringSet(&createdPerson->name, "Steve");
    charStringSet(&createdPerson->phone, "+79046672130");
    charStringSet(&createdPerson->email, "mail3545@mail.com");
    createdPerson->age = 29;
    createdAvatar = (struct Avatar *)calloc(1, sizeof(Avatar));
    if (createdAvatar == nullptr)
    {
        Serial.println(F("Error allocate memory of create Avatar 2"));
        return;
    }
    createdAvatar->id = 2;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println(F("Error allocate memory strings of create User 2"));
        return;
    }
    charStringSet(&createdAvatar->name, "Manager");
    createdAvatar->width = 40;
    createdAvatar->heigth = 40;
    createdPerson->avatar = createdAvatar;
    createdUser->person = createdPerson;
    createdUser->status = Status::ACTIVE;

    createdUser = &createdUsers[2];
    createdUser->id = 3;
    createdUser->isAdmin = false;
    createdPerson = (struct Person *)calloc(1, sizeof(Person));
    if (createdPerson == nullptr)
    {
        Serial.println(F("Error allocate memory of create Person 3"));
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) || !charStringInit(&createdPerson->name) || !charStringInit(&createdPerson->phone) || !charStringInit(&createdPerson->email))
    {
        Serial.println(F("Error allocate memory strings of create User 3"));
        return;
    }
    charStringSet(&createdPerson->xmlId, "45221347-f2b3-47c1-bdbc-7196866165ff");
    charStringSet(&createdPerson->name, "Jack");
    charStringSet(&createdPerson->phone, "+79079346028");
    charStringSet(&createdPerson->email, "mail43563@mail.com");
    createdPerson->age = 32;
    createdAvatar = (struct Avatar *)calloc(1, sizeof(Avatar));
    if (createdAvatar == nullptr)
    {
        Serial.println(F("Error allocate memory of create Avatar 3"));
        return;
    }
    createdAvatar->id = 3;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println(F("Error allocate memory strings of create User 3"));
        return;
    }
    charStringSet(&createdAvatar->name, "Agent");
    createdAvatar->width = 40;
    createdAvatar->heigth = 40;
    createdPerson->avatar = createdAvatar;
    createdUser->person = createdPerson;
    createdUser->status = Status::INACTIVE;

    struct UserList userList = {
        .items = createdUsers,
        .length = length,
    };

    return userList;
}

void appendUser(UserList **userList)
{
    if (userList == nullptr)
    {
        Serial.println(F("Users cannot be null"));
        return;
    }

    struct User *createdUser = nullptr;
    struct Person *createdPerson = nullptr;
    struct Avatar *createdAvatar = nullptr;
    int *length = &(*userList)->length;
    User *items = (*userList)->items;
    items = (User *)realloc(items, (*length + 1) * sizeof(User));
    if (items == nullptr)
    {
        Serial.println(F("Error allocate memory of Users"));
        return;
    }
    (*length)++;
    createdUser = &items[(*length) - 1];
    memset(createdUser, 0, sizeof(User));

    createdUser->id = 4;
    createdUser->isAdmin = false;
    createdPerson = (struct Person *)calloc(1, sizeof(Person));
    if (createdPerson == nullptr)
    {
        Serial.println(F("Error allocate memory of create appended User"));
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) || !charStringInit(&createdPerson->name) || !charStringInit(&createdPerson->phone) || !charStringInit(&createdPerson->email))
    {
        Serial.println(F("Error allocate memory strings of appended Person"));
        return;
    }
    charStringSet(&createdPerson->xmlId, "428db1e4-2d1d-4449-bb5c-ee533e77b77e");
    charStringSet(&createdPerson->name, "Test");
    charStringSet(&createdPerson->phone, "+79999999999");
    charStringSet(&createdPerson->email, "test@mail.com");
    createdPerson->age = 24;
    createdAvatar = (struct Avatar *)calloc(1, sizeof(Avatar));
    if (createdAvatar == nullptr)
    {
        Serial.println(F("Error allocate memory of appended Avatar"));
        return;
    }
    createdAvatar->id = 4;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println(F("Error allocate memory strings of appended create User"));
        return;
    }
    charStringSet(&createdAvatar->name, "Agent");
    createdAvatar->width = 60;
    createdAvatar->heigth = 60;
    createdPerson->avatar = createdAvatar;
    createdUser->person = createdPerson;
    createdUser->status = Status::ACTIVE;

    (*userList)->items = items;
}

int findIndexById(UserList *userList, int id) 
{
    if (userList == nullptr)
    {
        Serial.println(F("Users cannot be null"));
        return;
    }
    int index = 0;
    for (uint8_t count = 0; count < userList->length; count++)
    {
        if ((&userList->items[count])->id != id)
        {
            continue;
        }
        index = count;
        break;
    }
    return index;
}

void deactivateById(UserList **userList, int id)
{
    int index = findIndexById(*userList, id);
    (&(*userList)->items[index])->status = Status::INACTIVE;
}

void removeById(UserList **userList, int id)
{
    int index = findIndexById(*userList, id);
    memmove((*userList)->items + index, (*userList)->items + index + 1, ((*userList)->length - index) * sizeof(User));
    (*userList)->length--;
}

void updateById(UserList **userList, int id)
{
    int index = findIndexById(*userList, id);
    struct User *userUpdated = nullptr;
    userUpdated = &(*userList)->items[index];

    userUpdated->isAdmin = true;
    userUpdated->status = Status::ACTIVE;
    charStringSet(&userUpdated->person->xmlId, "a994e056-b7af-436b-839d-560a0155375f");
    charStringSet(&userUpdated->person->name, "John");
    charStringSet(&userUpdated->person->name, "john@mail.com");
    charStringSet(&userUpdated->person->phone, "+79043564367");
    userUpdated->person->age = userUpdated->person->age + 7;
    charStringSet(&userUpdated->person->avatar->name, "Admin");
    userUpdated->person->avatar->width = userUpdated->person->avatar->width * 2;
    userUpdated->person->avatar->heigth = userUpdated->person->avatar->heigth * 3;
}

void usersPrint(UserList userList, CharString title)
{
    Serial.println(F("----"));
    Serial.println((&title)->value);
    Serial.println(F("----"));
    Serial.print(F("Users length: "));
    Serial.println(userList.length);

    for (int8_t count = 0; count < userList.length; count++)
    {
        struct User *user = &userList.items[count];
        struct Person *person = user->person;
        struct Avatar *avatar = person->avatar;
        Serial.println("----");
        Serial.print("User: ");
        Serial.println(user->id);
        Serial.println("----");
        Serial.print(F("Is admin: "));
        Serial.println(user->isAdmin ? F("true") : F("false"));
        Serial.print("Status: ");
        Serial.println(user->status == Status::ACTIVE ? F("Active") : F("Incactive"));
        Serial.println(F("Personal info:"));
        Serial.print(F("Xml Id: "));
        Serial.println(person->xmlId->value);
        Serial.print(F("Name: "));
        Serial.println(person->name->value);
        Serial.print(F("Email: "));
        Serial.println(person->email->value);
        Serial.print(F("Phone: "));
        Serial.println(person->phone->value);
        Serial.print(F("Age: "));
        Serial.println(person->age);
        Serial.println(F("Avatar info:"));
        Serial.print(F("Identifier: "));
        Serial.println(avatar->id);
        Serial.print(F("Name: "));
        Serial.println(avatar->name->value);
        Serial.print(F("Width: "));
        Serial.println(avatar->width);
        Serial.print(F("Heigth: "));
        Serial.println(avatar->heigth);
    }
}

void usersFree(UserList **userList)
{
    if (userList == nullptr || *userList == nullptr)
    {
        return;
    }

    if ((*userList)->items != nullptr)
    {
        for (int i = 0; i < (*userList)->length; i++)
        {
            User *user = &(*userList)->items[i];

            if (user->person == nullptr)
            {
                continue;
            }

            Person *person = user->person;

            if (person->avatar != nullptr)
            {
                Avatar *avatar = person->avatar;

                charStringFree(&avatar->name);

                free(avatar);
                person->avatar = nullptr;
            }

            charStringFree(&person->xmlId);
            charStringFree(&person->name);
            charStringFree(&person->phone);
            charStringFree(&person->email);

            free(person);
            user->person = nullptr;
        }

        free((*userList)->items);
        (*userList)->items = nullptr;
        (*userList)->length = 0;
    }

    free(*userList);
    *userList = nullptr;
}