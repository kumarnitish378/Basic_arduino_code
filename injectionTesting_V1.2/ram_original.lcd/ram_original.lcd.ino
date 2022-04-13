#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
int x1 = 0;
int x11= 0;
int x22 = 0;
int x2 = 0;
int a = 0;
unsigned int t1 = 0;
unsigned int t2 = 0;
int error = 10;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup()
{
  lcd.init();
  lcd.backlight();
  for (int j = 1; j <= 50; j++)
  {
    x1 = touchRead(4);
    x2 = touchRead(14);
  }
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("calibrating...");
  delay(1000);
  lcd.clear();
  Serial.begin(115200);
}
void loop()
{
  while (1)
  {
    for (int j = 0; j <= 2; j++)
    {
      x11 = touchRead(4);
      x22 = touchRead(14);
    }
    if (x11 <= 70 && x22 <= 70)
    {
      Serial.print(4 );
      Serial.print(',');
      Serial.print(14);
      Serial.print(',');
      Serial.print("conected");
      Serial.println();
      break;
    }
    else if (x11 <= 70 && x22 > 70)
    {
      Serial.print(4 );
      Serial.print("conected");
      Serial.print(',');
      Serial.print(14 );
      Serial.print("Notconected");
      Serial.println();
    }
    else if (x22 <= 70 && x11 > 70)
    {
      Serial.print(14 );
      Serial.print("conected" );
      Serial.print(',');
      Serial.print(4 );
      Serial.print("Notconected");
      Serial.println();
    }
    else
    {
      Serial.print(4 );
      Serial.print("Notconected");
      Serial.print(',');
      Serial.print(14 );
      Serial.print("Notconected");
      Serial.println();
    }
  }
for (int i = 0; i < 100; i++)
{
  t1 = t1 + touchRead(4);
  t2 = t2 + touchRead(14);

}

t1 = t1 / 100;
t2 = t2 / 100;

int a = x1 - error;
int b = x2 - error;
int c = x1 / 2;
int d = x2 / 2;
int e = (x1 / 2) + 5;
int f = (x2 / 2) + 5;

if (t1 >= a && t2 >= b)
{
  lcd.setCursor(5, 0);
  lcd.print("None ");
}
else
{
  if (t1 <= c && t2 <= d)
  {
    lcd.setCursor(5, 0);
    lcd.print("True ");
  }

  if (t1 <= c && t2 >= f)
  {
    lcd.setCursor(5, 0);
    lcd.print("true ");
  }
  if (t1 >= e && t2 <= d)
  {
    lcd.setCursor(5, 0);
    lcd.print("False");
  }
}
}
