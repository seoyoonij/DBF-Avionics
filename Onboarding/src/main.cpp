#include <Arduino.h>

void activity01_setup();
void activity01_loop();

void setup()
{
#ifdef ACTIVITY_01
  activity01_setup();
#endif
#ifdef ACTIVITY_01
  activity02_setup();
#endif
}

void loop()
{
#ifdef ACTIVITY_01
  activity01_loop();
#endif
#ifdef ACTIVITY_01
  activity02_loop();
#endif
}
