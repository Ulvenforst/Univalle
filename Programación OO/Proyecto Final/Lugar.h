/*
  Archivo: Lugar.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-08
  Licencia: GNU-GPL
*/

/**
  CLASE: Lugar
  INTENCIÓN: Siendo un objeto padre, este tendrá las propiedades básicas o comunes de 
  los lugares; establece qué individuos están en un respectivo lugar y determina la victoria.
  RELACIONES:
  - Conoce a Individuo.
*/

#ifndef LUGAR_H
#define LUGAR_H
// Librerías.
#include <string> // Se usa para retornar el motivo por el cual perdió.
#include <vector>
#include <algorithm>
// Clases.
#include "Individuo.h"

using namespace std;

class Lugar
{
  protected:
  vector<Individuo *> personajes = {nullptr};
  string motivoDerrota;

  public:
  /**
  Constructor; da valores iniciales a los atributos internos.
  */
  Lugar(vector<Individuo *> personajes);
  /**
  Destructor; no hace nada.
  */
  virtual ~Lugar();
  /**
  cuantosPersonajesHay: Retorna un entero correspondiente al número de personajes que hay en sí mismo.
  */
  virtual int cuantosPersonajesHay();
  /**
  quePersonajesHay: Retorna un arreglo con los personajes que hay en sí mismo.
  */
  virtual vector<Individuo *> quePersonajesHay();
  /**
  sacarPersonaje: Saca el personaje correspondiente al identificador asignado.
  */
  virtual Individuo *sacarPersonaje(string identificador);
  /**
  meterPersonaje: Mete el personaje que se pase como atributo, retorna un bool que indica el éxito del proceso.
  */
  virtual bool meterPersonaje(Individuo *personajeEnMovimiento);
  /**
  aforoCompleto: Retorna un bool que indica si ya está lleno el lugar.
  */
  virtual bool aforoConEspacio();
  /**
  validarMovimiento: Valida el estado de juego (si perdió o ganó), y consiguiente aplica el mivimiento 
  indicado, retorna true en caso de haber aplicado el movimiento con éxito, de lo contrario cierra el programa.
  */
  virtual bool validarMovimiento(vector<Lugar *> posiciones, string *identificador, int cualPosicion);
  /**
  validarDevoracion: Valida que en la posicion correspondiente nadie devore a nadie, de ser así retorna false.
  */
  virtual bool validarDevoracion();
  /**
  motivoMuerte: Retorna el motivo de la derrota.
  */
  virtual string motivoMuerte();
  /**
  conductor_a_bordo: Función abstracta que se usará en la barca.
  */
  virtual bool conductor_a_bordo();
};

#else
class Lugar; // Declaración adelantada.
#endif