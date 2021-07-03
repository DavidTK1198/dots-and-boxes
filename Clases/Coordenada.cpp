#include "Coordenada.h"

Coordenada::~Coordenada()
{
}

Coordenada::Coordenada(int xx, int yy)
{
	x = 2*xx;
	y = 2*yy;
}

int Coordenada::obtenerX()
{
	return x;
}

int Coordenada::obternerY()
{
	return y;
}

void Coordenada::setX(int xx)
{
	x = x;
}

void Coordenada::setY(int yy)
{
	y = yy;
}

string Coordenada::toString()
{
	stringstream s;
	s << "(" << x/2 << "," << y/2 << ")";
	return s.str();
}

istream& operator>>(istream& in, Coordenada& p)
{

	//3,5
	in >> p.x >> p.y;
	return in;

}
