/*
 * Escrito por Cristian Carreras
 * Programa para leer, escribir, borrar en la memoria eeprom
 * 
 * version v1.1
 */
 
#ifndef FUNCIONES_EEPROM_H
#define FUNCIONES_EEPROM_H

#include <EEPROM.h>
#include<Arduino.h>

void borrarEeprom(int i, int f);
String leerEeprom(int i, int f);
void grabarEeprom(int addr, String a, int f=50);

#endif