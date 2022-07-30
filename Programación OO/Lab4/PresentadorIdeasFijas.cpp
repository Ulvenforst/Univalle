/*
  Archivo: PresentadorIdeasFijas.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2020-10-24
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
