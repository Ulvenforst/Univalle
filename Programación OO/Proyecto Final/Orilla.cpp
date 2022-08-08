/*
  Archivo: Orilla.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-07
  Licencia: GNU-GPL
*/

#include "Orilla.h"

Orilla::Orilla(vector<Individuo *> personajes) : Lugar(personajes)
{
  // Atributo pasado a clase padre.
}

Orilla::~Orilla()
{
  // Los personajes de la lista están siendo eliminados en la clase padre.
}

