#include "LineaHorizontal.h"
#include <Windows.h>

LineaHorizontal::LineaHorizontal():Linea()
{
	linea = "----";
}

LineaHorizontal::~LineaHorizontal()
{
}

string LineaHorizontal::toString() const
{
	static int p = 1;
	stringstream s;
	if (this->jugador == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}


	if (this->jugador == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	}
	s <<linea;
	return s.str();
}

void LineaHorizontal::setJugador(int p)
{
	this->jugador = p;
}

int LineaHorizontal::getJugador()
{
	return this->jugador;
}
