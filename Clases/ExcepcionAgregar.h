#pragma once
#include <iostream>
#include <sstream>
#include "Coordenada.h"
using namespace std;
class ExcepcionAgregar
{
	protected:
		Coordenada* coor1;
		Coordenada* coor2;
	public:
		ExcepcionAgregar(Coordenada*, Coordenada*);
		virtual ~ExcepcionAgregar();
		virtual string toString();
};

