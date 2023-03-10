#include <Servo.h>
//CONTROL DE SERVOMOTORES
int pinScuello = 13;
int pinSBderecho = 12;
int pinSBizquierdo = 11;
int pinStorso = 10;
int cambioMovimiento = 2;
Servo Scuello;
Servo SBderecho;
Servo SBizquierdo;
Servo Storso;
//CONTROL DE LOS MOTORES
int pinMotor1A = 2;
int pinMotor1B = 3;
int pinMotor2A = 9;
int pinMotor2B = 8;
//variable de entrada por bluetooth
char val;
//valores inciales
int posicionCuello = 90;
int posicionBrazoD = 90;
int posicionBrazoI = 90;
int posicionTorso = 90;

void setup() {
  //Desiganmos los pines de uso
  Scuello.attach(pinScuello);
  SBderecho.attach(pinSBderecho);
  SBizquierdo.attach(pinSBizquierdo);
  Storso.attach(pinStorso);
  
  pinMode(pinMotor1A, OUTPUT);  
  pinMode(pinMotor1B, OUTPUT);  
  pinMode(pinMotor2A, OUTPUT);  
  pinMode(pinMotor2B, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  
  val = Serial.read();
  Serial.println(val);
  
    //cabeza
    
  if(val == '-')
    {
      posicionCuello -= cambioMovimiento;
      Scuello.write(posicionCuello);      
    }
  if(val == '+')
    {
      posicionCuello += cambioMovimiento;
      Scuello.write(posicionCuello);       
    }

    //brazo derecho
    
  if(val == 'T')
    {
      posicionBrazoD -= cambioMovimiento;
      SBderecho.write(posicionBrazoD);      
    }
  if(val == 'G')
    {
      posicionBrazoD += cambioMovimiento;
      SBderecho.write(posicionBrazoD);      
    }
    
    //brazo izquierdo
    
  if(val == 'R')
    {
      posicionBrazoI += cambioMovimiento;
      SBizquierdo.write(posicionBrazoI);      
    }
  if(val == 'F')
    {
      posicionBrazoI -= cambioMovimiento;
      SBizquierdo.write(posicionBrazoI);      
    }
    
    //torso
    
  if(val == 'Q')
    {
      posicionTorso -= cambioMovimiento;
      Storso.write(posicionTorso);      
    }
  if(val == 'E')
    {
      posicionTorso += cambioMovimiento;
      Storso.write(posicionTorso);      
    }  
    
    //FUNCIONAMIENTO DEL MOTOR
    
  if( val == 'W')               //adelante
    {
      digitalWrite(pinMotor1A, HIGH);
      digitalWrite(pinMotor1B, LOW);
      digitalWrite(pinMotor2A, HIGH);
      digitalWrite(pinMotor2B, LOW);  
    }
  else if(val == 'S')           // Hacia atras
    {
      digitalWrite(pinMotor1A, LOW);
      digitalWrite(pinMotor1B, HIGH);
      digitalWrite(pinMotor2A, LOW);
      digitalWrite(pinMotor2B, HIGH); 
    }
  
  else if(val == 'A')           // Izquierda 
    {
    digitalWrite(pinMotor1A, LOW);
    digitalWrite(pinMotor1B, LOW);
    digitalWrite(pinMotor2A, HIGH);
    digitalWrite(pinMotor2B, LOW);
    }
  else if(val == 'D')           //Derecha
    {
    digitalWrite(pinMotor1A, HIGH);
    digitalWrite(pinMotor1B, LOW);
    digitalWrite(pinMotor2A, LOW);
    digitalWrite(pinMotor2B, LOW); 
    }
  else if(val == 'O')           //STOP
    {
    digitalWrite(pinMotor1A, LOW);
    digitalWrite(pinMotor1B, LOW);
    digitalWrite(pinMotor2A, LOW);
    digitalWrite(pinMotor2B, LOW); 
    }
}
