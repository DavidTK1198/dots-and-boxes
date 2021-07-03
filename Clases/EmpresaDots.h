#pragma once
#include "ArregloJugador.h"
#include <Windows.h>
#include <time.h>
#include "Partida.h"
#include "ListaGenerica.h"
class EmpresaDots
{
	private:
		ArregloJugador* arreglito;
		string codigo;
		Lista<Partida>* partidas;
		int dia;
		double precioSus;
		string nombre;
	public:
		EmpresaDots();
		virtual ~EmpresaDots();
		void attach(Jugador*);
		void notify();
		void notifyV2(Jugador*);
		void changeDay();
		void setCodigo(string);
		void generarCodigoAut();
		string mostrarSuscriptores();
		void cargaTodo();
		void GuardaTodo();
		Lista<Partida>* getContenedorPar();
		Jugador* buscarJugador(string);
		ArregloJugador* getArreglo();
		void agregaPartida(Partida*);
		string toString();
		string cambiaNombreDia();
};

