#include "ExcepcionDiagonal.h"

ExcepcionDiagonal::ExcepcionDiagonal(Coordenada* x, Coordenada* y):ExcepcionAgregar(x,y)
{
}

ExcepcionDiagonal::~ExcepcionDiagonal()
{
}

string ExcepcionDiagonal::toString()
{
	stringstream s;
	s << ExcepcionAgregar::toString() << endl;
	s << "Error 01: Imposible unir coordenadas en diagonal." << endl;
	s << "Vuelva a intentarlo." << endl;
	return s.str();
}
