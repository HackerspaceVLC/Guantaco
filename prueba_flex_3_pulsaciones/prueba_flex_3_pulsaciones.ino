int x, y ;
int datos[5], datos2[5];
int configura=1;
int flexos, flexos_ant;
int TIEMPO_PARA_GESTO=25;
unsigned long tiempo, tiempo_anterior;


void setup() {
  Serial.begin(9600);
   Mouse.begin();
  Keyboard.begin();
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
 
  Serial.println("espera un poquin bonico, configurando");
      
      for(x=0;x<=4;x++)
      {
      datos2[x]=analogRead(x);
      }
       delay(2500); // saco la base a las malas.
}

void mide_gesto(void)
  {
    for(x=0;x<=4;x++)
      {
      datos[x]=analogRead(x);
      if(datos[x]<(datos2[x]-175))
        {
        bitSet(flexos, x);
        }
      else
        {
        bitClear(flexos, x);
        }
      }
      Serial.println(flexos);
      
    switch (flexos)
      {
        case 1: //doble click
            Mouse.click(MOUSE_LEFT);
            //delay(100);
            Mouse.click(MOUSE_LEFT);
            break;
        
        case 2:  //click izq
            Mouse.click(MOUSE_LEFT);
            break;
        
        case 4:
            Mouse.click(MOUSE_RIGHT);
            break;
            
        case 6:
            Mouse.click(MOUSE_MIDDLE);
            break;
            
        case 24:
            Keyboard.press(214); //re pag
            //delay(50);
            Keyboard.releaseAll(); 
           break;   
        
        case 25:
            Keyboard.press(211); //av pag
            //delay(50);
            Keyboard.releaseAll();
            break;
           
        case 27:
            Keyboard.press(128); //ctrl
            Keyboard.press(130); //alt   
            Keyboard.press(212); //del 
            //delay(50);
            Keyboard.releaseAll();
            break;
        
        case 28:
            Keyboard.press(130); // alt
            Keyboard.press(179); // tab
            //delay(50);
            Keyboard.releaseAll();
            break;
        
        case 31:
            Keyboard.press(130); //alt
            Keyboard.press(197); //f4
            //delay(50);
            Keyboard.releaseAll();
            
            
            
           
        default:
        break;    
      }
      
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
      
      
tiempo=millis();
if((tiempo-tiempo_anterior)>500)
  {
   mide_gesto();
   tiempo_anterior=tiempo;
  }
 
  
  for(int x=0;x<=4;x++)
  {
   Serial.print(x);
  Serial.println(datos[x]);
  
  }
delay(250);
}
