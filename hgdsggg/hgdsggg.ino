int p1[] = {0, 0, 0, 0, 0};
char p[] = {'0', '0', '0', '0', '0'};
int pin[4][7] = {
  {49, 48, 22, 53, 52, 50, 51},
  {45, 44, 26, 25, 24, 46, 47},
  {40, 39, 30, 29, 28, 41, 42},
  {38, 35, 43, 33, 32, 37, 36}
};
int a[7] = {49, 48, 22, 53, 52, 50, 51};
int b[7] = {45, 44, 26, 25, 24, 46, 47};
int c[7] = {40, 39, 30, 29, 28, 41, 42};
int d[7] = {38, 35, 43, 33, 32, 37, 36};
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
  //
  pinMode(27, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(31, OUTPUT);
}

void loop()
{
  digitalWrite(31, LOW);
  //
  String num = "12";
  String x = String(num);
  int len = x.length();
  Serial.print("lenth = :");
  Serial.println(len);
  for (int i = 0; len >= i; i++)
  {
    p[i] = x[i];
  }
  int temp = 0;
  for (int j = 0; j < len; j++)
  {
    if ((int(p[j]) - 48) != -2)
    {
      p1[temp] = int(p[j]) - 48;
      temp += 1;
    }
  }
  //  Serial.println("___________________________");
  for (int j = 0; j < len; j++)
  {
    Serial.println(p1[j]);
  }
  // Serial.print("____________________________");
  int A = int(p1[0]);
  Serial.println(A);
  int B = int (p1[1]);
  Serial.println(B);
  int C = int (p1[2]);
  Serial.println(C);
  int D = int (p1[3]) ;
  Serial.println(D);
  //
  if (len == 4)
  {
    Display('a', A);
    Display('b', B);
    Display('c', C);
    Display('d', D);
  }
  else if (len == 3)
  {
    Display('b', A);
    Display('c', B);
    Display('d', C);
  }
  else if (len == 2)
  {
    Display('c', A);
    Display('d', B);
  }
  if (len == 1)
  {
    Display('d', A);
  }
  if (len >= 5)
  {
    digitalWrite(31, HIGH);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
  }
  else if (len == 4)
  {
    digitalWrite(31, LOW);
    digitalWrite(27, HIGH);
    digitalWrite(23, LOW);
  }
  else if (len == 3)
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, HIGH);
  }
  else if (len == 2)
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, HIGH);
  }
  delay(500);
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
