#pragma once
#include "Jugador.h"
#include "Estrategia.h"
class Estrategia;
class JugadorMaquina :
	public Jugador
{
	private:
		string nombre;
		Estrategia* nuevaEstrategia;
	public:
		JugadorMaquina();
		virtual ~JugadorMaquina();
		virtual void setEstrategia(Estrategia*);
		virtual void ejecutarEstrategia();
		virtual void actualizar(string, double) { throw;}
		virtual string toString()const { throw; }
		virtual string getNombre();
		virtual string getCedula() { throw; }
		virtual string getCodigo() { throw; }
		virtual double getMonedero() { throw; }
		virtual void setNombre(string) { throw; }
		virtual void setCedula(string) { throw; }
		virtual void setCodigo(string) { throw; }
		virtual void setMonedero(double) { throw; }
		virtual Jugada* ultima();
		
};