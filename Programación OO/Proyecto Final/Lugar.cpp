/*
  Archivo: Lugar.cpp
  Autor: Juan Camilo Narváez Tascón <juan.narvaez.tascon@correounivalle.edu.co>
  Fecha creación: 2022-08-05
  Fecha última modificación: 2022-08-07
  Licencia: GNU-GPL
*/

#include "Lugar.h"

Lugar::Lugar(vector<Individuo *> personajes)
{
  this -> personajes = personajes;
}

Lugar::~Lugar()
{
  Individuo *personaje_que_se_elimina = nullptr;
  while (personajes.size() > 0)
  {
    personaje_que_se_elimina = personajes[0];
    personajes.erase(personajes.begin()+0);
    if(personaje_que_se_elimina)
    {
      delete personaje_que_se_elimina;
      personaje_que_se_elimina = nullptr;
    }
  }
  personajes.clear();
}

int Lugar::cuantosPersonajesHay()
{
  return personajes.size();
}

vector<Individuo *> Lugar::quePersonajesHay()
{
  return personajes;
}

Individuo *Lugar::sacarPersonaje(char identificador)
{
  Individuo *personajeEnMovimiento = nullptr;
  for (int cualPersonaje = 0; cualPersonaje < personajes.size(); cualPersonaje++)
  {
    if(identificador == personajes[cualPersonaje]->identificadorPersonaje())
    {
      personajeEnMovimiento = personajes[cualPersonaje];
      personajes.erase(personajes.begin()+cualPersonaje); 
    }
  }
  return personajeEnMovimiento;
}

int Lugar::meterPersonaje(Individuo *personajeEnMovimiento)
{
  personajes.push_back(personajeEnMovimiento);
  return validarDevoracion();
}

bool Lugar::aforoConEspacio()
{
  int aforoPorDefecto = 6; // Este valor puede ser modificado para indicar un aforo por defecto.
  if (personajes.size() < aforoPorDefecto)
    return true;
  else
    return false;
}

int Lugar::validarDevoracion()
{ 
  // Valida si en dicha posición hay un vigilante que evite la devoración.
  for(int cualVigilante = 0; cualVigilante < personajes.size(); cualVigilante++)
  {
    if(personajes[cualVigilante]->validacionVigilante())
    {
      return 0;
    }
  }
  // Valida si queda alguien que pueda devorar a alguien.
  Individuo *personajeEnRevision = nullptr;
  vector<Individuo *> copia_personajes = personajes;
  for(int cualPersonaje = 0; cualPersonaje < personajes.size(); cualPersonaje++)
  {
    personajeEnRevision = copia_personajes[cualPersonaje];
    copia_personajes.erase(copia_personajes.begin()+cualPersonaje); 
    copia_personajes.insert(copia_personajes.begin()+cualPersonaje, personajeEnRevision);
    for(int cualDevorable = 0; cualDevorable < personajes.size(); cualDevorable++)
    {
      if(personajeEnRevision->validacionDevora(copia_personajes[cualDevorable]))
      {
        motivoDerrota = "Alguien fue devorado";
        sacarPersonaje(personajes[cualDevorable]->identificadorPersonaje());
        return 1;
      }
    }
  }
  return 0;
}

int Lugar::validarMovimiento(vector<Lugar *> posiciones, char *identificador, int cualPosicion)
{
  int numeroColumnasBusqueda = 4;
  Individuo *personajeEnMovimiento = nullptr;

  if(cualPosicion == 1 || cualPosicion == 3) // Únicos movimientos permitidos.
  {
    if(posiciones[cualPosicion-1])
    {
      if(posiciones[cualPosicion-1]->aforoConEspacio())
      {
        personajeEnMovimiento = posiciones[cualPosicion]->sacarPersonaje(*identificador);
        if(posiciones[cualPosicion-1]->meterPersonaje(personajeEnMovimiento))
          return 1;
      }
    }
    else
    {
      motivoDerrota = "Alguien se cayó al agua";
      personajeEnMovimiento = posiciones[cualPosicion]->sacarPersonaje(*identificador);
      return 1; // Determina que el personaje en cuestión se ahogo.
    }
  }
  else if(cualPosicion == 0 || cualPosicion == 2) // Únicos movimientos permitidos.
  {
    if(posiciones[cualPosicion+1])
    {
      if(posiciones[cualPosicion+1]->aforoConEspacio())
      {
        personajeEnMovimiento = posiciones[cualPosicion]->sacarPersonaje(*identificador);
        if(posiciones[cualPosicion+1]->meterPersonaje(personajeEnMovimiento) == 1)
          return 1;
      }
    }
    else
    {
      motivoDerrota = "Alguien se cayó al agua";
      personajeEnMovimiento = posiciones[cualPosicion]->sacarPersonaje(*identificador);
      return 1; // Determina que el personaje en cuestión se ahogo.
    }
  }
  return validarDevoracion();
}

string Lugar::motivoMuerte()
{
  return motivoDerrota;
}