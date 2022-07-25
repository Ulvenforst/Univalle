/*
  Archivo: Vagon.h
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-16-07
  Fecha última modificación: 2022-16-07
  Licencia: GNU-GPL
*/

/**
  CLASE: Vagon
  INTENCIÓN: Crea vagones de tren individuales con sus respectivos números asignados y estado de enfermedad (el estado de enfermedad indica si hay contagiados en el respectivo vagón o no).
  RELACIONES: Ninguna.
*/

#ifndef VAGON_H
#define VAGON_H

using namespace std;

class Vagon
{
  private:
  int numero_Vagon;
  bool transporta_enfermos;

  public:
  /**
  Constructor. Da valores iniciales a los atributos internos.
  */
  Vagon(int numero_del_Vagon, bool transporte_de_enfermos);
  /**
  Destructor. No hace nada.
  */
  virtual ~Vagon();
  /**
  Pregunta si hay pasajeros enfermos (No es usado de momento).
  */
  bool hay_pasajeros_enfermos();
  /**
  Retorna el número del vagón solicitado.
  */
  virtual int numero_vagon();
};

#else
class Vagon; // Declaración adelantada.
#endif