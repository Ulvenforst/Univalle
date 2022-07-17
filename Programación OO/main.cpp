/*
  Archivo: main.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-03-22
  Fecha última modificación: 2022-02-13
  Versión: 0.1
  Licencia: GPL
*/

/**
  HISTORIA: hay un tren con 6 vagones numerados consecutivamente de izquierda a derecha, del 1 al 6.
  En los vagones 2 y 4 hay personas enfermas que conviene transportarlas pero aisladas de las demás.
  Para ello, vamos a mover estos vagones al final del tren. Por suerte, en la estación hay dos ramales (uno hacia la izquierda y otro hacia la derecha) que nos van a ayudar a hacer este movimiento de vagones.
*/

#include "Via.h"
#include "Vagon.h"
#include <iostream>
using namespace std;


int main()
{
  Via viaPrincipal;
  Via ramalIzquierdo;
  Via ramalDerecho;
  
  // Situación inicial:
  viaPrincipal.introducirVagon(new Vagon(1, false));  // LA VÍA PRINCIPAL TOMA PROPIEDAD
  viaPrincipal.introducirVagon(new Vagon(2, true));   // LA VÍA PRINCIPAL TOMA PROPIEDAD
  viaPrincipal.introducirVagon(new Vagon(3, false));  // LA VÍA PRINCIPAL TOMA PROPIEDAD
  viaPrincipal.introducirVagon(new Vagon(4, true));   // LA VÍA PRINCIPAL TOMA PROPIEDAD
  viaPrincipal.introducirVagon(new Vagon(5, false));  // LA VÍA PRINCIPAL TOMA PROPIEDAD
  viaPrincipal.introducirVagon(new Vagon(6, false));  // LA VÍA PRINCIPAL TOMA PROPIEDAD
  cout << "Al inicio hay " << viaPrincipal.dimeCuantosVagonesHay() << " vagones: " << viaPrincipal.estadoActual() << endl;
  
  //Movimientos para llegar a la solución:
  viaPrincipal.retrocederPor(&ramalIzquierdo);  // LA VIA PRINCIPAL CEDE PROPIEDAD DEL VAGON A LA OTRA VIA
  viaPrincipal.retrocederPor(&ramalIzquierdo);  // LA VIA PRINCIPAL CEDE PROPIEDAD DEL VAGON A LA OTRA VIA
  viaPrincipal.retrocederPor(&ramalDerecho);  // LA VIA PRINCIPAL CEDE PROPIEDAD DEL VAGON A LA OTRA VIA
  viaPrincipal.retrocederPor(&ramalIzquierdo);  // LA VIA PRINCIPAL CEDE PROPIEDAD DEL VAGON A LA OTRA VIA
  viaPrincipal.retrocederPor(&ramalDerecho);  // LA VIA PRINCIPAL CEDE PROPIEDAD DEL VAGON A LA OTRA VIA
  viaPrincipal.avanzarDesde(&ramalIzquierdo);  // LA VIA PRINCIPAL TOMA PROPIEDAD DEL VAGON QUE ME CEDE LA OTRA VIA
  viaPrincipal.avanzarDesde(&ramalIzquierdo);  // LA VIA PRINCIPAL TOMA PROPIEDAD DEL VAGON QUE ME CEDE LA OTRA VIA
  viaPrincipal.avanzarDesde(&ramalIzquierdo);  // LA VIA PRINCIPAL TOMA PROPIEDAD DEL VAGON QUE ME CEDE LA OTRA VIA
  viaPrincipal.avanzarDesde(&ramalIzquierdo);  // LA VIA PRINCIPAL TOMA PROPIEDAD DEL VAGON QUE ME CEDE LA OTRA VIA
  viaPrincipal.avanzarDesde(&ramalDerecho);  // LA VIA PRINCIPAL TOMA PROPIEDAD DEL VAGON QUE ME CEDE LA OTRA VIA
  viaPrincipal.avanzarDesde(&ramalDerecho);  // LA VIA PRINCIPAL TOMA PROPIEDAD DEL VAGON QUE ME CEDE LA OTRA VIA
  
  // Imprimir la solución: 
  cout << "Al final hay " << viaPrincipal.dimeCuantosVagonesHay() << " vagones: " << viaPrincipal.estadoActual() << endl;

  return 0;
}