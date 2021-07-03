#pragma once
#include "ExcepcionAgregar.h"
class ExcepcionDiagonal :
	public ExcepcionAgregar
{
	public:
		ExcepcionDiagonal(Coordenada*, Coordenada*);
		virtual ~ExcepcionDiagonal();
		string toString();
};

