#include "ExcepcionLexistente.h"

ExcepcionLexistente::ExcepcionLexistente(Coordenada* x, Coordenada* y):ExcepcionAgregar(x,y)
{
}

ExcepcionLexistente::~ExcepcionLexistente()
{
}

string ExcepcionLexistente::toString()
{
	stringstream s;
	s << ExcepcionAgregar::toString() << endl;
	s << "Error: 06: Imposible trazar linea sobre otra ya creada." << endl;
	s << "Intente de nuevo." << endl;
	return s.str();
}
