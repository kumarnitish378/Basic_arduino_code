#include <Servo.h>

Servo myservo;
static const int servosPins[4] = {32 ,18,14,4};

Servo servos[4];

void setup()
{
  Serial.begin(115200);

  for (int i = 0; i <= 3; ++i) {
    if (!servos[i].attach(servosPins[i])) {
      Serial.print("Servo ");
      Serial.print(i);
      Serial.println("attach error");
    }
  }
}

void loop()
{
   servos[0].write(110);
   delay(20);
   servos[1].write(180);
   delay(20);
   servos[2].write(180);
   delay(1000);
}
