#include <Servo.h>
static const int servosPins[4] = {18,32, 14, 4};
#define dirPin 26
#define stepPin 25
//#define stepsPerRevolution 200
Servo servos[4];

void setServos(int degrees)
{
  for (int i = 0; i < 3; ++i)
  {
    if (i == 0)
    {
      Serial.print("servo1: ");
      servos[0].write((degrees + (60 * i)) % 180);
      Serial.print((degrees + (60 * i)) % 180);
      Serial.print(',');
    }
    if (i == 1)
    {
      Serial.print("servo2: ");
      servos[1].write((degrees*2  + (60 * i)) % 180);
      Serial.print((degrees *2 + (60 * i)) % 180);
      Serial.print(',');
    }
    if (i == 2)
    {
      Serial.print("servo3: ");
      servos[2].write((degrees + (50 * (i+1))-1) % 180);
      Serial.print((degrees + (50 * (i+1))-1) % 180);
      Serial.print(',');
    }
  }
  Serial.println(',');
}
void setup()
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
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
  up();
 // delay(100);
  anticlockwise();
  //delay(100);
  down();
  //delay(100);
  pick();
 // delay(1000);
  up();
 // delay(100);
  clockwise();
 // delay(100);
  down();
 // delay(100);
  drop();
 // delay(100);
}

void clockwise()
{
  int stepsPerRevolution = 200;
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution; i++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000);
  }
}

void anticlockwise()
{
  int stepsPerRevolution = 200;
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution; i++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000);
  }
}
void up()
{
  for (int posDegrees = 0; posDegrees <= 30; posDegrees++)
  {
    setServos(posDegrees);
   // Serial.println(posDegrees);
    delay(10);
  }
}
void down()
{
  for (int posDegrees = 30; posDegrees >= 0; posDegrees--)
  {
    setServos(posDegrees);
  //  Serial.println(posDegrees);
    delay(10);
  }
}

void pick()
{
    servos[3].write(180);
    delay(2000);
    servos[3].write(155);
    delay(500);
}
void drop()
{
    servos[3].write(180);
    delay(500);
}
