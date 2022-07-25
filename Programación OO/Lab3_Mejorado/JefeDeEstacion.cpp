/*
  Archivo: JefeDeEstacion.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-23-07
  Fecha última modificación: 2022-23-07
  Licencia: GNU-GPL
*/

#include "JefeDeEstacion.h"

JefeDeEstacion::JefeDeEstacion(Via *viaPrincipal, Via *ramalIzquierdo, Via *ramalDerecho)
{
  this->viaPrincipal = viaPrincipal;
  this->ramalIzquierdo = ramalIzquierdo;
  this->ramalDerecho = ramalDerecho;
}

JefeDeEstacion::~JefeDeEstacion()
{
  // No se hace nada, la vías fueron creadas en el main de manera estática.
}

void JefeDeEstacion::organizarTren()
{
  for (int contadoVagones = 0; contadoVagones != viaPrincipal->dimeCuantosVagonesHay();)
  {
    if (viaPrincipal->sacarVagon()->hay_pasajeros_enfermos())
    {
      viaPrincipal->retrocederPor(ramalIzquierdo);
    }
    else
    {
      viaPrincipal->retrocederPor(ramalDerecho);
    }
  }
  for (int contadoVagones = 0; contadoVagones != ramalDerecho->dimeCuantosVagonesHay();)
  {
    viaPrincipal->avanzarDesde(ramalDerecho);
  }
  for (int contadoVagones = 0; contadoVagones != ramalIzquierdo->dimeCuantosVagonesHay();)
  {
    viaPrincipal->avanzarDesde(ramalIzquierdo);
  }
}