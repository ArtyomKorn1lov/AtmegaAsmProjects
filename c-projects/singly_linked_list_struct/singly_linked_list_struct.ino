#include "src/example_linked_list.h"

bool flag = true;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (!flag) {
        return;
    }
    flag = false;
    processLinkedList();
}