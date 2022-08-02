/*
  Archivo: PresentadorLoco.cpp
  Autores: Juan Camilo Narváez Tascón, Carol Sofía Macarena Rubiano Valderrama.
  Email: <juan.narvaez.tascon@correounivalle.edu.co>, <carol.rubiano@correounivalle.edu.co>
  Fecha creación: 2020-10-24
  Fecha última modificación: 2022-30-07
  Versión: 0.2
  Licencia: GPL
*/

#include "PresentadorLoco.h"

PresentadorLoco::PresentadorLoco(string nombre) : Presentador(nombre)
{
  // No hay que hacer nada
}

PresentadorLoco::~PresentadorLoco()
{
  // No hay que hacer nada
}

double PresentadorLoco::entregarPremio(string nombreConcursante)
{
  return 200 * nombreConcursante.size();
}