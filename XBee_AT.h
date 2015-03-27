/*
  Xbee_AT.h - Arduino Library for configuring XBee in AT Mode
  Created by Victor Boria and Marcos Martinez. 
*/ 

#ifndef XBee_AT_h
#define	XBee_AT_h

#include "Arduino.h"


class XBeeClass  
{
  public:
    XBeeClass();

    void entraConfig();
    void restauraConfig();
    void cambiaID(uint16_t _red);
    void cambiaCanal(char _canal);
    void guardaConfig();
    void salirConfig();
    void modoBroadcast();
    void modoUnicast(uint32_t _high, uint32_t _low);
    void cambioBD(char _bd);

  private:

    void desactivarReset();
    void limpiaBuffer();
    void check();
}; 

  extern XBeeClass XBee;
#endif
