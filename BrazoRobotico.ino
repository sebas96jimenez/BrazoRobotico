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

void setup() {
  Serial.begin(9600);
  Derecho.attach(motorDerecho);//Inicializamos el servo
  Izquierdo.attach(motorIzquierdo);
  Base.attach(motorBase);
  Mano.attach(motorMano);  
  int B=0,D=0,M=0,I=0,i=0;
  /*Base.write(B);
  Derecho.write(D);
  Mano.write(M);
  Izquierdo.write(I);*/

 /* if(B!=90){
    for(i=0;i<=90;i++){
      Base.write(i);
      delay(20);
    }
  }
  if(M!=13){
    for(i=0;i<=13;i++){
      Mano.write(i);
      delay(10);
    }
}
  if(D!=40){
    for(i=0;i<=40;i++){
      Derecho.write(i);
      delay(20);
    }
}
    if(I!=80){
    for(i=0;i<=80;i++){
      Izquierdo.write(i);
      delay(20);
    }
}


 if(M==13){
    for(i=13;i>=0;i--){
      Mano.write(i);
      delay(10);
    }
}
 if(I==80){
    for(i=80;i<=20;i--){
      Izquierdo.write(i);
      delay(20);
    }
}
 if(B==90){
    for(i=90;i<=180;i++){
      Base.write(i);
      delay(20);
    }
  }*/
  Pos_Inicial ();
 Pos_Medio ();
 Pos_Final ();
}

void loop() {
 

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
      delay(40);
    }
}
 
void Pos_Final (){
  for(int i=90;i<=180;i++){
      Base.write(i);
      delay(20);
    }
  for(int i=20;i>=0;i--){
      Mano.write(i);
      delay(10);
    }
  

 }
   
