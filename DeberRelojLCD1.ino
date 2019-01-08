#include <MsTimer2.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);//RS,E,D4,D5,D6,D7
int seconds=00;//segundos
int minutes=00;//minutos
int hours=00;//horas

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
MsTimer2::set(50,contando);
MsTimer2::start();
}

void loop() {
lcd.setCursor(0,0);
lcd.print("HH:MM:SS");
 
  //reinicio de segundos
  if(seconds==60){
    seconds=0;
    lcd.clear();
    minutes++;
  }
  if(minutes==60){
    minutes=0;
    hours++;
    lcd.clear();
  }
  if(hours==24){
    hours=0;
    lcd.clear();
  }
 lcd.setCursor(0,1);
 lcd.print(String(hours)+':'+String(minutes)+':'+String(seconds));
 

}
void contando() {
  seconds++;
}
