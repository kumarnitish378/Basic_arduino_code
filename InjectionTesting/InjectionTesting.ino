#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
int x1 = 0;
int x2 = 0;
int margin = 1.8;
unsigned int t1 = 0;
unsigned int t2 = 0;
int error = 10;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup() {
  lcd.init();
  lcd.backlight();
  x1 = touchRead(4);
  x2 = touchRead(14);
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

  Serial.print(50);
  Serial.print(',');
  Serial.print(0);
  Serial.print(',');
  Serial.print(t1 / 100);
  Serial.print(',');
  Serial.println(t2 / 100);
  t1 = t1 / 100;
  t2 = t2 / 100;
  Serial.println(x1);
  Serial.println(x2);
if(t1>=40-error&&t2>=41-error)
{
  lcd.setCursor(5, 0);
  lcd.print("None ");
}
else
{
  if(t1<=20 && t2<=20)
  {
  lcd.setCursor(5, 0);
  lcd.print("True ");
  }

  if(t1<=20 && t2>=25)
  {
    lcd.setCursor(5, 0);
    lcd.print("true ");
   
  }
  if(t1>=25 && t2<=20)
  {
    lcd.setCursor(5, 0);
    lcd.print("False");
  }
}
}
