#include "ExcepcionRangoInferior.h"
ExcepcionRangoInferior::ExcepcionRangoInferior(int min, int max, int val) :ExcepcionRango(min, max) {
	valorcito = val;
}

ExcepcionRangoInferior::~ExcepcionRangoInferior()
{
}

string ExcepcionRangoInferior::toString()
{
	stringstream p;
	p << "El valor: " << valorcito << " es menor al permitido." << endl;
	p << ExcepcionRango::toString() << endl;
	return p.str();
}
void ExcepcionRangoInferior::setValor(int val) {
	valorcito = val;
}
