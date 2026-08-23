#include "src/basic_variables.h";

bool flag = true;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (!flag) {
        return;
    }
    calculateIntegers();
    calculateBytes();
    processStringExample();
    flag = false;
}