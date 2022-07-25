/*
  Archivo: JefeDeEstacion.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-23-07
  Fecha última modificación: 2022-23-07
  Licencia: GNU-GPL
*/

/**
  CLASE: JefeDeEstacion
  INTENCIÓN: Da órdenes a las vías para organizar el tren colocando los vagones contagiados al final.
  RELACIONES: Conoce las vías.
*/

#ifndef JEFEDEESTACION_H
#define JEFEDEESTACION_H

#include "Via.h"
#include <iostream>

using namespace std;

class JefeDeEstacion
{
private:
  Via *viaPrincipal = nullptr;
  Via *ramalIzquierdo = nullptr;
  Via *ramalDerecho = nullptr;

public:
  /**
  Constructor. Da valores iniciales a los atributos internos.
  */
  JefeDeEstacion(Via *viaPrincipal, Via *ramalIzquierdo, Via *ramalDerecho);
  /**
  Destructor. No hace nada.
  */
  virtual ~JefeDeEstacion();
  /**
  Organiza el tren colocando los vagones enfermos al final.
  */
  virtual void organizarTren();
};

#else
class JefeDeEstacion; // Declaración adelantada.
#endif