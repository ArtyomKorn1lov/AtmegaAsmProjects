#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include "dto/dto.h"

UserList usersCreate();
void appendUser(UserList **userList);
void usersPrint(UserList userList, CharString title);
void usersFree(UserList **userList);
int findIndexById(UserList *userList, int id);
void deactivateById(UserList **userList, int id);
void removeById(UserList **userList, int id);
void updateById(UserList **userList, int id);

#endif