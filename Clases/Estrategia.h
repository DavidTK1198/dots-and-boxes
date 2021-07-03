#pragma once
#include <iostream>
#include <sstream>
#include "CampoAbs.h"
#include "LineaHorizontal.h"
#include "ListaGenerica.h"
#include "Jugada.h"
#include <time.h>
using namespace std;
class Partida;
class Estrategia
{
	protected:
		CampoAbs* campito;
		Lista<string> lista;
		Lista<string> movimientosNoPermitidos;
		Jugada* ultima;
		string nombre;

	public:
		Estrategia(CampoAbs*);
		virtual ~Estrategia(){}
		virtual void tipoDeEstrategia() = 0;
		virtual bool analizarPosiblesCuadros(bool);
		virtual bool recuperarPosicion();
		virtual void setJugada(Jugada*) = 0;
		virtual bool verficar();
		virtual bool ingresaVertical(int,int);
		virtual bool ingresaHorizontal(int,int);
		virtual string* LineaV(int, int);
		virtual string* LineaH(int, int);
		Jugada* retornaUltima();
		bool convierteValores(string);
		virtual string getNombreEst();
		int valoraPosibilidades();
		int posibilidades(string);
		string* JugadaMasInteligente();
		void corroboraMovimientosLegales();
	protected:
		Coordenada* convierteCoordDer(int,int);
		Coordenada* convierteCoordIzq(int,int);
		Coordenada* convierteCoorArri(int,int);
		Coordenada* convierteCoorAba(int, int);
		
};

