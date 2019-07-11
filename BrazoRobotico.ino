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
int angulo =0,B=0,D=0,I=0,M=0;
char motor;
void setup() {
  Serial.begin(9600);
  Derecho.attach(motorDerecho);//Inicializamos el servo
  Izquierdo.attach(motorIzquierdo);
  Base.attach(motorBase);
  Mano.attach(motorMano);  

}


void loop() {
//  Inicial();
  Leer_Dato();
  switch (motor){
    case 'B':
    B=angulo;
    break;
    case 'M':
    M=angulo;
    break;
    case 'D':
    D=angulo;
    break;
    case 'I':
    I=angulo;
    break;
  }
  Base.write(B);
  Mano.write(M);
  Derecho.write(D);
  Izquierdo.write(I);
  delay(15);
  }
  void Leer_Dato(){
    if(Serial.available()>0){
      motor =Serial.read();
      angulo=Serial.parseInt();
    }
  }
  /*void Inicial(){
    int B=(0);
    M=(20);
    D=(70);
    I=(70);
    
  }*/
   
