#include "ExcepcionCoordIguales.h"

ExcepcionCoordIguales::ExcepcionCoordIguales(Coordenada* x, Coordenada* y):ExcepcionAgregar(x,y)
{
}

ExcepcionCoordIguales::~ExcepcionCoordIguales()
{
}

string ExcepcionCoordIguales::toString()
{
	stringstream s;
	s << ExcepcionAgregar::toString() << endl;
	s << "Error 05: Imposible trazar linea entre coordenadas iguales." << endl;
	s << "Intente de nuevo." << endl;
	return s.str();
}
