/*
  Archivo: Camion.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-05-02
  Fecha última modificación: 2022-05-02
  Licencia: GNU-GPL
*/

/**
  CLASE: Camion
  INTENCIÓN: Obtener la placa de identificación del camión, al igual que la capacidad máxima de peso que puede transportar. Con estos datos se guardarán objetos en el camión, mientras no excedan la capacidad máxima de peso, y se transportarán, indicando al final cuánto fue lo máximo que pudo transportar. Por último el camión se vaciará.
  RELACIONES: ninguna
*/

#ifndef CAMION_H
#define CAMION_H

#include<string>
using namespace std;

class Camion
{
  private:
  string placa;
  int capacidadMaxima;
  int pesoAcumulado;
  bool mudanzaRealizada;

  public:
  /**
  Constructor. Da valores iniciales a los atributos internos
  */
  Camion(string laPlaca, int laCapacidadMaxima);
  /**
  Destructor. No hace nada
  */
  virtual ~Camion();
  /**
  Retorna la identificación de la placa.
  */
  virtual string cualEsLaPlaca();
  /**
  Carga el objeto respectivo, que brinde el vector, al camión (Si este cuenta con la capacidad).
  */
  bool cargarUnObjeto(int pesoDelObjeto); // true = se pudo cargar; false = no se pudo cargar
  /**
  Validará que la mudanza se haya hecho.
  */
  virtual void hacerMudanza();
  /**
  Si la mudanza fue hecha, retornará el peso que transportó.
  */
  virtual int pesoTransportado(); // Retorna la carga que transportó
  /**
  Vacía los camiones dejando el peso acomulado en 0.
  */
  virtual void descargar();
};

#else
class Camion; // Declaración adelantada
#endif
