int touch[] = {2 , 15, 4 , 13 , 12 , 14, 27 , 32,33};
int data[] = {0, 0, 0, 0, 0, 0, 0, 0,0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i <= 9; i++)
  {
    data[i] = touchRead(touch[i]);
   
    Serial.print(data[i]);// put your main code here, to run repeatedly:
    Serial.println(',');
  }

}
