#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class ExcepcionRango
{
protected:
	int max;
	int min;
public:
	ExcepcionRango(int, int);
	virtual ~ExcepcionRango();
	virtual void setValor(int) = 0;
	virtual string toString();
};

