#pragma once
#include "Estrategia.h"
#include "ListaGenerica.h"
class JuegoAleatorio :
	public Estrategia
{

	public:
		 JuegoAleatorio(CampoAbs*);
		 virtual ~JuegoAleatorio();
		 void tipoDeEstrategia();
		 virtual void setJugada(Jugada*) { throw; }


};

