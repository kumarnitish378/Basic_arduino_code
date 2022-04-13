
void setup()
{
Serial. begin(115200); //initiates serial monitor.
pinMode(4, INPUT);
Serial. println("Distance sensor test");
Serial. println(',');
}
void loop()
{
  Serial.println(digitalRead(4));
}
