/*
  Archivo: Individuo.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-08
  Licencia: GNU-GPL
*/

#include "Individuo.h"

Individuo::Individuo(string nombre, bool manejaLaBarca, bool esVigilante)
{
  this -> nombre = nombre;
  this -> esVigilante = esVigilante;
  this -> manejaLaBarca = manejaLaBarca;
  identificador = nombre[0];
}

Individuo::Individuo(string nombre, string identificador, bool manejaLaBarca, bool esVigilante)
{
  this -> nombre = nombre;
  this -> esVigilante = esVigilante;
  this -> manejaLaBarca = manejaLaBarca;
  this -> identificador = identificador;
}

Individuo::~Individuo()
{
  if(personajesComestibles.size() != 0)
  {
    // Los personajes de forma individual ya están siendo eliminados en Lugar
    if(personajesComestibles.size() >= 0)
    {
      for(int cualPersonajeComestible = 0; cualPersonajeComestible < personajesComestibles.size(); cualPersonajeComestible++)
      {
        personajesComestibles[cualPersonajeComestible] = nullptr;
      }
    }  
  }
  personajesComestibles.clear();
}

string Individuo::nombrePersonaje()
{
  return nombre;
}

string Individuo::identificadorPersonaje()
{
  return identificador;
}

bool Individuo::validacionVigilante()
{
  return esVigilante;
}

void Individuo::seComeA(Individuo *comestible)
{
  personajesComestibles.push_back(comestible);
}

bool Individuo::validacionDevora(Individuo *comestible)
{
  for(int cualPersonaje = 0; cualPersonaje < personajesComestibles.size(); cualPersonaje++)
  {
    if(comestible->identificadorPersonaje() == personajesComestibles[cualPersonaje]->identificadorPersonaje())
      return true;
  }
  return false;
}

bool Individuo::puedeManejar()
{
  return manejaLaBarca;
}