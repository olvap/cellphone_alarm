#include <SoftwareSerial.h>

#define RX 8
#define TX 9
#define LED 13
#define SENSOR 12

const char* cellphone_number = "543425091329";

SoftwareSerial mySerial(RX, TX);

void EnviaSMS(const char* message){
  mySerial.println("AT+CMGF=1");                 // Activamos la funcion de envio de SMS
  delay(100);
  mySerial.print("AT+CMGS=\"");
  mySerial.print(cellphone_number);              // Definimos el numero del destinatario en formato internacional
  mySerial.println("\"");
  delay(100);
  mySerial.print(message);
  delay(500);
  mySerial.print(char(26));                      // Enviamos el equivalente a Control+Z
  delay(100);
  mySerial.println("");
  delay(100);
}

void llamar(){
  digitalWrite(LED,0);
  mySerial.print("ATD+");   //Comando AT para realizar una llamada
  mySerial.print(cellphone_number);
  mySerial.println(";");
  delay(15000);
  mySerial.println("ATH");  // Cuelga la llamada
  delay(60000);
  digitalWrite(LED,1);
}

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
  digitalWrite(LED,0);
  mySerial.begin(9600);
  delay(10000);
  digitalWrite( LED,1);
}

void loop(){
  if(digitalRead(SENSOR) == LOW){
    llamar();
  }
}
