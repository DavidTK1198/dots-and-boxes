#pragma once
#include "Estrategia.h"
class JuegoCentral :
	public Estrategia
{
	private:
		int lim1;
		int lim2;

	public:
		JuegoCentral(CampoAbs*);
		virtual ~JuegoCentral();
		void tipoDeEstrategia();
		bool devuelveCuadradoMasCentrico();
		int ayudante(int,int);
		int ayudanteImpar(int,int,int);
		int ayudantePar(int, int, int);
		bool completaEstrategia();
		bool recuperaPedazosPerdidos();
		void setJugada(Jugada*) { throw; }
};

