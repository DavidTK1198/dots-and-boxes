#pragma once
#include "ExcepcionRango.h"
class ExcepcionRangoInferior :
	public ExcepcionRango
{
private:
	int valorcito;
public:
	ExcepcionRangoInferior(int, int, int);
	virtual ~ExcepcionRangoInferior();
	void setValor(int);
	string toString();
};

