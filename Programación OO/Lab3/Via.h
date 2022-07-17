/*
  Archivo: Via.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-16-07
  Fecha última modificación: 2022-16-07
  Licencia: GNU-GPL
*/

/**
  CLASE: Via
  INTENCIÓN: Esta clase es la encargada de crear las respectivas vías del tren, también se encarga de cambiar las conexiones de las vías a petición del usuario y devolver el estado actual de las mismas.
  RELACIONES: Las vías conocen los vagones.
*/

#ifndef VIA_H
#define VIA_H

#include<string>
#include<vector>
#include"Vagon.h"

using namespace std;

class Via
{
  private:
  vector<Vagon*> tren;

  public:
  /**
  Constructor. Da valores iniciales a los atributos internos
  */
  Via();
  /**
  Destructor. No hace nada
  */
  virtual ~Via();
  /**
  Introduce un puntero vagón.
  */
  void introducirVagon(Vagon *unVagon);
  /**
  Saca el último vagón.
  */
  Vagon *sacarVagon();
  /**
  Indica la cantidad de vagones actuales.
  */
  virtual int dimeCuantosVagonesHay();
  /**
  Muestra el estado actual de la vía (posición de los vagones en el tren).
  */
  string estadoActual();
  /**
  Indica en qué dirección retrocederá el vagón.
  */
  virtual void retrocederPor(Via* via);
  /**
  Indica desde dónde ha de avanzar el vagón en una vía.
  */
  virtual void avanzarDesde(Via* via);

};

#else
class Via; // Declaración adelantada
#endif