int p1[] = {0, 0, 0, 0, 0};
char p[] = {'0', '0', '0', '0', '0'};
char segment[4] = {'d', 'c', 'b', 'a'};
int pin[4][7] = {
  {49, 48, 22, 53, 52, 50, 51},
  {45, 44, 26, 25, 24, 46, 47},
  {40, 39, 30, 29, 28, 41, 42},
  {38, 35, 43, 33, 32, 37, 36}
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
int d[7] = {38, 35, 43, 33, 32, 37, 36};
//float num = 124.6;
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
  pinMode(43, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);

  for (int i = 0; i < 4 ; i++)
  {
    for (int j = 0; j < 7 ; j++)
    {
      digitalWrite(pin[i][j], LOW );
    }
  }

  delay(10);
}
void loop()
{ 
    String num = "14.  67";
  //int num = 6934;
  //outputint(num);
  //output(num);
  String x1=String(num);
  int len1=num.length();
  int abc = 0;
  for(int i=0; i<=len1;i++)
  {
    if( int (num[i])==46)
    {
      abc = 1;
      break;
    }
  }
  if( abc == 1)
    {
      Serial.println("float value");
      output(num);
    }
    else
    {
      Serial.println("integer value");
      outputint(num);
    }
  delay(500);
}


// Calling Function
void output(String num)
{
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
  if ( len <=5&&len>0)
  {
   digitalWrite(27, HIGH);
    digitalWrite(31, LOW); 
  }
  else if (len >5 )
  {
    digitalWrite(31,HIGH);
    digitalWrite(27,LOW );
  }
  else
  {
    digitalWrite(31, LOW);
    digitalWrite(27, LOW);
  }

  int A = int(p1[0]);
  Serial.println(A);
  int B = int (p1[1]);
  Serial.println(B);
  int C = int (p1[2]);
  Serial.println(C);
  int D = int (p1[3]) ;
  Serial.println(D);
  int E = int (p1[4]);
  Serial.println(E);
  if (len <= 4 && len > 0)
  {
    Display('b', A);
    Display('c', B);
    Display('d', C);
  }
  else if (len <= 3 && len > 0)
  {
    Display('c', C);
    Display('d', D);
  }
  else
  {
    Display('a', A);
    Display('b', B);
    Display('c', C);
    Display('d', D);
  }
  len = 0;
}


// function for integer number

void outputint(String num)
{
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
  // Serial.print("____________________________")

  int A = int(p1[0]);
  Serial.println(A);
  int B = int (p1[1]);
  Serial.println(B);
  int C = int (p1[2]);
  Serial.println(C);
  int D = int (p1[3]) ;
  Serial.println(D);
  int E = int (p1[4]);
  Serial.println(E);
  if (len <= 3 && len > 0)
  {
    Display('b', A);
    Display('c', B);
    Display('d', C);
  }
  else if (len <= 2 && len > 0)
  {
    Display('c', C);
    Display('d', D);
  }
  else if (len <= 1 && len > 0)
  {
    Display('d', D);
  }
  else
  {
    Display('a', A);
    Display('b', B);
    Display('c', C);
    Display('d', D);
  }
  len = 0;
}


// Function to display 0-9 Number


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
