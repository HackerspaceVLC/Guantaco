int x, y ;
int datos[5], datos2[5];
boolean configura=true;



void setup() {
  Serial.begin(9600);
   Mouse.begin();
  Keyboard.begin();
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
 
  Serial.println('espera un poquin bonico, configurando');
      
      for(x=0;x<=4;x++)
      {
      datos2[x]=analogRead(x);
      }
       delay(2500);
}


void loop() {
//  if(configura==true)
//    {
//      Serial.println('espera un poquin bonico, configurando');
//      
//      for(x=0;x<=4;x++)
//      {
//      datos2[x]=analogRead(x);
//      }
//      for(y=0;x<=500;x++)
//      {
//        for(x=0;x<=4;x++)
//        {
//        datos[x]=analogRead(x);
//        if(datos[x] != datos2[x])
//          {
//          datos2[x]= (datos[x]+datos2[x])/2;
//          }
//        }
//     }
//     configura=false;
//     
//  }   
      
   
    
  
  for(x=0;x<=4;x++)
  {
  datos[x]=analogRead(x);
  }
  if(datos[0]<(datos2[0]-100))
    {
      Mouse.move(0, -5); //parriba
      }
  
  if(datos[1]<(datos2[1]-100))
    {
      Mouse.move(0, 5); //pabajo
      }
   
   if(datos[2]<(datos2[2]-100))
    {
      Mouse.move(-5, 0); //izquierda
    }   
  
  if(datos[3]<(datos2[3]-100))
    {
      Mouse.move(5, 0);
      }
  
  if(datos[4]<(datos2[4]-100))
    {
      Mouse.click(MOUSE_LEFT);
      }
  
  
  for(int x=0;x<=4;x++)
  {
   Serial.print(x);
  Serial.println(datos[x]);
  
  }
delay(150);
}
