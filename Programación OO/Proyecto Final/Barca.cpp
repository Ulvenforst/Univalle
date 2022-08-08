/*
  Archivo: Barca.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-08
  Licencia: GNU-GPL
*/

#include "Barca.h"

Barca::Barca(vector<Individuo *> personajes) : Lugar(personajes)
{
  // Atributo pasado a clase padre.
}

Barca::~Barca()
{
  // Los personajes de la lista están siendo eliminados en la clase padre.
}

bool Barca::aforoConEspacio()
{
  int aforoPorDefecto = 2;
  if (personajes.size() < aforoPorDefecto)
    return true;
  else
    return false;
}

bool Barca::conductor_a_bordo()
{
  for(int cualPersonaje = 0; cualPersonaje < personajes.size(); cualPersonaje++)
  {
    if(personajes[cualPersonaje]->puedeManejar())
      return true;
  }
  return false;
}