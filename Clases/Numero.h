#pragma once
#include "Componentes.h"
class Numero :
	public Componentes
{
	private:
		int numero;
	public:
		Numero(int);
		virtual ~Numero();
		virtual bool agregar(Coordenada*, Coordenada*,int) { throw; }
		string toString()const;
		virtual bool asignarNumeroXCuadro(int) { throw; }
		int getNumero();
		virtual void setJugador(int) { throw; }
		virtual int getJugador() { throw; }

};

