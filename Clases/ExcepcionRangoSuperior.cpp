#include "ExcepcionRangoSuperior.h"
ExcepcionRangoSuperior::ExcepcionRangoSuperior(int min, int max, int val) :ExcepcionRango(min, max) {
	valorcito = val;
}


ExcepcionRangoSuperior::~ExcepcionRangoSuperior()
{
}

string ExcepcionRangoSuperior::toString()
{
	stringstream p;
	p << "El valor: " << valorcito << " es mayor al permitido." << endl;
	p << ExcepcionRango::toString() << endl;
	return p.str();
}
void ExcepcionRangoSuperior::setValor(int val) {
	valorcito = val;
}
