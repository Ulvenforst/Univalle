/*
  Archivo: Concursante.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2020-10-24
  Versión: 0.1
  Licencia: GPL
*/

#include "Concursante.h"


Concursante::Concursante(string nombre)
  : nombre(nombre), bitcoinsDePremio(0)
{
}


Concursante::~Concursante()
{
}


string Concursante::comoTeLlamas()
{
  return nombre;
}


double Concursante::quePremioTeDieron()
{
  return bitcoinsDePremio;
}


void Concursante::recibirPremio(double bitcoinsDePremio)
{
  this->bitcoinsDePremio += bitcoinsDePremio;
}



