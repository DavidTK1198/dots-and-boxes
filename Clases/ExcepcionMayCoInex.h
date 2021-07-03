#pragma once
#include "ExcepcionAgregar.h"
class ExcepcionMayCoInex :
	public ExcepcionAgregar
{
	public:
		ExcepcionMayCoInex(Coordenada*, Coordenada*);
		virtual ~ExcepcionMayCoInex();
		string toString();
};

