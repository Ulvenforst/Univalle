/*
  Archivo: Vagon.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-16-07
  Fecha última modificación: 2022-16-07
  Licencia: GNU-GPL
*/

#include "Vagon.h"

Vagon::Vagon(int numero_del_Vagon, bool transporte_de_enfermos)
{
  numero_Vagon = numero_del_Vagon;
  transporta_enfermos = transporte_de_enfermos;
}

Vagon::~Vagon() 
{
  // No hay que hacer nada
}

bool Vagon::hay_pasajeros_enfermos() // Esta función no se usa de momento.
{
  if (transporta_enfermos == true)
  {
    return true;
  }
  else
    return false;
}

int Vagon::numero_vagon()
{
  return numero_Vagon;
}