/*
  Archivo: Via.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-16-07
  Fecha última modificación: 2022-21-07
  Licencia: GNU-GPL
*/

#include "Via.h"

Via::Via()
{
  // No hay que hacer nada.
}

Via::~Via() 
{
  // std::cout <<"Entidad destruída" << std::endl;
  for (int contador_vagones; contador_vagones < tren.size(); contador_vagones++)
  {
    if (tren.at(contador_vagones) != nullptr)
    {
      // std::cout <<"Eliminando vagón número " << to_string(tren.at(contador_vagones)->numero_vagon()) << std::endl;
      delete tren.at(contador_vagones);
      tren.at(contador_vagones) = nullptr;
    }
  }
}

void Via::introducirVagon(Vagon *unVagon)
{
  tren.push_back(unVagon);
}

int Via::dimeCuantosVagonesHay()
{
  return tren.size();
}

string Via::estadoActual()
{
  string vagones_del_tren = "";
  for (int contador_vagones; contador_vagones < tren.size(); contador_vagones++)
  {
    vagones_del_tren += to_string(tren.at(contador_vagones)->numero_vagon()) + " ";
  }
  return vagones_del_tren;
}

void Via::retrocederPor(Via *via)
{
  Vagon *vagonQueEntra = nullptr;
  if (tren.size() != 0) // Se asegura de que no se sobrepase los vagones por vía.
  {
    Vagon *vagonQueEntra = tren.back();
    tren.pop_back();
    via->tren.push_back(vagonQueEntra);
  }
  if (vagonQueEntra != nullptr)
    //std::cout <<"Eliminando vagón alterno que retrocede" << std::endl;
    delete vagonQueEntra;
}

void Via::avanzarDesde(Via *via)
{
  Vagon *vagonQueEntra = nullptr;
  if (via->tren.size() != 0) // Se asegura de que no se sobrepase los vagones por vía.
  {
    Vagon *vagonQueEntra = via->tren.back();
    via->tren.pop_back();
    introducirVagon(vagonQueEntra);
  }
  if (vagonQueEntra != nullptr)
    //std::cout <<"Eliminando vagón alterno que avanza" << std::endl;
    delete vagonQueEntra;
}
