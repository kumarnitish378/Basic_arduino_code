int pin[] ={PB15, PA8, PB1, PB10, PB11, PB14, PB13};

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(PB15, OUTPUT);
  pinMode(PA8, OUTPUT);
  pinMode(PB1,OUTPUT );
  pinMode(PB10, OUTPUT);
  pinMode(PB11, OUTPUT);
  pinMode(PB14, OUTPUT);
  pinMode(PB13, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
    digitalWrite(PB15, HIGH);
    digitalWrite(PA8, HIGH);
    digitalWrite(PB10, HIGH);
    digitalWrite(PB11, HIGH);
    digitalWrite(PB14,HIGH);
    digitalWrite(PB13, HIGH);
}
