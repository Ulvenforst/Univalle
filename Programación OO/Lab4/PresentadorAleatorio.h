/*
  Archivo: PresentadorAleatorio.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2022-29-07
  Versión: 0.2
  Licencia: GPL
*/

/**
  CLASE: PresentadorAleatorio
  INTENCIÓN: representa un presentador de televisión que tiene un algoritmo que calcula el valor del premio a entregar al azar. Además:
  - le puedo preguntar el nombre
  - le puedo pedir que entregue el premio
  RELACIONES:
  - Es un presentador.
*/

#ifndef PRESENTADORALEATORIO_HH
#define PRESENTADORALEATORIO_HH

#include "Presentador.h"
#include <string>
#include <cstdlib>
using namespace std;

class PresentadorAleatorio : public Presentador
{
protected:
  // Nombre es heredado.

public:
  /**
   * @brief Construye un presentador de ideas fijas (ese va a ser su nombre)
   */
  PresentadorAleatorio(string nombre);
  /**
   * @brief Destructor. No hace nada.
   */
  virtual ~PresentadorAleatorio();
  /**
   * @brief Retorna el premio a entregar a un concursante (concretamente, un número al azar entre 0 y 300 bitcoins)
   * @param recibe el nombre del concursante al que le va a entregar el premio, aunque no hace nada con este dato
   */
  virtual double entregarPremio(string nombreConcursante);
};

#else
class PresentadorAleatorio; // Declaración adelantada
#endif
