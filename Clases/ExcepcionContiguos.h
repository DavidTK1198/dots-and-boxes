#pragma once
#include "ExcepcionAgregar.h"
class ExcepcionContiguos :
	public ExcepcionAgregar
{
	public:
		ExcepcionContiguos(Coordenada*, Coordenada*);
		virtual ~ExcepcionContiguos();
		string toString();
};

