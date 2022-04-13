#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
int x[] = {0,0,0,0,0,0,0,0,0};
int a = 0;
int pin[]={2,4,12,13,14,15,27,32,33};
unsigned int t1 = 0;
unsigned int t2 = 0;
int error = 5;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup()
{
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  for (int j = 1; j <= 50; j++)
  { 
    for(int j=0;j<=9;j++)
    {
    x[j] = touchRead(pin[j]);
    } 
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
for(int j=0;j<=9;j++)
  {
  if(x[j]<=100)
    {
      Serial.print(pin[j]);
      Serial.println("conected");
    }
    else
    {
      Serial.print(pin[j]);
      Serial.println("Notconected");
    }
}
}
