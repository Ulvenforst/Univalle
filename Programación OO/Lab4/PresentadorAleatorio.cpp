/*
  Archivo: PresentadorAleatorio.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2021-09-26
  Versión: 0.2
  Licencia: GPL
*/

#include "PresentadorAleatorio.h"

PresentadorAleatorio::PresentadorAleatorio(string nombre) : Presentador(nombre)
{
  // No hay que hacer nada
}

PresentadorAleatorio::~PresentadorAleatorio()
{
  // No hay que hacer nada
}

double PresentadorAleatorio::entregarPremio(string nombreConcursante)
{
  return rand() % 300;
}
