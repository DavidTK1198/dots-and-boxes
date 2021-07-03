#pragma once
#include "Coordenada.h"
#include <iostream>
using namespace std;
class Jugada
{
	private:
		Coordenada* cord1;
		Coordenada* cord2;
	public:
		Jugada(Coordenada* = NULL, Coordenada* = NULL);
		virtual ~Jugada();
		Coordenada* getCordenada1();
		Coordenada* getCoordenada2();
		string toString();
		void guardaJugada (ofstream&);
		Jugada* cargaJugada (ifstream&);
		friend ostream& operator <<(ostream&, Jugada&);
		bool operator == (Jugada&);
};

