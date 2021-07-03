#include "Circulo.h"
#include <Windows.h>
Circulo::Circulo():Componentes()
{
	circulito = "O";
}

Circulo::~Circulo()
{
}

string Circulo::toString() const
{
	stringstream s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	s << circulito;
	return s.str();
}
