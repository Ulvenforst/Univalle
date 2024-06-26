/*
  Archivo: PresentadorIdeasFijas.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2020-10-24
  Fecha última modificación: 2022-30-07
  Versión: 0.2
  Licencia: GPL
*/

#include "PresentadorIdeasFijas.h"

PresentadorIdeasFijas::PresentadorIdeasFijas(string nombre) : Presentador(nombre)
{
  // No hay que hacer nada
}

PresentadorIdeasFijas::~PresentadorIdeasFijas()
{
  // No hay que hacer nada
}

double PresentadorIdeasFijas::entregarPremio(string nombreConcursante)
{
  return 100;
}
