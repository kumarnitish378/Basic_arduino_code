String temp = "";
String abc = "";
int pin[4][7] = {
  {49, 48, 22, 53, 52, 50, 51},
  {45, 44, 26, 25, 24, 46, 47},
  {40, 39, 30, 29, 28, 41, 42},
  {36, 35, 34, 33, 32, 37, 38}
};

int zero[7] = {1, 1, 1, 1, 1, 1, 0};
int one[7] = {0, 1, 1, 0, 0, 0, 0};
int two[7] = {1, 1, 0, 1, 1, 0, 1};
int three[7] = {1, 1, 1, 1, 0, 0, 1};
int four[7] = {0, 1, 1, 1, 0, 1, 1};
int five[7] = {1, 0, 1, 1, 0, 1, 1};
int six[7] = {1, 0, 1, 1, 1, 1, 1};
int seven[7] = {1, 1, 1, 0, 0, 0, 0};
int eight[7] = {1, 1, 1, 1, 1, 1, 1};
int nine[7] = {1, 1, 1, 1, 0, 1, 1};

int digit[10][7] = {
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


int a[7] = {49, 48, 22, 53, 52, 50, 51};
int b[7] = {45, 44, 26, 25, 24, 46, 47};
int c[7] = {40, 39, 30, 29, 28, 41, 42};
int d[7] = {36, 35, 34, 33, 32, 37, 38};
void setup() {
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
  pinMode(34, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  //  digitalWrite(23,LOW);
  //  digitalWrite(27,LOW);
  digitalWrite(31, HIGH);
  //  digitalWrite(43,LOW);
  for (int i = 0; i < 4 ; i++)
  {
    for (int j = 0; j < 7 ; j++)
    {
      digitalWrite(pin[i][j], LOW );
    }
  }
  //  for (int k = 0; k < 7; k++)
  //  {
  //    if (zero[k] == 1)
  //    {
  //      digitalWrite(a[k], HIGH);
  //      digitalWrite(b[k], HIGH);
  //      digitalWrite(c[k], HIGH);
  //      digitalWrite(d[k], HIGH);
  //      Serial.println(a[k]);
  //    }
  //    else
  //    {
  //      digitalWrite(a[k], LOW);
  //      digitalWrite(b[k], LOW);
  //      digitalWrite(c[k], LOW);
  //      digitalWrite(d[k], LOW);
  //      Serial.println(a[k]);
  //    }
delay(10);
}
void loop()
{
  Display('a', 1); // value = 1023
  Display('b', 0);
  Display('c', 2);
  Display('d', 3);
  delay(2000);
  //off();
  Display('a', 0); // value = 0364
  Display('b', 3);
  Display('c', 6);
  Display('d', 4);
  delay(2000);
}
int Display(char pos, int value)
{
  //  char pos = char(pos)
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
  return (0);
}


void off()
{
  for (int i = 0; i < 4 ; i++)
  {
    for (int j = 0; j < 7 ; j++)
    {
      digitalWrite(pin[i][j], LOW );
    }
  }
}
