#pragma once
#include <iostream>
#include <sstream>
#include "Coordenada.h"
using namespace std;
class Componentes
{
	public:
		Componentes() {}
		virtual ~Componentes(){}
		virtual string toString()const = 0;
		virtual bool agregar(Coordenada*,Coordenada*,int) = 0;
		virtual bool asignarNumeroXCuadro(int) = 0;
		virtual void setJugador(int)=0;
		virtual int getJugador()=0;



};

