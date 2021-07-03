#pragma once
#include "Estrategia.h"
class JuegoCercano :
	public Estrategia
{
	private:
		Jugada* nueva;
	public:
		JuegoCercano(CampoAbs*);
		virtual ~JuegoCercano();
		void tipoDeEstrategia();
		virtual void setJugada(Jugada*);
		bool cercano();
		bool cercanoCoor2();
};

