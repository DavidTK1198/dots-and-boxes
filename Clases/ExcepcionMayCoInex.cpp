#include "ExcepcionMayCoInex.h"

ExcepcionMayCoInex::ExcepcionMayCoInex(Coordenada* x, Coordenada* y):ExcepcionAgregar(x,y)
{
}

ExcepcionMayCoInex::~ExcepcionMayCoInex()
{
}

string ExcepcionMayCoInex::toString()
{
	stringstream s;
	s << ExcepcionAgregar::toString() << endl;
	s << "Error 02: Imposible unir lineas en coordenadas inexistentes." << endl;
	s << "Intentar de nuevo." << endl;
	return s.str();
}
