#include <XBee_AT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);


//CAMBIA ESTOS VALORES POR LOS TUYOS:
uint16_t red = 0x3332;    //ID de la red
char canal = 'C';         //Canal de la red
char baudrate = '3';      //9600
uint32_t DH = 0x13A200;   //Parte alta de la MAC del destinatario
uint32_t DL = 0x408BCE55; //Parte baja de la MAC del destinatario
char response_a1[17] = "Pantalla 1:     "; //Escribe 16 caracteres
char response_b1[17] = "Cambia el  texto"; //Escribe 16 caracteres
char response_a2[17] = "Pantalla 2:     "; //Escribe 16 caracteres
char response_b2[17] = "Segundo texto   "; //Escribe 16 caracteres


void setup() {    
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido a");
  lcd.setCursor(0, 1);
  lcd.print("Arduino Day Zgz");  
  delay(2000);
  
  XBee.entraConfig();
  delay(500);
   
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Configurando    ");
  lcd.setCursor(0, 1);
  lcd.print("XBee           ");

  XBee.restauraConfig();
  delay(500);
  
  //Mensaje que recibiran todos en mi misma ID de red
  //XBee.modoBroadcast(); 
  
  //Mensaje que solo recibira el XBee con esta MAC
  XBee. modoUnicast(DH, DL);
  delay(500);

  XBee.cambiaID(red); 
  delay(500);
  
  XBee.cambiaCanal(canal); 
  delay(500);
  
  XBee.cambioBD(baudrate);
  delay(500);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Saliendo de     ");
  lcd.setCursor(0, 1);
  lcd.print("de configuracion");
  
  XBee.guardaConfig();
  delay(500);
 
  XBee.salirConfig(); 
  delay(1000);
}

void loop() {
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(response_a1);
  lcd.setCursor(0, 1);
  lcd.print(response_b1);
  
  Serial.print(response_a1);
  Serial.println(response_b1);
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(response_a2);
  lcd.setCursor(0, 1);
  lcd.print(response_b2);
  
  Serial.print(response_a2);
  Serial.println(response_b2);
  delay(4000);
}






