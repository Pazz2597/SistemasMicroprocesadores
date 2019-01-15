#include <EEPROM.h>
int in,alin;//in es de ingreso y al in already in
String varin;
void setup() {
 Serial.begin(9600);
 Serial.println("Ingrese una variable tipo entero");
 EEPROM.update(0,0);
}

void loop() {
  if(Serial.available()>0){
    alin=EEPROM.read(0);
    varin=Serial.readString();
    in=varin.toInt();
    if(alin<in){
      EEPROM.update(0,in);
      Serial.println("Datos actualizados");
    }else{
      Serial.println("La variable ingresada no supera a la variable almacenada actualmente\ro no es de tipo entero");
    }
  }

}
