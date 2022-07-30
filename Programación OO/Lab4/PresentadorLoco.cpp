/*
  Archivo: PresentadorLoco.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2021-09-29
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
