/*
  Xbee_AT - Arduino Library for configuring XBee in AT Mode
 Created by Victor Boria and Marcos Martinez. 
 */

#include <XBee_AT.h>

uint16_t red = 0xDADA;   //ID de la red
char canal = 'C';        //Canal de la red
char baudrate = '3';     //9600
uint32_t DH = 0x13A200;  //Parte alta de la MAC del destinatario
uint32_t DL = 0x40762130;//Parte baja de la MAC del destinatario


void setup() {  
  Serial.begin(9600);

  XBee.entraConfig();
  delay(500);

  XBee.restauraConfig();
  delay(500);

  XBee.modoUnicast(DH, DL);
  delay(500);

  XBee.cambiaID(red); 
  delay(500);

  XBee.cambiaCanal(canal); 
  delay(500);

  XBee.cambioBD(baudrate);
  delay(500);

  XBee.guardaConfig();
  delay(500);

  XBee.salirConfig(); 
  delay(500);
}

void loop() {

  Serial.print("Hola");
  delay(500); 

}