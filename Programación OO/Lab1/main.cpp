/*
  Archivo: main.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-05-02
  Fecha última modificación: 2022-05-02
  Licencia: GNU-GPL
*/

// Ejemplo con una clase y dos objetos.
/** 
HISTORIA: Hacer una mudanza. Tenemos dos camiones y un conjunto de objetos a transportar, para hacer una mudanza. 
  Cada objeto lo intentamos subir al primer camión, pero si no se puede lo llevamos al segundo camión; y si tampoco se puede, lo dejamos en tierra (no se puede transportar). Luego a cada camión le pedimos que haga la mudanza, que nos diga cuanto peso transportó y que descargue los objetos. 
  Estoy modelando un camión con una placa, que puede transportar una cierta carga en kilos, y que tiene una capacidad máxima en kilos. Se le puede pedir que me diga su placa, que cargue un objeto, que transporte toda la carga y que me diga cuánto transportó y que descargue todo.
*/

#include "Camion.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  Camion unCamion("ABC-001", 10000);
  Camion otroCamion("DEF-002", 5000);

  vector<int> objetos = {1000, 3000, 5000, 2000, 500, 1800, 4000, 30};

  for (int cualObjeto = 0; cualObjeto < objetos.size(); cualObjeto++)
  {
    int objetoATransportar = objetos[cualObjeto];

    if (not unCamion.cargarUnObjeto(objetoATransportar))
    {
      if (not otroCamion.cargarUnObjeto(objetoATransportar))
      {
        cout << "El objeto número " << cualObjeto << " que pesa " << objetos[cualObjeto] << " no se puede cargar en ningún camión." << endl;
      }
    }
  }

  unCamion.hacerMudanza();
  otroCamion.hacerMudanza();

  cout << "El camión " << unCamion.cualEsLaPlaca() << " transportó " << unCamion.pesoTransportado() << " kg." << endl;
  cout << "El camión " << otroCamion.cualEsLaPlaca() << " transportó " << otroCamion.pesoTransportado() << " kg." << endl;

  unCamion.descargar();
  otroCamion.descargar();

  return 0;
}
