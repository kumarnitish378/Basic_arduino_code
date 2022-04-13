 #define BRAKE 0
#define CW    1
#define CCW   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").

//MOTOR 1
#define MOTOR_A1_PIN 2
#define MOTOR_B1_PIN 4

#define PWM_MOTOR_1 5

#define CURRENT_SEN_1 12

#define EN_PIN_1 13

#define MOTOR_1 0
//char user_input; 
short usSpeed = 250;  //default motor speed
unsigned short usMotor_Status = BRAKE;
int sensor1 = 26;
int sensor2 = 27;
int count =0;
void setup()                        
{
  Serial.begin(57600);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);

  pinMode(PWM_MOTOR_1, OUTPUT);
 
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN_PIN_1, OUTPUT);
 
  Serial.println("Begin motor control");
  Serial.println(); //Print function list for user selection
  Serial.println("Enter number for control option:");
  Serial.println("1. STOP");
  Serial.println("2. FORWARD");
  Serial.println("3. REVERSE");
  Serial.println();

}

void loop()
{
  digitalWrite(EN_PIN_1, HIGH);
  if(digitalRead(sensor1)==LOW)
    {
      count=0;
    }
  Serial.println(digitalRead(sensor2));
  if(digitalRead(sensor2)==LOW)
  {
    count=1;
  }
  if(digitalRead(sensor2)==LOW  &&  digitalRead(sensor1)==LOW)
  {
    count=2;
  }
   if(count==0)
   {  
      Serial.println("3");
      Forward();
    }
   else if(count==1)
    {
      Serial.println("2");
      Reverse();
    }
    else
    {
      Serial.println("1");
       Stop();
    }
    delay(100);
  char user_input;  
  while(Serial.available())
  {
    user_input = Serial.read(); //Read user input and trigger appropriate function
    digitalWrite(EN_PIN_1, HIGH);
     
  }
}

void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
}

void Forward()
{
  Serial.println("Forward");
  usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
}

void Reverse()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Function that controls the variables: motor(0 ou 1), direction (cw ou ccw) e pwm (entra 0 e 255);
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
   
    digitalWrite(PWM_MOTOR_1, pwm);
  }
}
