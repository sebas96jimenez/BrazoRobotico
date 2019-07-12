#include <Servo.h>
#include <SoftwareSerial.h>

#define motorBase 12//Declaro el pin de la base
#define motorDerecho 11 //Declaro el pin del motor derecho
#define motorIzquierdo 10 // Declaro el pin de la izquierda
#define motorMano 9// Declaro el pin de la mano

Servo Base; //Declaro el servomotor de la base
Servo Derecho; //Declaro servomotor derecha
Servo Izquierdo;// Declaro el servomotor Izquierda
Servo Mano;//Declaro el servomotor de la mano
SoftwareSerial BT(2,3);

int angulo;
char motor;
int PosBase;
int PosDerecho;
int PosIzquierdo;
int PosMano;


void anguloBT(){
  if(BT.available()>0){
    motor =BT.read();
    angulo = BT.parseInt();
  }
}

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Derecho.attach(motorDerecho);//Inicializamos el servo
  Izquierdo.attach(motorIzquierdo);
  Base.attach(motorBase);
  Mano.attach(motorMano);  
  Mano.write(0);
  

 

}

void loop() {
  anguloBT();
  switch (motor){
    case 'B':
    if (angulo>=0 && angulo<=180){
      PosBase = angulo;
      Base.write(PosBase);
      break;
    }
    case 'D':
    if (angulo>=0 && angulo<=180){
      PosDerecho = angulo;
      Derecho.write(PosDerecho);
      break;
    }
     case 'I':
    if (angulo>=0 && angulo<=180){
      PosIzquierdo = angulo;
      Izquierdo.write(PosIzquierdo);
      break;
    }
     case 'M':
    if (angulo==20){
      PosMano = angulo;
      Mano.write(PosMano);
      break;
    }
    else{
      PosMano = angulo;
      Mano.write(PosMano);
      break;
    }
     case 'Z':
    if (angulo==1){  
     Pos_Inicial ();
 Pos_Medio ();
 Pos_Final ();
  }
  if (angulo==2){
    break;
  }
  }
}

void Pos_Inicial (){
  Base.write(0);
  Derecho.write(0);
  Mano.write(0);
  Izquierdo.write(0);
}

void Pos_Medio(){
  for(int i=0;i<=90;i++){
      Base.write(i);
      delay(20);
    }
for(int i=0;i<=105;i++){
      Izquierdo.write(i);
      delay(20);
    }
  for(int i=0;i<=45;i++){
      Derecho.write(i);
      delay(20);
}

    for(int i=0;i<=20;i++){
      Mano.write(i);
      delay(70);
    }
}
 
void Pos_Final (){
  for(int i=45;i<=80;i++){
      Izquierdo.write(i);
      delay(20);
}
  for(int i=90;i<=180;i++){
      Base.write(i);
      delay(20);
    }
  for(int i=20;i>=0;i--){
      Mano.write(i);
      delay(70);
    }
   
  

 }
