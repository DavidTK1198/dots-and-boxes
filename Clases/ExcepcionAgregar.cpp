#include "ExcepcionAgregar.h"

ExcepcionAgregar::ExcepcionAgregar(Coordenada* coor, Coordenada* c)
{
	this->coor1 = coor;
	this->coor2 = c;
}

ExcepcionAgregar::~ExcepcionAgregar()
{
}

string ExcepcionAgregar::toString()
{
	stringstream s;
	s << "Las coordenadas " << coor1->toString() << " y " << coor2->toString() << " no cumplen";
	s << " con la regla del juego siguiente: " << endl;
	return s.str();
}
