#include "avatar.hpp"

Avatar::Avatar(
    String name,
    String code,
    uint8_t width,
    uint8_t heigth)
    : name(name),
      code(code),
      width(width),
      heigth(heigth) 
{
}

Avatar::~Avatar()
{
}

String Avatar::getName()
{
    return name;
}

void Avatar::setName(String value)
{
    name = value;
}

String Avatar::getCode()
{
    return code;
}

uint8_t Avatar::getWidth()
{
    return width;
}

void Avatar::setWidth(uint8_t value)
{
    width = value;
}

uint8_t Avatar::getHeight()
{
    return heigth;
}

void Avatar::setHeight(uint8_t value)
{
    heigth = value;
}
