/*
 * UTN/FICA-CIERCOM/SISTEMAS MICROPROCESADOS
 * PAUL ZURITA
 * 
 * Estimados estudiantes realizar un sistema que permite determinar el número de vocales dentro de una palabra
 * 
 */
//DECLARACION DE VARIABLES 
int i=0;//variable de recorrido 1
int j=0; //variable de suma de vocales 
int vecl=0; //tamano del vector



String dato; //variable para la palabra
void setup() {
  //habilitar cx serial
  Serial.begin(9600);
  
}

void loop() {

  //leer string

  if(Serial.available()>0){
    dato=Serial.readString();

    //transformacion a minusculas para facilitar lectura
    dato.toLowerCase();

    //Definicion del tamano del vector de letras para el limite del ciclo for
    vecl=dato.length();
    
    
    for(;i<vecl;i++){//for que recorre el string posicion a posicion
      
      //comparacion de letras  
     if (dato.charAt(i)=='a' || dato.charAt(i)=='e' 
          || dato.charAt(i)=='i' || dato.charAt(i)=='o' 
          || dato.charAt(i)=='u'){
          j=j+1;  //suma el numero de vocales segun recorre el strign   
        }
    }
    //impresion de total de vocales 
    Serial.println(j);
    //RESET DE VARIABLES DE CONTEO
    i=0;
    j=0;
    
  }
  

}

       
