/*
 * Universidad Tecnica del Norte
 * FICA - CIERCOM
 * SISTEMAS MICROPROCESADOS
 * PAUL ZURITA
 * 
 * REALIZAR UN CONTADOR HASTA 40 QUE AUMENTE CON UN PULSADOR Y RESTE CON OTRO
 */
 //DECLARACION DE VARIABLES

int A=5; //DELCARACION BIT MENOS SIGNIFICATIVO
int B=4;
int C=3;
int D=2;//DECLARACION BIT MAS SIGNIFICATIVO

int r=0;// DECLARACION VARIABLE DE RECORRIDO EMPIEZA DESDE 1
int uni=8;// DECLARACION FUENTE UNIDADES
int dec=9;// DECLARACION FUENTE DECENAS
int res=11;//pulsador restador
int sum=1;//pulsador sumador

int d,u; // DECLARACION VARIABLES TEMPORALES 



void setup() {

  //DECLARACION PINES COMO SALIDA
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(uni, OUTPUT);
  pinMode(dec, OUTPUT);
  pinMode(res, INPUT); 
  pinMode(sum, INPUT); 
 delay(200); //espera 200 ms
}

void loop() {
  
  //condicional para sumar
 if(digitalRead(sum)==HIGH){
  delay(200);//eliminador de rebotes
  //inicio if para contar 
  if (r<40){
    r++;
        //con el operador modulo(%) ubicamos el contador para decenas, unidades
        d=(r%100)/10; //valor de las decenas
        u=r%10; //valor de las unidades
        
  }else{
    //reseteo de valores
    r=0;
  
    d=0;
    u=0;
    
  }
 }
   
 
 //condicional para restar
if(digitalRead(res)==HIGH){
  delay(200);//eliminador de rebotes
  
  //inicio if para contar 
  if (r>0){
    r--;
        //con el operador modulo(%) ubicamos el contador para decenas, unidades
        d=(r%100)/10; //valor de las decenas
        u=r%10; //valor de las unidades
        
  }else{
    //reseteo de valores desde 40 
    r=40;
  //inicio desde 40 
    d=4;
    u=0;
    
  }
 }
  //IMPRESION DE NUMEROS EN DISPLAY
    //impresion unidades
    digitalWrite(uni, HIGH);//display unidades on
    digitalWrite(dec, LOW);// display decenas off
    printNum(u);//llamada a metodo de visualizacion
    delay(200);//espera

    //impresion decenas
    digitalWrite(uni, LOW);//display unidades off
    digitalWrite(dec, HIGH);// display decenas on
    printNum(d);//llamada a metodo de visualizacion
    delay(200);//espera
        
  
     
}
void printNum ( int numSelec){
switch (numSelec){

//print 0
case 0:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//print 1
 case 1:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//print 2
case 2:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//print 3
case 3:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//print 4
case 4:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//print 5
case 5:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//print 6
case 6:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//print 7
case 7:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
// print 8
case 8:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//print 9
case 9:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
}
