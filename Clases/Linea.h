#pragma once
#include <iostream>
#include "Componentes.h"
class Linea :
	public Componentes
{
	protected:
		int jugador;
	public:
		Linea() { jugador = 0; }
		virtual ~Linea(){}
		virtual bool agregar(Coordenada*, Coordenada*,int) = 0;
		virtual string toString()const = 0;
		virtual bool asignarNumeroXCuadro(int) { throw; }
		virtual void setJugador(int) = 0;
		virtual int getJugador() = 0;
};

