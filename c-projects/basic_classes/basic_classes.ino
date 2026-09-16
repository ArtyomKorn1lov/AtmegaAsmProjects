#include "src/basic_classes.hpp";

bool flag = true;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (!flag) {
        return;
    }
    flag = false;
    processClassesExample();
}