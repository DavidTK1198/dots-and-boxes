#pragma once
#include "ExcepcionAgregar.h"
class ExcepcionLexistente :
	public ExcepcionAgregar
{
	public:
		ExcepcionLexistente(Coordenada*, Coordenada*);
		virtual ~ExcepcionLexistente();
		string toString();
};

