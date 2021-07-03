#pragma once
#include "Jugador.h"
class ArregloJugador
{
	private:
		Jugador** vector;
		int cant;
		int tam;
	public:
		ArregloJugador(int);
		virtual ~ArregloJugador();
		int getCantidad();
		Jugador** getVector();
		string toString();
		void agregarJugador(Jugador*);
		bool operator [](int);
		void actualizarCodigo(string,double);
		void actualizaCodigoV2(Jugador*, string, double);
		Jugador* buscarJugador(string);



};

