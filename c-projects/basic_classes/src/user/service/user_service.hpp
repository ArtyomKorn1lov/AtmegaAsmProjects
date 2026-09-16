#ifndef USER_SERVICE_HPP
#define USER_SERVICE_HPP
#include "../enum/enum.hpp"
#include "../dto/dto.hpp"
#include "../factory/factory.hpp"

class UserService
{
private:
    UserFactory factory;
    Person findByIndex(
        UserList list,
        int index
    );
public:
    UserService(UserFactory factory);
    ~UserService();
    UserList initPersons();
    UserList addPerson(
        UserList list,
        String name,
        String email,
        String phone,
        String address
    );
    UserList updatePerson(
        UserList list,
        int index,
        String name,
        String email,
        String phone,
        String address,
        Group group
    );
    UserList deactivePerson(
        UserList list,
        int index
    );
    UserList deletePerson(
        UserList list,
        int index
    );
    void printPersons(UserList list);
};

#endif