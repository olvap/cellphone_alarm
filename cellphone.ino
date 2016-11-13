#include <SoftwareSerial.h>    // Incluimos la libreria SoftwareSerial
SoftwareSerial mySerial(8, 9); // Declaramos los pines RX(8) y TX(9) que vamos a usar

void loop(){
  int buttonState = 0;
  buttonState = digitalRead(12);

  if(buttonState == LOW)
  {
    llamar();
  }
/*if (mySerial.available()){          // Si la comunicacion SoftwareSerial tiene datos
  Serial.write(mySerial.read());    // Los sacamos por la comunicacion serie normal
} 
  */
/*if (Serial.available()){            // Si la comunicacion serie normal tiene datos
  while(Serial.available()) {       // y mientras tenga datos que mostrar 
    mySerial.write(Serial.read());  // Los sacamos por la comunicacion SoftwareSerial
  } 
  mySerial.println();               // Enviamos un fin de linea

}*/
}

// Funcion para el envio de un SMS
void EnviaSMS(){              
 mySerial.println("AT+CMGF=1");                 // Activamos la funcion de envio de SMS
 delay(100);                                    // Pequeña pausa
 mySerial.println("AT+CMGS=\"+543425091329\"");  // Definimos el numero del destinatario en formato internacional
 delay(100);                                    // Pequeña pausa
 mySerial.print("Hola Mundo!");                 // Definimos el cuerpo del mensaje
 delay(500);                                    // Pequeña pausa
 mySerial.print(char(26));                      // Enviamos el equivalente a Control+Z 
 delay(100);                                    // Pequeña pausa
 mySerial.println("");                          // Enviamos un fin de linea
 delay(100);                                    // Pequeña pausa
}

void llamar()
{
//  Serial.println("Realizando llamada...");
  digitalWrite(13,0);
  mySerial.println("ATD+543425091329;");  //Comando AT para realizar una llamada
  delay(15000);  // Espera 30 segundos mientras realiza la llamada
  mySerial.println("ATH");  // Cuelga la llamada
  delay(60000);
  digitalWrite(13,1);
//  Serial.println("Llamada finalizada");
}

void setup(){
pinMode(13, OUTPUT);
pinMode(12, INPUT);
digitalWrite(13,0);
//Serial.begin(9600);       // Iniciamos la comunicacion serie
mySerial.begin(9600);     // Iniciamos una segunda comunicacion serie
delay(10000);              // Pausa de 1 segundo
digitalWrite( 13,1);


//llamar();
//EnviaSMS();               // Llamada a la funcion que envia el SMS
}
