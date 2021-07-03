#pragma once
#include "ExcepcionAgregar.h"
class ExcepcionCoordIguales :
	public ExcepcionAgregar
{
	public:
		ExcepcionCoordIguales(Coordenada*, Coordenada*);
		virtual ~ExcepcionCoordIguales();
		string toString();
};

