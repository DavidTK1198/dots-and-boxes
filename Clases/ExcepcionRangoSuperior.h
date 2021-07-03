#pragma once
#include "ExcepcionRango.h"
class ExcepcionRangoSuperior :
	public ExcepcionRango
{
private:
	int valorcito;
public:
	ExcepcionRangoSuperior(int, int, int);
	virtual ~ExcepcionRangoSuperior();
	void setValor(int);
	string toString();
};

