#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include "dto/dto.h"

UserList usersCreate();
void usersPrint(UserList userList);
void usersFree(UserList **userList);

#endif