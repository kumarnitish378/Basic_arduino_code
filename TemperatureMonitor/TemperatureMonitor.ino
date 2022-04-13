/*
 * pin configration
 * Arduino pin : {22,23,24,25,26,27,28,29,30,31,32,33,43,35,36,37,38,39,40,41,42,44,45,46,47,48,49,50,51,52,53};
 * Display pin : { 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,29,30,31,32,34,35,36,37, 5, 6};
 * col  28= GND ;
 * D.p1 :8 = 23 ;
 * D.p2 :12 = 27 ;
 * D.p3 :16 = 31 ;
 * com  : 1, 40 ;
 * N/C  :2,3,4,33,38,39 ;
 */
 
char ch[4];
int aa = 0;
int pos = 0;
int pin[4][7] =
{
  {49, 48, 22, 53, 52, 50, 51},
  {45, 44, 26, 25, 24, 46, 47},
  {40, 39, 30, 29, 28, 41, 42},
  {38, 35, 43, 33, 32, 37, 36}
};
int a[7] = {49, 48, 22, 53, 52, 50, 51};
int b[7] = {45, 44, 26, 25, 24, 46, 47};
int c[7] = {40, 39, 30, 29, 28, 41, 42};
int d[7] = {38, 35, 43, 33, 32, 37, 36};
int digit[10][7] =
{
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};

// Variables for temperature
float t[50], temp;
int ThermistorPin = A0;
float raw_adc;
float R1 = 10000;
float logR2, R2, T, C, Vout;
float c1 = -1.250195230e-03, c2 = 6.003625790e-04, c3 = -11.84324074e-07;
float Vin = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  
  pinMode(27, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(31, OUTPUT);
  

}
void loop()
{
  float Tdata = Temperature();
  String tempdata = String(Tdata);
  RamShanker(tempdata);
}


void RamShanker(String data)
{
//  String data="02.04";
  //Serial.println(data);
  //Serial.println(data.length());
  for(int i=0; i<data.length(); i++)
  {
    if (int(data[i]) != 46)
    {
      ch[aa] = data[i];
      aa += 1;
    }
    else
    {
      pos = i;
    }
  }
// Serial.print("Decimal at: ");
 //Serial.println(pos);
 //Serial.println(ch);
 
  int A = int(ch[0])-48;
 // Serial.println(A);
  int B = int (ch[1])-48;
  //Serial.println(B); 
  int C = int (ch[2])-48;
  //Serial.println(C);  
  int D = int (ch[3])-48 ;
  //Serial.println(D);

  if(data.length()>=5)
  {
   Display('a', A);
   Display('b', B);
   Display('c', C);
   Display('d', D);

   if (pos== 3)
  {
    digitalWrite(31, HIGH);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
  else if (pos ==2)
  {
    digitalWrite(31, LOW);
    digitalWrite(27, HIGH);
    digitalWrite(23, LOW);
  }
  else if (pos == 1)
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, HIGH);
  }
  else
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
 }
 else if(data.length()==4)
{
   Display('b', A);
   Display('c', B);
   Display('d', C);

   if (pos== 2)
  {
    digitalWrite(31, HIGH);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
  else if (pos ==1)
  {
    digitalWrite(31, LOW);
    digitalWrite(27, HIGH);
    digitalWrite(23, LOW);
  }
  else
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
 }
 else if(data.length()<=3)
  {
   Display('c', A);
   Display('d', B);

   if (pos== 1)
  {
    digitalWrite(31, HIGH);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
  else
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
 }
   delay(500);
}

////display function

void Display(char pos, int value)
{
  switch (pos)
  {
    case 'a':
      {
        for (int i = 0; i <= 9; i++)
        {
          if (i == value)
          {
            for (int j = 0; j < 7; j++)
            {
              if (digit[i][j] == 1)
              {
                digitalWrite(a[j], HIGH );
              }
              if (digit[i][j] == 0)
              {
                digitalWrite(a[j], LOW );
              }
            }
          }
        }
        break;
      }
    case 'b':
      {
        for (int i = 0; i <= 9; i++)
        {
          if (i == value)
          {
            for (int j = 0; j < 7; j++)
            {
              if (digit[i][j] == 1)
              {
                digitalWrite(b[j], HIGH );
              }
              if (digit[i][j] == 0)
              {
                digitalWrite(b[j], LOW );
              }
            }
          }
        }
        break;
      }
    case 'c':
      {
        for (int i = 0; i <= 9; i++)
        {
          if (i == value)
          {
            for (int j = 0; j < 7; j++)
            {
              if (digit[i][j] == 1)
              {
                digitalWrite(c[j], HIGH );
              }
              if (digit[i][j] == 0)
              {
                digitalWrite(c[j], LOW );
              }
            }
          }
        }
        break;
      }
    case 'd':
      {
        for (int i = 0; i <= 9; i++)
        {
          if (i == value)
          {
            for (int j = 0; j < 7; j++)
            {
              if (digit[i][j] == 1)
              {
                digitalWrite(d[j], HIGH );
              }
              if (digit[i][j] == 0)
              {
                digitalWrite(d[j], LOW );
              }
            }
          }
        }
        break;
      }
  }
//  return (0);
}

float Temperature()
{
   T = 0.0;
  for (int i = 0; i <= 50; i++) {

    raw_adc = analogRead(ThermistorPin);
   Vout = (raw_adc * Vin) / 1023.0;
   // Vout = (raw_adc *( Vin / 1023.0));
    R2 = R1 * ((Vin / Vout) - 1);
    logR2 = log(R2);
    temp = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
    temp = temp - 273.15;
    t[i] = (temp * 9.0) / 5.0 + 32.0;
    T = T + t[i];
    //    Serial.print("T: ");
    //    Serial.println(T, 1);
    delay(20);
  }
  //  T = (t[0] + t[1] + t[2] + t[3] + t[4] + t[5] + t[6] + t[7] + t[8] + t[9]) / 10;
  T = T / 50;
  C = (T - 32) / 1.8;

 // Serial.print(Vout);
 // Serial.print(",");
  //Serial.print(R2);
  //Serial.print(",");
  Serial.print("Temp: ");
  Serial.print(T, 1);
  Serial.print(" F");
  Serial.print(",");
  Serial.print(C, 1);
  Serial.println(" C");

  //  delay(500);
  return (T);
}
