#include <Servo.h>
Servo myservo;
static const int servosPins[4] = { 14, 18, 32, 4};

Servo servos[4];
void setup()
{
  Serial.begin(115200);

  for (int i = 0; i < 4; ++i)
  {
    if (!servos[i].attach(servosPins[i]))
    {
      Serial.print("Servo ");
      Serial.print(i);
      Serial.println("attach error");
    }
  }
 }
 void loop()
    { 
      servos[2].write(5);
      delay(50);
      servos[1].write(80);
      delay(50);
      servos[0].write(140);
      delay(300);
      servos[3].write(150);
      delay(2000);
      servos[3].write(130);
      delay(1000);
      
      servos[2].write(90);
      delay(50);
      servos[1].write(60);
      delay(50);
      servos[0].write(180);
      delay(1000);
      

      servos[2].write(5);
      delay(50);
      servos[1].write(80);
      delay(50);
      servos[0].write(140);
      delay(300);
      servos[3].write(150);
      delay(2000);
      
      servos[2].write(90);
      delay(50);
      servos[1].write(60);
      delay(50);
      servos[0].write(180);
      delay(1000);
      

//      servos[2].write(120);
//      delay(50);
//      servos[1].write(90);
//      delay(50);
//      servos[0].write(30);
//      delay(1000);
    }
  
    void servo1()
    {

      for (int i = 0; i <= 180 ; i++)
      {
        myservo.attach(32);
        myservo.write(i);
        delay(50);
        myservo.attach(18);
        myservo.write(i);
        delay(50);
        myservo.attach(14);
        myservo.write(i);
        delay(50);
      }
      for (int i = 180; i >= 0 ; i--)
      {
        myservo.attach(32);
        myservo.write(i);
        delay(50);
        myservo.attach(18);
        myservo.write(i);
        delay(50);
        myservo.attach(14);
        myservo.write(i);
        delay(50);
      }
    }
