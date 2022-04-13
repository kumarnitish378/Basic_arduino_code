#include <Servo.h>

Servo servo1, servo2, servo3;
void setup() 
{
  
servo1.attach(18);

servo2.attach(32);

servo3.attach(14);
}

void loop() 
{
servo1.write(90);
}
