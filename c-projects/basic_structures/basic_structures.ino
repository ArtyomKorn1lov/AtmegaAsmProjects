#include "src/basic_structures.h";

bool flag = true;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (!flag) {
        return;
    }
    processStructExample();
    flag = false;
}