/*
  Archivo: Camion.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-05-02
  Fecha última modificación: 2022-05-02
  Licencia: GNU-GPL
*/

#include "Camion.h"

Camion::Camion(string laPlaca, int laCapacidadMaxima)
{
  placa = laPlaca;
  capacidadMaxima = laCapacidadMaxima;
  pesoAcomulado = 0;
  mudanzaRealizada = false;
}


string Camion::cualEsLaPlaca() 
{ 
  return placa; 
}


bool Camion::cargarUnObjeto(int pesoDelObjeto)
{
  if (pesoAcomulado + pesoDelObjeto <= capacidadMaxima)
  {
    pesoAcomulado = pesoAcomulado + pesoDelObjeto;
    return true;
  }
  else
    return false;
}


Camion::~Camion() 
{
  // No hay que hacer nada
}


void Camion::hacerMudanza()
{
  mudanzaRealizada = true;
}


int Camion::pesoTransportado()
{
  if (mudanzaRealizada)
    return pesoAcomulado;
  else
    return 0;
}


void Camion::descargar()
{
  mudanzaRealizada = false;
  pesoAcomulado = 0;
}
