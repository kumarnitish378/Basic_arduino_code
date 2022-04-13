/*
   roboarm Serialmonitor control with sensor
*/




#include <Servo.h>
static const int servosPins[4] = {18 , 32 , 14 , 4};
#define dirPin 26
#define stepPin 25
Servo servos[4];
char var ;
void setServos(int degrees)
{
  for (int i = 0; i <= 2; ++i)
  {
    if (i >= 1)
    {
      servos[i].write((degrees + (60 * i)) % 180);
      Serial.print((degrees  + (60 * i)) % 180);

      Serial.print(',');
    }
    else
    {
      //   servos[0].write(180);
      servos[0].write((degrees * 3 - 1) % 180);
      Serial.print((degrees * 3 - 1) % 180);
      Serial.print(',');
    }
    Serial.println();
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(27, INPUT);
  Serial. println("Distance sensor test");
  Serial. println(',');

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
  while (Serial.available() > 0)
  {
    var = Serial.read();
    if (var == 'u')
    {
      up();
      delay(5000);
    }
    if (var == 'd')
    {
      down();
    }
    if (var == 'p')
    {
      pick();
    }
    if (var == 'l')
    {
     drop();
    }
    if (var == 'c')
    {
      anticlockwise();
    }
    if (var == 'a')
    {
      clockwise();
    }
  }
}
void clockwise()
{
  int stepsPerRevolution = 800;
  digitalWrite(dirPin, LOW );
  for (int i = 0; i < stepsPerRevolution; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}

void anticlockwise()
{
  int stepsPerRevolution = 800;
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(3000);
}
void down()
{

  for (int posDegrees = 59; posDegrees >= 0; posDegrees--)
  {
    setServos(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
}
void up()
{
  for (int posDegrees = 0; posDegrees <= 55; posDegrees++)
  {
    setServos(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
}

void pick()
{
  servos[3].write(180);
  delay(2000);
  servos[3].write(10);
  delay(500);
}
void drop()
{
 
   while (1)
      {
       Serial.print( digitalRead(27));
        if (digitalRead(27) == 0)
        {
          delay(1000);
          servos[3].write(180);
          delay(1000);
          Serial.println("droped");
          break ;
        }
      }
}
