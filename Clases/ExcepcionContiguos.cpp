#include "ExcepcionContiguos.h"

ExcepcionContiguos::ExcepcionContiguos(Coordenada* x, Coordenada* y):ExcepcionAgregar(x,y)
{
}

ExcepcionContiguos::~ExcepcionContiguos()
{
}

string ExcepcionContiguos::toString()
{
	stringstream s;
	s << ExcepcionAgregar::toString() << endl;
	s << "Error 03: Imposible trazar lineas a coordenadas no contiguas." << endl;
	s << "Vuelva a intentarlo." << endl;
	return s.str();
}
