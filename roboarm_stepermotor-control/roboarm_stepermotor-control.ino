#include<math.h>
#include <Servo.h>
static const int servosPins[4] = {32 , 18 , 14, 4};
#define dirPin 26
#define stepPin 25
Servo servos[4];
float m1 = 20;
float m2 = 10;
float m3 = 100;
float m4 = 0;
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
   Anglevalue1();
//   Anglevalue2();
}

//------------------------------Anglevalue function->1 ------------------------------------------
void Anglevalue1()
{
//  ArmMovement(90, 90, 90,0);
//  ArmMovement(90, 0, 90,0);
  ArmMovement(10, 20, 30,0);
  ArmMovement(60, 0, 60,90);
  ArmMovement(120, 30, 120,0);
  ArmMovement(150, 0, 180,-90);
  ArmMovement(160, 30, 30,0);
  ArmMovement(180, 0, 0,0);
  ArmMovement(110, 180, 120, 90);
  ArmMovement(110, 180, 120, -90);
  ArmMovement(110, 180, 120, 90);
  ArmMovement(120, 180, 20,0);
  ArmMovement(60, 120, 160,-90);
  ArmMovement(120, 180, 20,0);
  ArmMovement(60, 120, 160,90);
  ArmMovement(120, 180, 20,0);
  ArmMovement(100, 90, 90,-90);
  ArmMovement(40, 180, 150,0);
  ArmMovement(140, 0, 0,90);
  ArmMovement(100, 90, 90,-180);
  ArmMovement(100, 90, 90,180);
  ArmMovement(40, 180, 150,0);
  ArmMovement(140, 0, 0,-90);
  ArmMovement(100, 90, 90,0);
  ArmMovement(40, 180, 150,90);
  ArmMovement(140, 0, 0,0);
  ArmMovement(100, 90, 90,-90);
  ArmMovement(40, 20, 100,0);
}

//------------------------------Anglevalue function->2 ------------------------------------------
void Anglevalue2()
{
  ArmMovement(90, 90, 90,0);
  ArmMovement(180, 90, 90,0);
  ArmMovement(170, 80, 100,80);
  ArmMovement(160, 70, 110,-80);
  ArmMovement(150, 60, 120,80);
  ArmMovement(140, 50, 130,-80);
  ArmMovement(130, 40, 140,80);
  ArmMovement(120, 30, 150,-80);
  ArmMovement(110, 20, 160,80);
  ArmMovement(100, 10, 170,-80);
  ArmMovement(90, 0, 180,0);
  
  ArmMovement(80, 180, 0,80);
  ArmMovement(70, 170, 10,-80);
  ArmMovement(60, 160, 20,80);
  ArmMovement(50, 150, 30,-80);
  ArmMovement(30, 140, 40,80);
  ArmMovement(20, 130, 50,-80);
  ArmMovement(10, 120, 60,80);
  ArmMovement(0, 110, 70,-80);
}

//--------------------------ArmMovement function --------------------------------------------------

void ArmMovement(int theta1, int theta2, int theta3, int theta4)
{
  float f1 = theta1;
  float f2 = theta2;
  float f3 = theta3;
  float f4 = theta4;
  // float d1 = (f1-m1)/(f2-m1), d2 = (f2-m2)/(f2-m1), d3 = (f3-m3)/(f2-m1);
  int f = 200;
  int m = 20;  // f will be maximum value of all Angle, and x will we smallest Angle of all angle
  float d1 = (f1 - m1) / (f - m);
  float d2 = (f2 - m2) / (f - m);
  float d3 = (f3 - m3) / (f - m);
  float d4 = (f4 - m4) / (f - m);
  float UpdateStepperAngle = d4;
  d4 = d4 * 8.888;
  int rotation = round(d4);
  Serial.print(d1);
  Serial.print(",");
  Serial.print(d2);
  Serial.print(",");
  Serial.print(d3);
  Serial.print(",");
  Serial.print(d4);
  Serial.println();
  float ang1 = m1;
  float ang2 = m2;
  float ang3 = m3;
  float ang4 = m4;
  for (int i = m; i < f; i ++)
  {
    ang1 = ang1 + d1;
    ang2 = ang2 + d2;
    ang3 = ang3 + d3;
    ang4 = ang4 + UpdateStepperAngle;
    Serial.print(round(ang1));
    Serial.print(",");
    Serial.print(round(ang2));
    Serial.print(",");
    Serial.print(round(ang3));
    Serial.print(",");
    Serial.print(round(ang4));
    Serial.println("");
    servos[0].write(round(ang1));
    servos[1].write(round(ang2));
    servos[2].write(round(ang3));
    
    
    if (d4 >= 0)
    {
      digitalWrite(dirPin, HIGH);
      for (int j = 0; j < d4; j++)
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }
    }
    if (d4 < 0)
    { 
      digitalWrite(dirPin, LOW);
      for (int j = 0; j > d4; j--)
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
      }
    }

    delay(5);
  }
  m1 = round(ang1);
  m2 = round(ang2);
  m3 = round(ang3);
  m4 = round(ang4);
  delay(500);
}
