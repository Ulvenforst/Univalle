/*
  Archivo: EmpresaDeMudanza.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-05-17
  Fecha última modificación: 2022-05-20
  Licencia: GNU-GPL
*/

/**
  CLASE: EmpresaDeMudanza
  INTENCIÓN: Simular una empresa la cual trabaje a disposición de lo solicitado en main.cpp; se han de comprar camiones para realizar mudanzas, cargando cada objeto en dichos camiones hasta que estos estén llenos; se procede a realizar la respectiva mudanza devolviendo el dato correspondiente
  al total del peso transportado para ser impreso.
  RELACIONES: contiene Camiones
*/

#ifndef EmpresaDeMudanza_H
#define EmpresaDeMudanza_H

#include "Camion.h"
#include<string>
#include <vector>
using namespace std;

class EmpresaDeMudanza
{
  private:
  string nombreEmpresa;
  string nitEmpresa;
  vector <Camion> camionesComprados;

  public:
  /**
  Constructor. Da valores iniciales a los atributos internos.
  */
  EmpresaDeMudanza(string nombre, string nit);
  /**
  Destructor, no hace nada.
  */
  virtual ~EmpresaDeMudanza();
  /**
  Retorna el nombre de la empresa de mudanza.
  */
  virtual string nombreDeLaEmpresa();
  /**
  Retorna el nit de la empresa de mudanza.
  */
  virtual string nitDeLaEmpresa();
  /**
  Recibe como argumento un camión a la venta y efectúa la compra a nombre de la empresa.
  */
  virtual void comprarCamion(Camion unCamion);
  /**
  Recibe como argumento una lista con los pesos de los objetos que se transportarán y realiza la mudanza con los camiones comprados con anterioridad.
  */
  virtual void realizarMudanza(vector<int> objetos);
  /**
  Retorna el peso total transportado en la mudanza y descarga cada camión.
  */
  virtual int pesoTotalTransportado();
};

#else
class EmpresaDeMudanza; // Declaración adelantada
#endif