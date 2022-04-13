#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
int x1 = 0;
int x2 = 0;
unsigned int t1 = 0;
unsigned int t2 = 0;
int error = 5;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup() {
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

  for (int i = 0; i < 100; i++)
  {
    t1 = t1 + touchRead(4);
    t2 = t2 + touchRead(14);

  }

  t1 = t1 / 100;
  t2 = t2 / 100;

  int a = x1 - error;
  int b = x2 - error;
  int c = 25 - (25 / x1);
  int d = 25 - (25 / x2);
  int e = (25 - (25 / x1)) + 5;
  int f = (25 - (25 / x2)) + 5;

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
