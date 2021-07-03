#pragma once
#include "Linea.h"
using namespace std;
class LineaVertical:public Linea
{
	private:
		string lineaV;
	public:
		LineaVertical();
		virtual ~LineaVertical();
		virtual bool agregar(Coordenada*, Coordenada*,int) { throw; }
		string toString()const;
		virtual bool asignarNumeroXCuadro(int) { throw; }
		virtual void setJugador(int);
		virtual int getJugador();

};

