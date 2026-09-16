#include "user_list.hpp"

UserList::UserList(
    Person **items,
    int length)
    : items(items),
      length(length)
{
}

UserList::~UserList()
{
}