#include <MsTimer2.h>

#include <LiquidCrystal.h>

#include <avr/wdt.h>

LiquidCrystal lcd(13,12,11,10,9,8);//RS,E,D4,D5,D6,D7
int var;//variable de lector analogico
int st1=0;//variable para activacion del conteo regresivo de 10s
int st2=0;//variable para activacion del conteo regresivo de 20s
int st3=0;//variable para activacion del conteo regresivo de 30s
int st4=0;//variable para activacion del conteo regresivo de 40s
int secuence=0;
int maxT;//tiempo maximo 
//-------------------------------------
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
MsTimer2::set(200,countdown);
MsTimer2::start();
}
//--------------------------
void loop() {
    
    var=analogRead(0)*5/1023;
    if (var<1){
      st1=st2=st3=st4=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("sistema off");
      delay(200);
    }
    if(var==1 && st1==0){//activacion en 10 segundos
      st1=1;
      st2=0;
      st3=0;
      st4=0;
      maxT=9;
      secuence=0;
      lcd.setCursor(0,0);
      lcd.print("Activando en 10s ");
 
    }
    if(var==2 && st2==0){//activacion en 10 segundos
      st1=0;
      st2=1;
      st3=0;
      st4=0;
      maxT=19;
      secuence=0;
      lcd.setCursor(0,0);
      lcd.print("Activando en 20s ");

    }
    if(var==3 && st3==0){//activacion en 10 segundos
      st1=0;
      st2=0;
      st3=1;
      st4=0;
      maxT=29;
      secuence=0;
      lcd.setCursor(0,0);
      lcd.print("Activando en 30s ");

    }
    if(var==4 && st4==0){//activacion en 10 segundos
      st1=0;
      st2=0;
      st3=0;
      st4=1;
      maxT=39;
      secuence=0;
      lcd.setCursor(0,0);
      lcd.print("Activando en 40s ");
    }
}
//--------------
void countdown(){
  secuence++;
  if(maxT!=0){
    lcd.setCursor(0,1);
    lcd.print(secuence);
    if(secuence==maxT){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Reiniciando...");
  
      wdt_enable(WDTO_1S);
    }
  }
}
