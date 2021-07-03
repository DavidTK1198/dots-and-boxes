#pragma once
#include "Linea.h"
class LineaHorizontal :
	public Linea
{
	private:
		string linea;
	public:
		LineaHorizontal();
		virtual ~LineaHorizontal();
		virtual bool agregar(Coordenada*, Coordenada*,int) { throw; }
		string toString()const;
		virtual bool asignarNumeroXCuadro(int) { throw; }
		virtual void setJugador(int);
		virtual int getJugador();
};

