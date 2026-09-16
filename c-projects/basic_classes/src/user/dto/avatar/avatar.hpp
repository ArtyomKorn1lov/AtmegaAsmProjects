#ifndef AVATAR_HPP
#define AVATAR_HPP
#include <Arduino.h>

class Avatar
{
private:
    String name;
    String code;
    uint8_t width;
    uint8_t heigth;
public:
    Avatar(
        String name, 
        String code, 
        uint8_t width, 
        uint8_t heigth
    );
    ~Avatar();
    String getName();
    void setName(String value);
    String getCode();
    uint8_t getWidth();
    void setWidth(uint8_t value);
    uint8_t getHeight();
    void setHeight(uint8_t value);
};


#endif