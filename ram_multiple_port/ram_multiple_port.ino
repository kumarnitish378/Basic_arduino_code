#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
int error = 5;
int pin[] = { 2, 4, 12, 13, 33, 15, 27, 32,};
int Data[] = {0, 0, 0, 0, 0, 0, 0, 0,};
int touch[] = {0, 0, 0, 0, 0, 0, 0, 0,};
int a[8], b[8], c[8], d[8], e[8], f[8];
int gnd = 0;
int tgnd = 0;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup() {
  lcd.init();
  lcd.backlight();
  for (int j = 0; j <= 50; j++)
  {
    for (int i = 0; i <= 8; i++)
    {
      if (i == 1)
      {
        touch[i] = touchRead(pin[i]);
      }
    }
    gnd = touchRead(14);
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
    for (int j = 0; j <= 8; j++)
    {
      if (j == 1)
      {
        Data[j] = Data[j] + touchRead(pin[j]);
      }
    }
    tgnd = tgnd + touchRead(14);
  }
  for (int j = 0; j <= 8; j++)
  {
    if (j == 1)
    {
      Data[j] = Data[j] / 100;
    }
  }
  tgnd = tgnd / 100;
  for (int i = 0; i <= 8; i++)
  {
    if (i == 1)
    {
      a[i] = touch[i] - error;
      b[i] = gnd - error;
      c[i] = touch[i] / 2;
      d[i] = gnd / 2;
      e[i] = (touch[i] / 2) + 5;
      f[i] = gnd / 2 + 5;

      Serial.println(a[i]);
      Serial.print(',');

      Serial.println(b[i]);
      Serial.print(',');

      Serial.println(c[i]);
      Serial.print(',');

      Serial.println(d[i]);
      Serial.print(',');

      Serial.println(e[i]);
      Serial.print(',');

      Serial.println(f[i]);
      Serial.print(',');

      if (Data[i] >= a[i] && tgnd >= b[i])
      {
        lcd.setCursor(5, 0);
        lcd.print("None ");
      }
      else
      {
        if (Data[i] <= c[i] && tgnd <= d[i])
        {
          lcd.setCursor(5, 0);
          lcd.print("True ");
        }

        if (Data[i] <= c[i] && tgnd >= f[i])
        {
          lcd.setCursor(5, 0);
          lcd.print("true ");
        }
        if (Data[i] >= e[i] && tgnd <= d[i])
        {
          lcd.setCursor(5, 0);
          lcd.print("False");
        }
      }
    }
  }
}
