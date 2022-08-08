/*
  Archivo: Individuo.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-08
  Licencia: GNU-GPL
*/

/**
  CLASE: Individuo
  INTENCIÓN: Es un personaje que se transporta entre lugares. Puede comerse a otro individuo
  en el caso de no contar con una supervición y estar en el mismo lugar del individuo con el
  que se alimenta.
  RELACIONES:
  - Conoce a Lugar.
  - Se contiene a sí mismo.
*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H

// Librerías.
#include <vector>
#include <string>
// Clases.

using namespace std;

class Individuo
{
  private:
  vector<Individuo*> personajesComestibles;
  string identificador;
  bool esVigilante = false;
  string nombre;
  bool manejaLaBarca = false;

  public:
  /**
  Constructor; da valores iniciales a los atributos internos.
  */
  Individuo(string nombre, bool manejaLaBarca, bool esVigilante);
  /** 
  Sobrecarga de constructor para identificadores personalizados.
  */
  Individuo(string nombre, string identificador, bool manejaLaBarca, bool esVigilante);
  /**
  Destructor; no hace nada.
  */
  virtual ~Individuo();
  /**
  nombrePersonaje: Retorna el nombre del personaje en cuestión.
  */
  string nombrePersonaje();
  /**
  identificadorPersonaje: Retorna el identificador del personaje en cuestión.
  */
  string identificadorPersonaje();
  /**
  validacionVigilante: En caso de ser un vigilante, retorna true.
  */
  bool validacionVigilante();
  /**
  seComeA: Guarda en un arreglo propio aquellos personajes a los que puede devorar.
  */
  void seComeA(Individuo *comestible);
  /**
  validacionDevora: Revisa si el personaje pasado como atributo está en la lista de los
  personajesComestibles, de ser así retorna true.
  */
  bool validacionDevora(Individuo *comestible);
  /**
  puedeManejar: Retorna un valor de tipo bool que indica si el personaje puede manejar o no la barca.
  */
  bool puedeManejar();
};

#else
class Individuo; // Declaración adelantada.
#endif