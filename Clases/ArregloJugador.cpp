#include "ArregloJugador.h"

ArregloJugador::ArregloJugador(int tam)
{
	this->tam = tam;
	cant = 0;
	vector = new Jugador * [tam];
	for (int i = 0; i < this->tam; i++) {
		vector[i] = NULL;
	}
}

ArregloJugador::~ArregloJugador()
{
	for (int i = 0; i < cant; i++) {
		delete vector[i];
	}
	delete[] vector;
}

int ArregloJugador::getCantidad()
{
	return cant;
}

Jugador** ArregloJugador::getVector()
{
	return vector;
}

string ArregloJugador::toString()
{
	stringstream s;
	s << "--------INFORMACION DE LOS SUSCRIPTORES---------" << endl;
	for (int i = 0; i < cant; i++) {
		s << "Suscriptor # " << i+1 << endl;
		s << vector[i]->toString() << endl;
	}

	return s.str();
}

void ArregloJugador::agregarJugador(Jugador* j)
{
	if (cant < tam) {
		vector[cant++] = j;
	}
}

bool ArregloJugador::operator[](int ind)
{
	return (vector[ind]);
}

void ArregloJugador::actualizarCodigo(string cod,double monede)
{
	for (int i = 0; i < cant; i++) {
		vector[i]->actualizar(cod,monede);
	}
}

void ArregloJugador::actualizaCodigoV2(Jugador* p, string s, double d)
{
	for (int i = 0; i < cant; i++) {
		if (vector[i]->getCedula() == p->getCedula()) {
			vector[i]->actualizar(s, d);
		}
	}
}

Jugador* ArregloJugador::buscarJugador(string p)
{
	for (int i = 0; i < cant; i++) {
		if (vector[i]->getCedula() == p) {
			return vector[i];
		}
	}
	return NULL;
}


