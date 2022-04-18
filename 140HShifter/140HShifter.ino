
//Declaracion de pines
int neutral = 0;
int gear1 = 1;
int gear2 = 2;
int gear3 = 3;
int gear4 = 4;
int gear5 = 5;
int gear6 = 6;
int gear7 = 7;
int gear8 = 8;
int forward = 9;
int reverse = 10;
int parking = 11;
int neutralRed = 12;

int uppBtn = 22;
int downBtn = 23;
int reverseBtn = 24;
int neutralBtn = 25;
int parkingBtn = 26;
int forwardBtn = 27;

int neutralPress= 0; //  antirrebote
int parkingPress= 0; //  antirrebote
int forwardPress= 0; //
int reversePress= 0; //
int uppPress = 0;   //Variable usada para el antirrebote del pulsador avanzar
int downPress = 0;  //Variable usada para el antirrebote del pulsador disminuir
int counter;      //Variable asociada a un contador

void setup() {

  //Declaracion de entradas/salidas digitales

  for (int i=0;i<=12;i++){
  pinMode(i, OUTPUT);
  }
  for (int i=22;i<=27;i++){
  pinMode(i, OUTPUT);
  }
  
  pinMode(uppBtn, INPUT);
  pinMode(downBtn, INPUT);

  digitalWrite(neutral,LOW);
  digitalWrite(neutralRed,LOW);
  digitalWrite(parking,HIGH);

}

void loop() {

if (digitalRead(neutralBtn) == HIGH){
    neutralPress = 1;
    delay(15);
 }
    if (digitalRead(neutralBtn) == LOW && neutralPress == 1){
      neutralPress=0;
      digitalWrite(parking,LOW);
      digitalWrite(neutral,HIGH);
      digitalWrite(neutralRed,HIGH);
      delay(100);
      digitalWrite(reverse,LOW);
      digitalWrite(forward,LOW);
        }
if (digitalRead(parkingBtn) == HIGH){
    parkingPress = 1;
    delay(15);
 }
    if (digitalRead(parkingBtn) == LOW && parkingPress == 1){
      parkingPress=0;
      digitalWrite(parking,HIGH);
      digitalWrite(neutral,LOW);
      digitalWrite(neutralRed,LOW);
        }

          if (digitalRead(forwardBtn) == HIGH){
            forwardPress = 1;
            delay(15);
             }
              if (digitalRead(forwardBtn) == LOW && forwardPress == 1){
                  forwardPress=0;
                  digitalWrite(neutral,LOW);
                  digitalWrite(neutralRed,LOW);
                  digitalWrite(forward,HIGH);
                   }
               if (digitalRead(reverseBtn) == HIGH){
            reversePress = 1;
            delay(15);
             }
              if (digitalRead(reverseBtn) == LOW && reversePress == 1){
                  reversePress=0;
                  digitalWrite(neutral,LOW);
                  digitalWrite(neutralRed,LOW);
                  digitalWrite(reverse,HIGH);
                   }
  //Secuencia para aumentar o avanzar

  if (digitalRead(uppBtn) == HIGH)
  {
    uppPress = 1;  //Cambia de estado si se presiona el pulsador
    delay(15);
  }
  if (digitalRead(uppBtn) == LOW && uppPress == 1)
  {
    uppPress = 0; //Se reinicia la variable del antirrebote
    counter++;     //El contador aumenta en una unidad
      if (counter > 8)
    {
      counter = 8;       
    }

  }

  //Secuencia para disminuir o retroceder

  if (digitalRead(downBtn) == HIGH)
  {
    downPress = 1;          //Cambia de estado si se presiona el pulsador
    delay(15);
  }
  if (digitalRead(downBtn) == LOW && downPress == 1)
  {
    downPress = 0;         //Se reinicia la variable del antirrebote
    counter--;             //El contador disminuye en una unidad

    if (counter < 1)
    {
      digitalWrite(forward,!digitalRead(forward));
      digitalWrite(reverse,!digitalRead(reverse));
      counter = 0;       
    }
  }


  switch (counter)
  {
    //Enciende los LEDs de acuerdo al contador
    case 0:    
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear1, LOW); 
      break;

    case 1:    
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear1, HIGH); //Enciende el LED 1 y apaga los demas
      break;

    case 2:   
      digitalWrite(gear1, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear2, HIGH); //Enciende el LED 2 y apaga los demas
      break;

    case 3:    
      digitalWrite(gear1, LOW);
      digitalWrite(gear2, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear3, HIGH); //Enciende el LED 3 y apaga los demas
      break;

    case 4:
      digitalWrite(gear1, LOW);
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear4, HIGH); //Enciende el LED 4 y apaga los demas
      break;

    case 5:     
      digitalWrite(gear1, LOW);
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear5, HIGH); //Enciende el LED 5 y apaga los demas
      break;
      
     case 6:     
      digitalWrite(gear1, LOW);
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear6, HIGH); //Enciende el LED 5 y apaga los demas
      break;  

      case 7:
      digitalWrite(gear1, LOW);
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear8, LOW);
      digitalWrite(gear7, HIGH); //Enciende el LED 5 y apaga los demas
      break; 

       case 8:
      digitalWrite(gear1, LOW);
      digitalWrite(gear2, LOW);
      digitalWrite(gear3, LOW);
      digitalWrite(gear4, LOW);
      digitalWrite(gear5, LOW);
      digitalWrite(gear6, LOW);
      digitalWrite(gear7, LOW);
      digitalWrite(gear8, HIGH); //Enciende el LED 5 y apaga los demas
      break;  
  }

}  
