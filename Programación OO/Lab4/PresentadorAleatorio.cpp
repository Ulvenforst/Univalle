/*
  Archivo: PresentadorAleatorio.cpp
  Autores: Juan Camilo Narváez Tascón, Carol Sofía Macarena Rubiano Valderrama.
  Email: <juan.narvaez.tascon@correounivalle.edu.co>, <carol.rubiano@correounivalle.edu.co>
  Fecha creación: 2020-10-24
  Fecha última modificación: 2022-30-07
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