 #include<Math.h>

#include <Servo.h>
static const int servosPins[4] = {32 , 18 , 14, 4};
#define dirPin 26
#define stepPin 25
Servo servos[4];

int thetaIn[3] = {10, 20, 60};
int thetaFinal[3]; // = {90, 10, 90};

int m1_max = 90;
int m2_max = 90;
int m3_max = 90;
int sta = 0;

int tm1, tm2, tm3;
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
  
  ArmMovement(10, 20, 30);
  ArmMovement(60, 0, 60);
  ArmMovement(120, 30, 120);
  ArmMovement(150, 0, 180);
  ArmMovement(160, 30, 30);
  ArmMovement(180, 0, 0);
  ArmMovement(120, 160, 120);
  ArmMovement(120, 180, 20);
  ArmMovement(60, 120, 160);
  ArmMovement(120, 180, 20);
  ArmMovement(60, 120, 160);
  ArmMovement(120, 180, 20);
  ArmMovement(40, 20, 100);
}

void ArmMovement(int theta1, int theta2, int theta3)
{
  thetaFinal[0] = theta1;
  thetaFinal[1] = theta2;
  thetaFinal[2] = theta3;
  //  Y_for Servo motor 1
  if (thetaIn[0] <= thetaFinal[0])
  {
    int temp_m1 = thetaIn[0] - (thetaFinal[0] + thetaIn[0]);
    m1_max = abs(temp_m1);
    Serial.print("m1_max=");
    Serial.print(m1_max);
    Serial.println();
  }
  else if (thetaIn[0] > thetaFinal[0])
  {
    m1_max = thetaIn[0] + (thetaIn[0] - thetaFinal[0]);
    Serial.print("m1_max=");
    Serial.print(m1_max);
    Serial.println();
  }

  //  Y_for Servo motor 2
  if (thetaIn[1] <= thetaFinal[1])
  {
    int temp_m2 = thetaIn[1] - (thetaFinal[1] + thetaIn[1]);
    m2_max = abs(temp_m2);
    Serial.print("m2_max=");
    Serial.print(m2_max);
    Serial.println();
  }
  else if (thetaIn[1] > thetaFinal[1])
  {
    m2_max = thetaIn[1] + (thetaIn[1] - thetaFinal[1]);
    Serial.print("m2_max=");
    Serial.print(m2_max);
    Serial.println();
  }

  //  Y_for Servo motor 3
  if (thetaIn[2] <= thetaFinal[2])
  {
    int temp_m3 = thetaIn[2] - (thetaFinal[2] + thetaIn[2]);
    m3_max = abs(temp_m3);
    Serial.print("m3_max=");
    Serial.print(m3_max);
    Serial.println();
  }
  else if (thetaIn[2] > thetaFinal[2])
  {
    m3_max = thetaIn[2] + (thetaIn[2] - thetaFinal[2]);
    Serial.print("m3_max=");
    Serial.print(m3_max);
    Serial.println();
  }

  //  ----------Angle Setting -----
  for (int i = 0; i <= 360; i++)
  {
    Serial.println(i);
    if ((i >= thetaIn[0]) && (i <= m1_max))
    {
      if (thetaIn[0] >= thetaFinal[0])
      {
        tm1 = thetaIn[0] - (i - thetaIn[0]);
        servos[0].write(tm1);
        Serial.print(tm1);
        Serial.print(",");
      }
      else
      {
        tm1 = thetaIn[0] + (i - thetaIn[0]);
        servos[0].write(tm1);
        Serial.print(tm1);
        Serial.print(",");
      }
    }
    else
    {
      Serial.print("*");
      Serial.print(",");
    }

    //-----------------------------------------------
    //    Setting agle of Servo motor 2
    if (i >= thetaIn[1] && i <= m2_max)
    {
      if (thetaIn[1] >= thetaFinal[1])
      {
        tm2 = thetaIn[1] - (i - thetaIn[1]);
        servos[1].write(tm2);
        Serial.print(tm2);
        Serial.print(",");
      }
      else
      {
        tm2 = thetaIn[1] + (i - thetaIn[1]);
        servos[1].write(tm2);
        Serial.print(tm2);
        Serial.print(",");
      }
    }
    else
    {
      Serial.print("*");
      Serial.print(",");
    }
    //-----------------------------------------------
    //    Setting agle of Servo motor 3
    if (i >= thetaIn[2] && i <= m3_max)
    {
      if (thetaIn[2] >= thetaFinal[2])
      {
        tm3 = thetaIn[2] - (i - thetaIn[2]);
        servos[2].write(tm3);
        Serial.print(tm3);
        Serial.print(",");
      }
      else
      {
        tm3 = thetaIn[2] + (i - thetaIn[2]);
        servos[2].write(tm3);
        Serial.print(tm3);
        Serial.print(",");
      }
    }
    else
    {
      Serial.print("*");
      Serial.print(",");
    }
    Serial.println();
    delay(10);
    if (tm1 == thetaFinal[0] && tm2 == thetaFinal[1] && tm3 == thetaFinal[2])
    {
      break;
    }
  }
  Serial.print(tm1);
  Serial.print(",");
  Serial.print(tm2);
  Serial.print(",");
  Serial.print(tm3);
  Serial.print("\n");
  thetaIn[0] = tm1;
  thetaIn[1] = tm2;
  thetaIn[2] = tm3;
  delay(10);
}
//............................................
//---------clockwise Steper motor------------

void clockwise()
{
  int stepsPerRevolution = 100;
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000);
  }
}

//---------Anticlockwise Steper motor------------

void anticlockwise()
{
  int stepsPerRevolution = 100;
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000);
  }
}
//..............pick,drop................................
void pick()
{
    servos[3].write(150);
    delay(2000);
    servos[3].write(30);
    delay(500);
}
void drop()
{
    servos[3].write(150);
    delay(500);
}
