/*
  Archivo: Jugador.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-09
  Licencia: GNU-GPL
*/

#include "Jugador.h"

Jugador::Jugador(Lugar *orillaIzquierda, Lugar *barca, Lugar *orillaDerecha)
{
  // Posición inicial del juego.
  posiciones = {orillaIzquierda, barca, nullptr, orillaDerecha}; 
  cantidad_maxima_jugadores = max(posiciones[0]->cuantosPersonajesHay(), posiciones[3]->cuantosPersonajesHay());
}

Jugador::~Jugador()
{
  if(posiciones.size() != 0)
  {
    // Las posiciones de forma individual ya están siendo eliminados en Lugar.
    posiciones[0] = nullptr;
    posiciones[1] = nullptr; 
    posiciones[2] = nullptr; 
    posiciones[3] = nullptr; 
  }
  posiciones.clear();
}

void Jugador::jugar()
{
  string instruccion = "Q"; // Intrucción para finalizar el juego.

  cout << setw(33) << "LA BARCA" << endl;
  cout << "Eres un robot y tu misión es llevar a todos los individuos \na la otra orilla usando la barca. No puedes dejar solos al \nzorro con el conejo, ni al conejo con la lechuga, porque \nel primero se devoraría al segundo. En la barca solo caben \ndos individuos, y uno de ellos debes ser tú, para pilotarla. \nLas órdenes que puedes dar son: " << endl;
  cout << setw(33) << "- Q para rendirte" << endl;
  for(int cualInstruccion = 0; cualInstruccion < cantidad_maxima_jugadores; cualInstruccion++)
  { // Cambie las posiciones en el caso de que los personajes estén en otro lugar principalmente.
    cout << setw(18) << "- " << posiciones[0]->quePersonajesHay()[cualInstruccion]->identificadorPersonaje() << " para mover a: " << posiciones[0]->quePersonajesHay()[cualInstruccion]->nombrePersonaje() << endl;
  }

  do
  {
    if(instruccion == "B")
      moverBarca();
    else
    {
      if(moverPersonaje(instruccion) == false)
      {
        pintarInterfaz();
        if(posiciones[posicionDeMuerte]->motivoMuerte() == "")
          cout << "Alguien fue devorado" << endl;
        else
          cout << posiciones[posicionDeMuerte]->motivoMuerte() << endl;
        cout << "PERDISTE" << endl;
        exit(0);
      } 
    } 

    if(posiciones[3]->cuantosPersonajesHay() == cantidad_maxima_jugadores)
    { // Si se quiere cambiar el punto de llegada ganador, coloque posiciones[0].
      pintarInterfaz();
      cout << "GANASTE" << endl;
      exit(0);
    }
    
    pintarInterfaz();  
    cout << "¿Qué desea hacer? ";
    cin >> (instruccion);
    if(instruccion == "Q")
      cout << "TE RENDISTE\nPERDISTE" << endl;

  } while (instruccion != "Q");
}

bool Jugador::moverPersonaje(string identificador)
{
  int numeroColumnasBusqueda = 4;
  Individuo* personajeEnMovimiento = nullptr;
  
  // Validación de identificador, versión base.
  for (int cualPosicion = 0; cualPosicion < numeroColumnasBusqueda; cualPosicion++)
  {
    if(posiciones[cualPosicion]) // Se asegura de buscar el identificador donde haya algo.
    {
      for (int cualIdentificador = 0; cualIdentificador < posiciones[cualPosicion]->cuantosPersonajesHay(); cualIdentificador++)
      {
        if(identificador == posiciones[cualPosicion]->quePersonajesHay()[cualIdentificador]->identificadorPersonaje())
        { // Este es un ejemplo de cambio de propiedad (Jugador pasa elementos a Lugar).
          posicionDeMuerte = cualPosicion;
          return posiciones[cualPosicion]->validarMovimiento(posiciones, &identificador, cualPosicion);
        }
      }
    }
  }
  return true;
}

bool Jugador::moverBarca()
{ 
  Lugar* lugarEnMovimiento = nullptr;
  for(int cualPosicion = 1; cualPosicion < 3; cualPosicion++)
  {
    if(posiciones[cualPosicion] && posiciones[cualPosicion]->conductor_a_bordo())
    {
      // Este código describe el algoritmo más sencillo en el movimiento de la barca.
      lugarEnMovimiento = posiciones[1];
      posiciones.erase(posiciones.begin()+1);
      posiciones.push_back(lugarEnMovimiento);
      lugarEnMovimiento = posiciones[2];
      posiciones.erase(posiciones.begin()+2);
      posiciones.push_back(lugarEnMovimiento);
      return true;
    }
  }
  return true;
}

void Jugador::pintarInterfaz()
{ 
  int numeroFilasTotales = cantidad_maxima_jugadores;
  int numeroColumnasTotales = 4;

  // Impresión de encabezados.
  if (posiciones[1])
    cout << "|" << setw(12) << left << "IZQUIERDA" << "|" << setw(12) << "BARCA" << "|" << setw(12) << "" << "|" << setw(12) << "DERECHA" << "|" <<endl;
  else
    cout << "|" << setw(12) << left << "IZQUIERDA" << "|" << setw(12) << "" << "|" << setw(12) << "BARCA" << "|" << setw(12) << "DERECHA" << "|" <<endl;

  // Impresión de los lugares.
  for (int cualFila = 0; cualFila < numeroFilasTotales; cualFila++)
  {
    for (int cualColumna = 0; cualColumna < numeroColumnasTotales; cualColumna++)
    {
      if(posiciones[cualColumna] && cualFila < posiciones[cualColumna]->cuantosPersonajesHay())
      {
        cout << "|" << setw(12) << left << posiciones[cualColumna]->quePersonajesHay()[cualFila]->nombrePersonaje();
      }
      else 
        cout << "|" << setw(12) << left << "";
      if (cualColumna+1 == numeroColumnasTotales)
      {
        cout << "|" << endl;
      }
    }
  }
}
