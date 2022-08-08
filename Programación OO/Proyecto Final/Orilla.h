/*
  Archivo: Orilla.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-08
  Licencia: GNU-GPL
*/

/**
  CLASE: Orilla
  INTENCIÓN: La orilla determina tanto un punto de partida como uno de llegada. Guarda un 
  registro de los individuos que se encuentran en sí misma.
  RELACIONES:
  - Es un Lugar.
  - Conoce a Individuo. (Comportamiento heredado)
*/

#ifndef ORILLA_H
#define ORILLA_H

// Librerías.

// Clases.
#include "Lugar.h"

class Orilla: public Lugar
{
  private:

  public:
  /**
  Constructor; da valores iniciales a los atributos internos.
  */
  Orilla(vector<Individuo *> personajes);
  /**
  Destructor; no hace nada.
  */
  virtual ~Orilla();
};

#else
class Orilla; // Declaración adelantada.
#endif