/*
  Archivo: Jugador.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-07
  Licencia: GNU-GPL
*/

/**
  CLASE: Jugador
  INTENCIÓN: Este dará las órdenes en cada momento del juego, establecerá qué individuo se 
  mueve, y cuándo se mueve la barca. Determina las entradas del programa, también se asocia
  con una victoria o una derrota.
  RELACIONES:
  - Conoce a Individuo.
  - Conoce a Lugar. (También conoce sus hijos)
*/

#ifndef JUGADOR_H
#define JUGADOR_H

// Librerías.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Se usa para generar una interfaz visual que no se deforme.
#include <algorithm> // Permite realizar comparaciones numéricas de forma rápida.
#include <stdlib.h> // Se usa para finalizar el juego cuando Lugar determine si se perdió.
// Clases.
#include "Lugar.h"
#include "Individuo.h"

class Jugador
{
  private:
  vector<Lugar *> posiciones = {nullptr}; 
  int cantidad_maxima_jugadores = 0; // Su uso es principalmente con respecto a la parte visual.
  int posicionDeMuerte = 0; // Se usa para indicar dónde murió un personaje.

  public:
  /**
  Constructor; da valores iniciales a los atributos internos.
  */
  Jugador(Lugar *orillaIzquierda, Lugar *barca, Lugar *orillaDerecha);
  /**
  Destructor; limpia el vector de posiciones.
  */
  virtual ~Jugador();
  /**
  jugar: Con las reglas ya establecidas en main.cpp, se inicia el juego, principalmente se
  encarga de la parte visual.
  */
  virtual void jugar();
  /**
  moverPersonaje: Se encarga de mover un personaje de un lugar a otro, retorna un entero que indica el éxito del proceso.
  */
  virtual int moverPersonaje(char identificador);
  /**
  moverBarca: Se encarga de mover la barca de lugar, retorna un entero que indica el éxito del proceso.
  */
  virtual int moverBarca();
  /**
  pintarInterfaz: Se encarga de actualizar y generar la interfaz visual del juego.
  */
  virtual void pintarInterfaz();
};

#else
class Jugador; // Declaración adelantada.
#endif