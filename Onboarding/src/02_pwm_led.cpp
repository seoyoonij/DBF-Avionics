#include <Arduino.h>

void activity02_setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void activity02_loop()
{
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(500);
}