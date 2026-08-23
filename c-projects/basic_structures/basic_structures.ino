#include "src/basic_struct_data.h";

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