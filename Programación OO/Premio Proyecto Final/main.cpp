/**
  Archivo: main.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-08
  Licencia: GNU-GPL
*/

/**
  HISTORIA: Hay un robot que debe de transportar un zorro, un conejo y una lechuga desde un
  lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres
  individuos, incluyendo el robot. El problema es que si el robot deja solos al zorro y al 
  conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se 
  comerá la lechuga. El jugador debe controlar que órdenes dar, para lograr que el robot
  transporte los tres individuos a la otra orilla, sanos y salvos.
*/

// Librerías.
#include <vector>
// Clases.
#include "Jugador.h"
#include "Orilla.h"
#include "Barca.h"
#include "Individuo.h"

using namespace std;

int main() 
{
  // Variables para mejor lectura.
  bool si_maneja_la_barca = true;
  bool no_maneja_la_barca = false;
  bool si_es_vigilante = true;
  bool no_es_vigilante = false;
  vector<Individuo*> sinPersonajesIniciales = {}; // Posiciones de los lugares vacíos.

  // Personajes iniciales del juego.
  vector<Individuo*> personajesIniciales =
  { // Identificadores reservados: B, Q, y las iniciales de los personajes que ya hay.
    new Individuo("Robot", si_maneja_la_barca, si_es_vigilante),           // Posición 0.
    new Individuo("Zorro", no_maneja_la_barca, no_es_vigilante),           // Posición 1.
    new Individuo("Conejo", no_maneja_la_barca, no_es_vigilante),          // Posición 2.
    new Individuo("Lechuga", no_maneja_la_barca, no_es_vigilante),         // Posición 3.
    new Individuo("Conejo 2", "C2", no_maneja_la_barca, no_es_vigilante),  // Posicion 4.
    new Individuo("Robot 2", "R2", si_maneja_la_barca, si_es_vigilante)    // Posicion 5.
    /* En el caso de que la inicial de un nombre (el id) se repita, o se quiera asignar un identificador 
    diferente a la inicial, puede hacerlo de esta manera por medio de la sobrecarga. */
  };
  
  // Lugares. Si se quiere cambiar el punto de llegada ganador, coloque posiciones[0] en Jugador función jugar.
  Orilla orillaIzquierda(personajesIniciales); 
  Barca barca(sinPersonajesIniciales); // Solo admite, máximo, 2 personajes en sí.
  Orilla orillaDerecha(sinPersonajesIniciales); 

  // Reglas.
  personajesIniciales[1]->seComeA(personajesIniciales[2]); // El (1)zorro se come al (2)conejo.
  personajesIniciales[1]->seComeA(personajesIniciales[4]); // El (1)zorro se come al (4)conejo.
  personajesIniciales[2]->seComeA(personajesIniciales[3]); // El (2)conejo se come la (3)lechuga.
  personajesIniciales[4]->seComeA(personajesIniciales[3]); // El (4)conejo se come la (3)lechuga.

  // Inicialización del juego.
  Jugador jugador(&orillaIzquierda, &barca, &orillaDerecha);
  jugador.jugar();

  return 0;
}