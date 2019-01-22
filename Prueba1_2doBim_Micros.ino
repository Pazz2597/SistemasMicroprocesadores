#include <EEPROM.h>
#include <avr/wdt.h>
/*
 * Paul Zurita
 * Prueba micros 2do bimestre 
 */
int b1=8;
int b2=9;
int b3=10;
int d1,d2,d3;//digitos para saber la contrasena y el orden 
int st1=0;//estado para activar o desactivar master
int st2=0;//posicion de contrasena ingresada
int st3=0;//estado de intentos 
int tall=3; //intentos permitidos. 
int st4;//intentos restantes. 
int d;//variable que define el digito que se va a tomar en cuenta
int i=0;//probador de inicio de sisema 

String pass;//codigo del sistema
String passin;//codigo de entrada


void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);

 //EEPROM.update(0,1);EEPROM.update(1,2);EEPROM.update(2,3);

  attachInterrupt(0,master,FALLING);
  pass=String(EEPROM.read(0))+String(EEPROM.read(1))+String(EEPROM.read(2));

}

void loop() {
    if(i==0){
      Serial.println("inicio de sistema: "+pass);
      i=1;
    }
     if(digitalRead(b1)==HIGH){
      delay(300);
      d=1;
      codein(d);
      st2++;
     }
     if(digitalRead(b2)==HIGH){
      delay(300);
      d=2;
      codein(d);
      st2++;
     }
     if(digitalRead(b3)==HIGH){
      delay(300);
      d=3;
      codein(d);
      st2++;
     }

   if(st2==3){
    passin=String(EEPROM.read(3))+String(EEPROM.read(4))+String(EEPROM.read(5));
    
   }
   
 

}
void master(){
 
   st1=1-st1;
  if(st2==0){//deteccion de que los botones de codigo no han sido presionados
    if(st1==1){
      Serial.println("Activado");
    }else{
      Serial.println("Desactivado");
    }
  }else{
    comparator();
  }
}

///////////-----------------------------------
void reset(){
  
  Serial.println("Formateo de sistema");
  delay(200);
  Serial.println("Generando nuevo codigo");
  //generador de nuevo codigo con numeros del 1 al 3
  d1=random(1,4);
  d2=random(1,4);
  d3=random(1,4);
  //actualizar datos en la EEPROM
  EEPROM.update(0,d1);
  EEPROM.update(1,d2);
  EEPROM.update(2,d3);
  //impresion del nuevo codigo y comprobacion de que se ha guardado de manera correcta
  Serial.println("El nuevo Codigo es: "+String(EEPROM.read(0))+String(EEPROM.read(1))+String(EEPROM.read(2)));
  delay(500);
  st1=0;
  st2=0;
  st3=0;
  wdt_enable(WDTO_1S);
  
}
//------------------------------
//registro de contrasena
void codein(int digito){
  //ingreso de contrasena
  if(st2==0){
    EEPROM.update(3,digito);
    Serial.print("x ");
  }
  if(st2==1){
    EEPROM.update(4,digito);
    Serial.print("x ");
  }
  if(st2==2){
    EEPROM.update(5,digito);
    Serial.println("x");
  }
  
}
//------------------------------------
//comprobador de contrasena
void comparator(){
  if (passin.equals(pass)){
    Serial.println("Se puede encender el carro");
    st1=0;
    st2=0;
  }else{
    st3++;
    st4=tall-st3;
    if(st4!=0){
      st2=0;
    Serial.println("contrasena incorrecta, intentos restantes: "+String(st4));
    }else{
      reset();
    }
  }
}
