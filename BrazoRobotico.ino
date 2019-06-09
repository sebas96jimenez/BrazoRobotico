
#include <Servo.h>
#define motorBase 12//Pin de la base
#define motorDerecho 11 //Pin del motor derecho
#define motorIzquierdo 10 //Pin de la izquierda
#define motorMano 9//Pin de la mano
Servo Base; //Servomotor de la base
Servo Derecho; //Servomotor derecha
Servo Izquierdo;//Servomotor Izquierda
Servo Mano;//Servomotor de la mano
void setup() {
  // put your setup code here, to run once:
 // Serial.begin(9600);

  Derecho.attach(motorDerecho);//Inicializamos el servo
  Izquierdo.attach(motorIzquierdo);
   Base.attach(motorBase);
   Mano.attach(motorMano);
 
  Base.write(90);
   delay(1000);
   Base.write(180);
  delay(1000);
   Base.write(0);
   delay(1000);
   
   Mano.write(0);
   delay(5000);

   Mano.write(0);
   delay(1000);

   Derecho.write(180);
  delay(1000);
   Derecho.write(120);
  delay(1000);
   Derecho.write(100);
   delay(1000);


   Izquierdo.write(0);
   delay(1000);
   Izquierdo.write(0);
  delay(1000);
   Izquierdo.write(0);
   delay(1000);
   


  
}

void loop() {
  // put your main code here, to run repeatedly:
   
    }
