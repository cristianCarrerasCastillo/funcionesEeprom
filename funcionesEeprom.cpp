/*
 * Escrito por Cristian Carreras
 * Programa para leer, escribir, borrar en la memoria eeprom
 * 
 * version v1.5.5
 */

 #include <EEPROM.h>
 #include<Arduino.h>

 /*!
  * \brief Funcion para borrar un largo de memoria
  * \param i Direccion de memoria inicial a borrar
  * \param f Direccion de memoria final a borrar
  */

void borrarEeprom(int i, int f){
  for (int j=i;j<f;j++) {
    EEPROM.write(j, 255);
    }
    Serial.print("------------ Memoria");
    Serial.print(i);
    Serial.print("-");
    Serial.print(f);
    Serial.println(" borrada------------");
    delay(500);
    EEPROM.commit();
}

/*!
 * \brief Funcion para leer un largo de memoria
 * \param i Direccion de memoria inicial a leer
 * \param f Direccion de memoria final a leer
 * \return Retorna un string con los datos leidos
 */
String leerEeprom(int i, int f){
  byte lectura;
  String strlectura;
   for (int j=i;j<f;j++) {
    lectura = EEPROM.read(j);
    if(lectura!=255){
      strlectura = strlectura + (char)lectura;
      }
    }
    Serial.println(strlectura);
    return strlectura;
}

/*!
 * \brief Funcion para escribir un dato en la memoria y rellenar con 255 el espacio restante
 * \param i Direccion de memoria inicial a escribir
 * \param f Direccion de memoria final a escribir, por defecto es 50
 * \param dato String con los datos a escribir
 */
void grabarEeprom(int addr, String a, int f){
  int tamano = a.length();
  char inchar[f];
  a.toCharArray(inchar, tamano + 1);
  for (int i = 0; i < tamano; i++) {
    EEPROM.write(addr + i, inchar[i]);
  }
  for (int i = tamano; i < f; i++) {
    EEPROM.write(addr + i, 255);
  }
  EEPROM.commit();
}

