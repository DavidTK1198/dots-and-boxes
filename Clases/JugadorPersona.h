#pragma once
#include "Jugador.h"
class JugadorPersona :
	public Jugador
{
	private:
		string nombre;
		string cedula;
		string codigo;
		double monedero;
	public:
		JugadorPersona(string = "", string = "", string = "", double = 0.0);
		JugadorPersona(const JugadorPersona& jug);
		virtual ~JugadorPersona();
		virtual void actualizar(string, double);
		virtual string toString()const;
		virtual string getNombre();
		virtual string getCedula();
		virtual string getCodigo();
		virtual double getMonedero();
		virtual void setNombre(string);
		virtual void setCedula(string);
		virtual void setCodigo(string);
		virtual void setMonedero(double);
		virtual void setEstrategia(Estrategia*) { throw; }
		virtual void ejecutarEstrategia() { throw; }
		virtual Jugada* ultima() { throw; }
		bool operator == (string);
	
};

ostream& operator <<(ostream&, JugadorPersona&);