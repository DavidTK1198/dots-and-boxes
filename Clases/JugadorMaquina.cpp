#include "JugadorMaquina.h"

JugadorMaquina::JugadorMaquina():Jugador()
{
	nombre = "CPU";
	this->nuevaEstrategia = NULL;
}

JugadorMaquina::~JugadorMaquina()
{
}

void JugadorMaquina::setEstrategia(Estrategia* est)
{
	if (nuevaEstrategia == NULL) {
		nuevaEstrategia = est;
	}
	else {
		delete nuevaEstrategia;
		nuevaEstrategia = NULL;
		nuevaEstrategia = est;
	}
}

void JugadorMaquina::ejecutarEstrategia()
{
	nuevaEstrategia->tipoDeEstrategia();
}

string JugadorMaquina::getNombre()
{
	return nombre;
}

Jugada* JugadorMaquina::ultima()
{
	return nuevaEstrategia->retornaUltima();
}
