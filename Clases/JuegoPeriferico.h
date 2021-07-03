#pragma once
#include "ListaGenerica.h"
#include "Estrategia.h"
#include "ControlComposite.h"
class JuegoPeriferico :
	public Estrategia
{
	
	public:
		JuegoPeriferico(CampoAbs*);
		virtual ~JuegoPeriferico();
		void tipoDeEstrategia();
		bool ingresaLineasHorizontales();
		bool ingresaLineasVerticales();
		void agregaLineasPerifericas(int, int, int);
		bool cambiarPeriferia();
		void periferiaNueva(int,int,int);
		virtual void setJugada(Jugada*) { throw; }
};

