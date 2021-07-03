#include "ExcepcionRango.h"

ExcepcionRango::ExcepcionRango(int m, int ma)
{
	min = m;
	max = ma;
}
ExcepcionRango::~ExcepcionRango() {}

string ExcepcionRango::toString()
{
	stringstream m;
	m << "El valor ha ingresar esta en el rango de " << endl;
	m << min << " y " << max << endl;
	return m.str();
}

