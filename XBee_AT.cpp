/*
  Xbee_AT.cpp - Arduino Library for configuring XBee in AT Mode
  Created by Victor Boria and Marcos Martinez. 
*/

#include "XBee_AT.h" 


XBeeClass::XBeeClass() 
{	 	
}



void XBeeClass::entraConfig(){
   limpiaBuffer();
   Serial.print("+++");
   check(); 
}

void XBeeClass::restauraConfig(){
   limpiaBuffer();
   Serial.println("ATRE");
   check();   
}

void XBeeClass::cambiaID(uint16_t _red){
   limpiaBuffer();
   Serial.print("ATID"); 
   Serial.println(_red, HEX);  
   check();    
}

void XBeeClass::cambiaCanal(char _canal){
   limpiaBuffer();
   Serial.print("ATCH"); 
   Serial.println(_canal);
   check();    
}

void XBeeClass::guardaConfig(){
   desactivarReset();
   limpiaBuffer();
   Serial.println("ATWR");
   check();
}


void XBeeClass::salirConfig(){ 
   limpiaBuffer();
   Serial.println("ATCN");
   check();
}


void XBeeClass::modoBroadcast(){
   limpiaBuffer();
   Serial.println("ATDH0000");
   check();
   delay(100);  

   limpiaBuffer();
   Serial.println("ATDLFFFF");
   check();  
}

void XBeeClass::modoUnicast(uint32_t _high, uint32_t _low){
   limpiaBuffer();
   Serial.print("ATDH");
   Serial.println(_high, HEX);
   check();
   delay(100);


   limpiaBuffer();
   Serial.print("ATDL");
   Serial.println(_low, HEX);
   check();  
}

void XBeeClass::cambioBD(char _bd){
   limpiaBuffer();
   Serial.print("ATBD");
   Serial.println(_bd); 
   check();   
}


void XBeeClass::desactivarReset(){
   limpiaBuffer();
   Serial.println("ATD70");
   check();        
}

void XBeeClass::limpiaBuffer(){
  while( Serial.available() > 0) Serial.read();
}

void XBeeClass::check(){
   uint8_t x=0, answer=0;;
   char response[100];
   unsigned long previous;
   previous = millis();

   do{ 

      if(Serial.available() != 0){    

            // Leo la UART
         response[x] = Serial.read();
         x++;
         if (strstr(response, "OK") != NULL)
         {
            answer = 1;    
         }
      }
   }while((answer == 0) && ((millis() - previous) < 2000));   
}


XBeeClass XBee;