int t1=0;
int t=0;
int x=0;
int x1=0;
void setup() {
 Serial.begin(115200);// put your setup code here, to run once:
 
}

void loop() {
  for (int i = 0; i < 100; i++)
  {
    t = t + touchRead(4);

  }
    t =t /100;
  
    Serial.println(touchRead(4));
    Serial.println(',');
    Serial.println(touchRead(14));
//    x=touchRead(4);
//    if(t<=x/2)
//    {
//      Serial.print("True");
//    }
//    else
//    {
//      Serial.print("None");
//      
//    }
}
