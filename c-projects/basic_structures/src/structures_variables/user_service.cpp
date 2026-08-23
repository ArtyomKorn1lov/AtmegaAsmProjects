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
        Serial.println("Error allocate memory of Users");
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
        Serial.println("Error allocate memory of create User 1");
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) 
        || !charStringInit(&createdPerson->name)
        || !charStringInit(&createdPerson->phone)
        || !charStringInit(&createdPerson->email)
    ) 
    {
        Serial.println("Error allocate memory strings of create Person 1");
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
        Serial.println("Error allocate memory of create Avatar 1");
        return;
    }
    createdAvatar->id = 1;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println("Error allocate memory strings of create User 1");
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
        Serial.println("Error allocate memory of create Person 2");
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) 
        || !charStringInit(&createdPerson->name)
        || !charStringInit(&createdPerson->phone)
        || !charStringInit(&createdPerson->email)
    ) 
    {
        Serial.println("Error allocate memory strings of create User 2");
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
        Serial.println("Error allocate memory of create Avatar 2");
        return;
    }
    createdAvatar->id = 2;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println("Error allocate memory strings of create User 2");
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
        Serial.println("Error allocate memory of create Person 3");
        return;
    }
    if (
        !charStringInit(&createdPerson->xmlId) 
        || !charStringInit(&createdPerson->name)
        || !charStringInit(&createdPerson->phone)
        || !charStringInit(&createdPerson->email)
    ) 
    {
        Serial.println("Error allocate memory strings of create User 3");
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
        Serial.println("Error allocate memory of create Avatar 3");
        return;
    }
    createdAvatar->id = 3;
    if (!charStringInit(&createdAvatar->name))
    {
        Serial.println("Error allocate memory strings of create User 3");
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

void usersPrint(UserList userList)
{
    String label = "Original users:";
    printFormatValue(label);
    Serial.print("Users length: ");
    Serial.println(userList.length);

    for (int8_t count = 0; count < userList.length; count++)
    {
        struct User *user = &userList.items[count];
        struct Person *person = user->person;
        struct Avatar *avatar = person->avatar;
        label = "User: " + (String)user->id;
        printFormatValue(label);
        Serial.print("Is admin: ");
        Serial.println(user->isAdmin ? "true" : "false");
        Serial.print("Status: ");
        Serial.println(user->status == Status::ACTIVE ? "Active" : "Incactive");
        Serial.println("Personal info:");
        Serial.print("Xml Id: ");
        Serial.println(person->xmlId->value);
        Serial.print("Name: ");
        Serial.println(person->name->value);
        Serial.print("Email: ");
        Serial.println(person->email->value);
        Serial.print("Phone: ");
        Serial.println(person->phone->value);
        Serial.print("Age: ");
        Serial.println(person->age);
        Serial.println("Avatar info:");
        Serial.print("Identifier: ");
        Serial.println(avatar->id);
        Serial.print("Name: ");
        Serial.println(avatar->name->value);
        Serial.print("Width: ");
        Serial.println(avatar->width);
        Serial.print("Heigth: ");
        Serial.println(avatar->heigth);
    }

    label.~String();
}

void usersFree(UserList **userList)
{
    if (userList == nullptr || *userList == nullptr) {
        return;
    }

    if ((*userList)->items != nullptr)
    {
        for (int i = 0; i < (*userList)->length; i++)
        {
            User *user = &(*userList)->items[i];

            if (user->person == nullptr) {
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