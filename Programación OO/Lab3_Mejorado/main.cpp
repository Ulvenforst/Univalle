/*
  Archivo: main.cpp
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-03-22
  Fecha última modificación: 2022-02-14
  Versión: 0.1
  Licencia: GPL
*/

/*
  HISTORIA: hay un tren con muchos vagones numerados consecutivamente de izquierda a derecha, del 1 en adelante. En algunos de los vagones hay personas enfermas que conviene transportarlas pero aisladas de las demás. Para ello, vamos a mover estos vagones al final del tren. Por suerte, en la estación hay dos ramales (uno hacia la izquierda y otro hacia la derecha) que nos van a ayudar a hacer este movimiento de vagones. Hay un Jefe de Estación que es el encargado de dar las órdenes a todas las vías, para mover los vagones adecuadamente.
*/

#include "Via.h"
#include "Vagon.h"
#include "JefeDeEstacion.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  Via viaPrincipal;
  Via ramalIzquierdo;
  Via ramalDerecho;
  JefeDeEstacion jefeDeEstacion(&viaPrincipal, &ramalIzquierdo, &ramalDerecho);

  string auxiliar;
  cout << "¿Cuántos vagones son?" << endl;
  getline(cin, auxiliar);
  int cantidadDeVagones = stoi(auxiliar);
  for (int cualVagon = 0; cualVagon < cantidadDeVagones; cualVagon++)
  {
    cout << "En el vagón " << cualVagon + 1 << " ¿hay personas enfermas (S/N)?" << endl;
    getline(cin, auxiliar);
    bool enfermos = (auxiliar == "S" or auxiliar == "s");
    viaPrincipal.introducirVagon(new Vagon(cualVagon + 1, enfermos)); // TOMA PROPIEDAD
  }

  cout << "Al inicio: " << viaPrincipal.estadoActual() << endl;
  jefeDeEstacion.organizarTren();
  cout << "Al final: " << viaPrincipal.estadoActual() << endl;

  return 0;
}