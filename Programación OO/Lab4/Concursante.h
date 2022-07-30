/*
  Archivo: Concursante.h
  Autor: Ángel García Baños
  Email: angel.garcia@correounivalle.edu.co
  Fecha creación: 2020-10-24
  Fecha última modificación: 2021-01-19
  Versión: 0.1
  Licencia: GPL
*/

/**
  CLASE: Concursante
  INTENCIÓN: representa un concursante ganador de un concurso de televisión que va a recibir su premio. Además:
  - le puedo solicitar que reciba el premio
  - le puedo preguntar su nombre y el premio recibido
  RELACIONES:
  - contiene un nombre
  - contiene el premio que reciba, en bitcoins
*/

#ifndef CONCURSANTE_HH
#define CONCURSANTE_HH

#include <string>
using namespace std;

class Concursante
{
  protected:
  string nombre;
  double bitcoinsDePremio;
  
  public:
  /**
   * Construye un Concursante con un nombre. Inicialmente no tiene ningún premio.
   */
  Concursante(string nombre);
  /**
   * Destructor. No hace nada.
   */
  virtual ~Concursante();
  /**
   * Dice cuál es nombre
   */
  virtual string comoTeLlamas();
  /**
   * Dice cuál fue el premio que recibió
   */
  virtual double quePremioTeDieron();
  /**
   * Recibe el premio del concurso (una cierta cantidad de bitcoins)
   */
  virtual void recibirPremio(double bitcoinsDePremio);
};

#else
class Concursante;  // Declaración adelantada
#endif


