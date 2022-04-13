#include<math.h>

#include <Servo.h>
static const int servosPins[4] = {32 , 18 , 14, 4};
#define dirPin 26
#define stepPin 25
Servo servos[4];
float m1 = 20;
float m2 = 10;
float m3 = 100;

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
  //ArmMovement(Servo_m1_agle, Servo_m2_agle, Servo_m3_agle);
  ArmMovement(70, 10, 135);
  delay(500);

  ArmMovement(110, 180, 180);
  delay(500);
}

void ArmMovement(int theta1, int theta2, int theta3)
{
    float f1 = theta1;
    float f2 = theta2;
    float f3 = theta3;
    // float d1 = (f1-m1)/(f2-m1), d2 = (f2-m2)/(f2-m1), d3 = (f3-m3)/(f2-m1);
    int f = 180;
    int m = 20;  // f will be maximum value of all Angle, and x will we smallest Angle of all angle
    float d1 = (f1-m1)/(f-m);
    float d2 = (f2-m2)/(f-m);
    float d3 = (f3-m3)/(f-m);
   
    Serial.print(d1);
    Serial.print(",");
    Serial.print(d2);
    Serial.print(",");
    Serial.print(d3);
    Serial.println();
    float ang1 = m1;
    float ang2 = m2;
    float ang3 = m3;
    for (int i = m; i<f; i ++)
    {
        ang1 = ang1 + d1;
        ang2 = ang2 + d2;
        ang3 = ang3 + d3;
        Serial.print(round(ang1));
        Serial.print(",");
        Serial.print(round(ang2));
        Serial.print(",");
        Serial.print(round(ang3));
        Serial.println("");
        servos[0].write(round(ang1));
        servos[1].write(round(ang2));
        servos[2].write(round(ang3));
        delay(5);
    }
  m1 = round(ang1);
  m2 = round(ang2);
  m3 = round(ang3);
  delay(500);
}
