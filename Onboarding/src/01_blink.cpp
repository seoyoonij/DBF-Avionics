#include <Arduino.h>

void activity01_setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void activity01_loop() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(500);
}