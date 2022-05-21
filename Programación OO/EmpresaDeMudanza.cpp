/*
  Archivo: EmpresaDeMudanza.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-05-17
  Fecha última modificación: 2022-05-20
  Licencia: GNU-GPL
*/

#include "EmpresaDeMudanza.h"

EmpresaDeMudanza::EmpresaDeMudanza(string nombre, string nit)
{
  nombreEmpresa = nombre;
  nitEmpresa = nit;
  this -> camionesComprados = {};
}


EmpresaDeMudanza::~EmpresaDeMudanza() 
{
  // No hay que hacer nada
}


string EmpresaDeMudanza::nombreDeLaEmpresa()
{
  return nombreEmpresa;
}


string EmpresaDeMudanza::nitDeLaEmpresa()
{
  return nitEmpresa;
}


void EmpresaDeMudanza::comprarCamion(Camion unCamion)
{
  camionesComprados.push_back(unCamion);
}


void EmpresaDeMudanza::realizarMudanza(vector<int> objetos)
{
  int objetoATransportar;

  for (int cualCamion = 0; cualCamion < camionesComprados.size(); cualCamion++)
  {
    for (int cualObjeto = 0; cualObjeto < objetos.size(); cualObjeto++)
    {
      objetoATransportar = objetos[cualObjeto];
      if (camionesComprados[cualCamion].cargarUnObjeto(objetoATransportar))
      {
        objetos.erase(objetos.begin() + cualObjeto);
        // Se efectúa una resta para que en cada iteración, una vez eliminado el objeto ya transportado, se inicie con índice 0 sin omitir ningún objeto de la lista.
        cualObjeto--;
      }
    }
    camionesComprados[cualCamion].hacerMudanza();
  }
}


int EmpresaDeMudanza::pesoTotalTransportado()
{
  int pesoTotal = 0;
  for (int cualCamion = 0; cualCamion < camionesComprados.size(); cualCamion++)
  {
    pesoTotal += camionesComprados[cualCamion].pesoTransportado();
    camionesComprados[cualCamion].descargar();
  }
  return pesoTotal;
}