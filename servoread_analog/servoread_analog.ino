
#include <Servo.h>
char posf;
char posb;

Servo myservo;  // create servo object to control a servo
double servoposition = 0;
const int servoAnalogOut = A1; //The new Servo Pin
void setup()
{
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
    posf = Serial.read();
    if (posf == 'r')
    {
      myservo.detach();
      delay(5000);
      servoposition = analogRead(servoAnalogOut);
      Serial.println(servoposition / 3.738);
      delay(500);
    }
    if (posf == 'w')
    {
      myservo.attach(7);
      myservo.write( int( servoposition));
      Serial.println(servoposition / 3.738);
    }
  }
}
