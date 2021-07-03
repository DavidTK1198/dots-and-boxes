#include "JugadorPersona.h"

JugadorPersona::JugadorPersona(string nom, string ced, string cod, double mon):Jugador()
{
	nombre = nom;
	cedula = ced;
	codigo = cod;
	monedero = mon;
}

JugadorPersona::JugadorPersona(const JugadorPersona& jug)
{
	this->nombre = jug.nombre;
	this->cedula = jug.cedula;
	this->codigo = jug.codigo;
	this->monedero = jug.monedero;
}

JugadorPersona::~JugadorPersona()
{
}

void JugadorPersona::actualizar(string co, double d)
{
	if (monedero >= 500) {
		monedero -= d;
		codigo = co;
	}
}



string JugadorPersona::getNombre()
{
	return nombre;
}

string JugadorPersona::getCedula()
{
	return cedula;
}

string JugadorPersona::getCodigo()
{
	return codigo;
}

double JugadorPersona::getMonedero()
{
	return monedero;
}

void JugadorPersona::setNombre(string nom)
{
	nombre = nom;
}

void JugadorPersona::setCedula(string cod)
{
	codigo = cod;
}

void JugadorPersona::setCodigo(string ced)
{
	cedula = ced;
}

void JugadorPersona::setMonedero(double mon)
{
	monedero = mon;
}

bool JugadorPersona::operator==(string p)
{
	return (cedula == p);
}

ostream& operator<<(ostream& out, JugadorPersona& j)
{
	out << j.toString() << endl;
	return out;
}
string JugadorPersona::toString() const
{
	stringstream s;
	s << "Nombre...." << nombre << endl;
	s << "Cedula...." << cedula << endl;
	s << "Codigo del JugadorPersona..." << codigo << endl;
	s << "Monedero actual...." << monedero << " colones." << endl;
	s << "--------------------------------------------------" << endl;
	return s.str();

}

