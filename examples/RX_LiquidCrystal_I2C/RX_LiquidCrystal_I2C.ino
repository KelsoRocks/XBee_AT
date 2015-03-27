#include <XBee_AT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20(Cooperate with 3 short circuit caps) for a 16 chars and 2 line display

//CAMBIA ESTOS VALORES POR LOS TUYOS:
uint16_t red = 0x3332;    //ID de la red
char canal = 'C';         //Canal de la red
char baudrate = '3';      //9600

char response_a[20];
char response_b[20];


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
  delay(500);
  
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Esperando      ");
  lcd.setCursor(0, 1);
  lcd.print("mensajes...    ");
  
  while(Serial.available()>0){Serial.read();}
}

void loop() {
  if(Serial.available() > 32){
    for(int i;i<16;i++){
      response_a[i] = Serial.read();
    }
    for(int i;i<16;i++){
      response_b[i] = Serial.read();
    }
    while (Serial.available() > 0)
    {
      Serial.read();
    }
  }
  
  lcd.setCursor(0, 0);
  lcd.print(response_a);
  lcd.setCursor(0, 1);
  lcd.print(response_b);
}










