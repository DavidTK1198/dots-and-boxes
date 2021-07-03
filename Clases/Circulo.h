#pragma once
#include "Componentes.h"
class Circulo :
	public Componentes
{
	private:
		string circulito;
	public:
		Circulo();
		virtual ~Circulo();
		virtual bool agregar(Coordenada*, Coordenada*,int) { throw; }
		string toString()const;
		virtual bool asignarNumeroXCuadro(int) { throw; }
		virtual void setJugador(int) { throw; }
		virtual int getJugador() { throw; }
};

