/*
  Archivo: Presentador.h
  Autores: Juan Camilo Narváez Tascón, Carol Sofía Macarena Rubiano Valderrama.
  Email: <juan.narvaez.tascon@correounivalle.edu.co>, <carol.rubiano@correounivalle.edu.co>
  Fecha creación: 2022-29-07
  Fecha última modificación: 2022-29-07
  Licencia: GNU-GPL
*/

#include "Presentador.h"

Presentador::Presentador(string nombre) : nombre(nombre)
{
  // No hay que hacer nada, el nombre ya fue asignado (": nombre(nombre)").
}

Presentador::~Presentador()
{
  // No hay que hacer nada.
}

string Presentador::comoTeLlamas()
{
  return nombre;
}