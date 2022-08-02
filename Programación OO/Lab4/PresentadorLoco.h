/*
  Archivo: PresentadorLoco.h
  Autores: Juan Camilo Narváez Tascón, Carol Sofía Macarena Rubiano Valderrama.
  Email: <juan.narvaez.tascon@correounivalle.edu.co>, <carol.rubiano@correounivalle.edu.co>
  Fecha creación: 2020-10-24
  Fecha última modificación: 2022-30-07
  Versión: 0.2
  Licencia: GPL
*/

/**
  CLASE: PresentadorLoco
  INTENCIÓN: representa un presentador de televisión que tiene un algoritmo raro para calcular el valor del premio a entregar. Además:
  - le puedo preguntar el nombre
  - le puedo pedir que entregue el premio
  RELACIONES:
  - Es un presentador.
*/

#ifndef PRESENTADORLOCO_HH
#define PRESENTADORLOCO_HH

#include "Presentador.h"
#include <string>
using namespace std;

class PresentadorLoco : public Presentador
{
  protected:
  // Nombre es heredado.
  
  public:
  /**
  * @brief Construye un presentador aleatorio (ese va a ser su nombre)
  */
  PresentadorLoco(string nombre);
  /**
  * @brief Destructor. No hace nada.
  */
  virtual ~PresentadorLoco();
  /**
  * @brief Retorna el premio a entregar a un concursante (concretamente, el número de letras del nombre del concursante multiplicado por 200).
  * @param recibe el nombre del concursante al que le va a entregar el premio
  */
  virtual double entregarPremio(string nombreConcursante);
};

#else
class PresentadorLoco; // Declaración adelantada
#endif