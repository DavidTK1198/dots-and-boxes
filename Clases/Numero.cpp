#include "Numero.h"
#include <Windows.h>

Numero::Numero(int num):Componentes()
{
	numero = num;
}

Numero::~Numero()
{
}

string Numero::toString() const
{
	stringstream s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	s << numero;
	return s.str();
}

int Numero::getNumero()
{
	return numero;
}
