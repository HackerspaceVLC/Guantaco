void setup() {
  Serial.begin(9600);
  
}

int datos[5];
void loop() {
  // put your main code here, to run repeatedly:
  for(int x=0;x<=4;x++)
  {
  datos[x]=analogRead(x);
 
  }
  
  for(int x=0;x<=4;x++)
  {
   Serial.print(x);
  Serial.println(datos[x]);
  
  }
delay(666);
}
