/*
  Archivo: Presentador.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-29-07
  Fecha última modificación: 2022-29-07
  Licencia: GNU-GPL
*/

/**
  CLASE: Presentador
  INTENCIÓN: Es una clase abstracta para el presentador. Su objetivo principal es calcular el valor del premio a entregar.
  - le puedo preguntar el nombre.
  - le puedo pedir que entregue el premio respectivo.
  RELACIONES: Contiene un Nombre.
*/

#ifndef PRESENTADOR_H
#define PRESENTADOR_H

#include <string>
using namespace std;

class Presentador
{
protected:
  string nombre;

public:
  /**
  Constructor; da valores iniciales a los atributos internos.
  */
  Presentador(string nombre);
  /**
  Destructor; no hace nada.
  */
  virtual ~Presentador();
  /**
  Devuelve como salida el nombre del respectivo presentador.
  */
  virtual string comoTeLlamas();
  /**
  Calcula el premio que dicho presentador debe entregar, este depende del tipo de presentador.
  */
  virtual double entregarPremio(string nombreConcursante) = 0;
};

#else
class Presentador; // Declaración adelantada
#endif