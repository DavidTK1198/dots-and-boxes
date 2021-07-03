#include "LineaVertical.h"
#include <Windows.h>

LineaVertical::LineaVertical():Linea()
{
	lineaV = "|";
}

LineaVertical::~LineaVertical()
{
}

string LineaVertical::toString() const
{

	stringstream s;
	if (this->jugador == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}


	if (this->jugador == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	s << lineaV;
	
	return s.str();
}

void LineaVertical::setJugador(int p)
{
	this->jugador = p;
}

int LineaVertical::getJugador()
{
	 return this->jugador;
}
