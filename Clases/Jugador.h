#pragma once
#include <iostream>
#include <sstream>
#include "Estrategia.h"
using namespace std;
class Jugador
{

	public:
		Jugador() {}
		/*Jugador(const Jugador&);*/
		virtual ~Jugador(){}
		virtual void actualizar(string, double) = 0;
		virtual string toString()const = 0;
		virtual string getNombre() = 0;
		virtual string getCedula() = 0;
		virtual string getCodigo() = 0;
		virtual double getMonedero() = 0;
		virtual void setNombre(string) = 0;
		virtual void setCedula(string) = 0;
		virtual void setCodigo(string) = 0;
		virtual void setMonedero(double) = 0;
		virtual void setEstrategia(Estrategia*) = 0;
		virtual void ejecutarEstrategia() = 0;
		virtual Jugada* ultima() = 0;

	
		//JugadorM

};

ostream& operator <<(ostream&, Jugador&);