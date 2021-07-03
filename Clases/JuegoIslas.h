#pragma once
#include "Estrategia.h"
class JuegoIslas :
	public Estrategia
{
public:
	JuegoIslas(CampoAbs*);
	virtual ~JuegoIslas();
	void tipoDeEstrategia();
	virtual void setJugada(Jugada*) { throw; }
	virtual bool misLineas();
};

