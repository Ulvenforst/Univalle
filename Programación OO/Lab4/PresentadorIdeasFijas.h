/*
  Archivo: PresentadorIdeasFijas.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2022-29-07
  Versión: 0.2
  Licencia: GPL
*/

/**
  CLASE: PresentadorIdeasFijas
  INTENCIÓN: representa un presentador de televisión que siempre entrega un premio del mismo valor. Además:
  - le puedo preguntar el nombre
  - le puedo pedir que entregue el premio
  RELACIONES:
  - Es un presentador.
*/

#ifndef PRESENTADORIDEASFIJAS_HH
#define PRESENTADORIDEASFIJAS_HH

#include "Presentador.h"
#include <string>
using namespace std;

class PresentadorIdeasFijas : public Presentador
{
protected:
  // Nombre es heredado.

public:
  /**
   * @brief Construye un presentador de ideas fijas (ese va a ser su nombre)
   */
  PresentadorIdeasFijas(string nombre);
  /**
   * @brief Destructor. No hace nada.
   */
  virtual ~PresentadorIdeasFijas();
  /**
   * @brief Retorna el premio a entregar a un concursante (concretamente, 100 bitcoins)
   * @param recibe el nombre del concursante al que le va a entregar el premio, aunque no hace nada con este dato
   */
  virtual double entregarPremio(string nombreConcursante);
};

#else
class PresentadorIdeasFijas; // Declaración adelantada
#endif
