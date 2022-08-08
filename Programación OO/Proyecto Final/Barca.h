/*
  Archivo: Barca.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-07
  Licencia: GNU-GPL
*/

/**
  CLASE: Barca
  INTENCIÓN: Se encarga de transportar los individuos de una orilla a otra.
  RELACIONES:
  - Es un Lugar.
  - Conoce a Individuo. (Comportamiento heredado)
*/

#ifndef BARCA_H
#define BARCA_H

// Librerías.

// Clases.
#include "Lugar.h"

using namespace std;

class Barca: public Lugar
{
  private:

  public:
  /**
  Constructor; da valores iniciales a los atributos internos.
  */
  Barca(vector<Individuo *> personajes);
  /**
  Destructor; no hace nada.
  */
  virtual ~Barca();
  /**
  aforoCompleto: Retorna un bool que indica si ya está lleno el lugar (Personalizado para 2).
  */
  virtual bool aforoConEspacio();
  /**
  conductor_a_bordo: Retorna un bool que indica si el conductor está en la barca, de modo que se pueda zarpar.
  */
  virtual bool conductor_a_bordo();
};

#else
class Barca; // Declaración adelantada.
#endif