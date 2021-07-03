#pragma once
#include "ControlComposite.h"
#include "ListaGenerica.h"
#include "Jugada.h"
#include "Jugador.h"
#include "JugadorMaquina.h"
#include "JugadorPersona.h"
class Partida
{
	private:
		Lista<Jugada>* list;
		ControlComposite* campoJuego;
		Jugador* jugador1;
		Jugador* jugador2;
	public:
		Partida(int = 0, Jugador* = NULL, Jugador* = NULL);
		virtual ~Partida();
		Lista<Jugada>* getListaJugadas();
		ControlComposite* getCampo();
		void setControlCompo(ControlComposite*);
		bool agregarComponente(Coordenada*, Coordenada*,int);
		void agregarMatrizACont(CampoAbs*);
		void agregarJugada(Jugada*);
		bool estaLleno();
		/*bool estaVacio();*/
		bool determinarNumeroXCuadroGana(int);
		string toString()const;
		void nuevoCampoXfilasIguales();
		void nuevaCampoXfilasDispares();
		void setNuevaZona(CampoAbs*);
		string toStringMatriz();
		string mostrandoPartidas();
		void pintaMatriz(int);
		void guardar(ofstream&);
		int getCantMatCom();
		Partida* recuperar(ifstream&);
		CampoAbs** getVector();
		Lista<Jugada>* getListaJugada();
		int determinaGanador();
		Jugada* ultimaJugada();
		string toStringJugadas();
		friend ostream& operator <<(ostream&, Partida&);
	
};

