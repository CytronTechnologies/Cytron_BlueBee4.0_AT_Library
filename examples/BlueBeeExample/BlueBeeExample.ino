void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    String s="";
    while(Serial.available())
    {
      s+=(char)Serial.read();
      delay(5);
    }
    Serial.print("From BlueBee4.0: ");
    Serial.print(s);
    Serial.println();
  }
}
