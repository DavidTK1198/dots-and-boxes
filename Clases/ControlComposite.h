#pragma once
#include "CampoAbs.h"
#include "CampoJuego.h"
#include "SeisPuntos.h"
#include "NuevePuntos.h"
#include "QuincePuntos.h"
class ControlComposite
{
	private:
		CampoAbs* campo;
	public:
		ControlComposite(int);
		virtual ~ControlComposite();
		bool agregarComponente(Coordenada*, Coordenada*,int);
		void agregarMatrizACont(CampoAbs*);
		bool estaLleno();
		bool estaVacio();
		void imprimirConColor(int);
		bool determinarNumeroXCuadroGana(int);
		string toString()const;
		void nuevaZonaJuegoSeisXNueve();
		void nuevaZonaJuegoSeisXQuince();
		void setNuevaZona(CampoAbs*);
		CampoAbs* getCampoAbs();
		int getkCampoJuego();
		string guardaCampo(int);
		int getCantVecMat();
		CampoAbs** getVector();
		int determinaGanador();
		

};

