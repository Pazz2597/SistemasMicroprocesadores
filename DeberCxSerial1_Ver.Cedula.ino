/*
 * UTN/FICA-CIERCOM/SISTEMAS MICROPROCESADOS
 * PAUL ZURITA
 * 
 * Realizar un sistemas de validacion de cedula y que quite el guion de la misma
 * 
 */
 #include<stdlib.h> //librerias de conversion en c
 //DECLARACION DE VARIABLES 
 int cedl; //tamano de la cedula

 String ced1; //lector de cedula 
 String ced2; //cedula sin guion 

 String d1, d2, d3, d4, d5, d6 ,d7, d8, d9, dg, d10,pd;//datos individuales
 int di1,di2,di3,di4,di5,di6,di7,di8,di9,df,op1,op2,op3,op4,op5,op6;//digitos en enteros

void setup() {
  Serial.begin(9600);  //inicio de cx serial
  

}

void loop() {
 //lectura de cedula 
 if(Serial.available()>0){
      ced1=Serial.readString();
        cedl = ced1.length();//tamano de la cedula
            if(cedl==11){//FOR COMPROBADOR DE LONGITUD DE CEDULA
          char ced3[cedl];// variable cedula en array
        
              //cedula en array
             ced1.toCharArray(ced3, cedl+1);
             //reconstruccion del nuevo vector 
              d1=ced3[0];                  d2=ced3[1];
              d3=ced3[2];                  d4=ced3[3];
              d5=ced3[4];                  d6=ced3[5];
              d7=ced3[6];                  d8=ced3[7];
              d9=ced3[8];                  d10=ced3[10];

      ced2 =d1+d2+d3+d4+d5+d6+d7+d8+d9+d10;
      Serial.println("\rCedula ingresada al sistema: " + ced2 +"\rValidando...");
      delay(200);
      //transformacion de variables a enteros 
        di1=d1.toInt();     di2=d2.toInt();
        di3=d3.toInt();     di4=d4.toInt();
        di5=d5.toInt();     di6=d6.toInt();
        di7=d7.toInt();     di8=d8.toInt();
        di9=d9.toInt();     df=d10.toInt();
      //suma de los numeros pares
      op1= di2+di4+di6+di8;

      //Comienzo de validaciones 
      pd= d1+d2;//creo arreglo de 2 primeros digitos
      op2=pd.toInt();//transformo a int los 2 primeros digitos
  
      //si esta dentro de las 24 provincias o son registrados en el exterior(por eso es el 30)
      if((op2>0 && op2<=24)||op2==30){
        //validacion del tercer digito con rango de 0 a 5
        if((di3>=0) && (di3<6)){
          //a multiplicar por 2 los numeros impares para validar el ultimo digito
            di1=di1*2; 
            di3=di3*2; 
            di5=di5*2;  
            di7=di7*2;  
            di9=di9*2; 
          //verificar que los numeros sean menores a 9 
            if(di1>9){//digito1
            di1=di1-9;
          }
          if(di3>9){//digito3
            di3=di3-9;
          }
            if(di5>9){//digito5
            di5=di5-9;
            }
          if(di7>9){//digito7
            di7=di7-9;
          }
            if(di9>9){//digito9
            di9=di9-9;
            }
           //sumatoria numeros impares
            op3=di1+di3+di5+di7+di9;
           //sumatoria de sumatorias pares e impares
            op4=op1+op3;
            //obtenemos el modulo de la ultima sumatoria(op4)
            op5=op4%10;
            //restamos el modulo de 10
            op6=10-op5;
            //comprobacion final del digito verificador
            if(op6==df){
              Serial.println("La cedula ingresada es correcta");
            }else{Serial.println("Cedula no valida, error FC");}
          
        }else{Serial.println("Cedula no valida, error 2C");}//fin segunda condicion
        
      }else{Serial.println("Cedula no valida, error 1C");}//fin primera condicion
               }else{Serial.println("Cedula no valida");}//fin validacion tamano cedula

             //100319730-6  
        
        }//final de serial.avialable
       
  
 }//final
