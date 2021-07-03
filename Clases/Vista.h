#pragma once
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Excepciones.h"
#include "EmpresaDots.h"
#include "Partida.h"
#include "ControlComposite.h"
#include "JuegoPeriferico.h"
#include "JuegoAleatorio.h"
#include "JuegoCercano.h"
#include "JuegoCentral.h"
#include "JuegoIslas.h"
using namespace std;
class Vista {

public:
	static void gotoxy(int, int);
	static void despedida();
	static void menuEspecial(EmpresaDots*);
	static void PresentacionInicial();
	static int MenuPrincipal(EmpresaDots*);
	static int verPartidas();
	static int menuJugar();
	static void subMenuCrearJugador(EmpresaDots*);
	static Jugador* Acceso(EmpresaDots*);
	static void jugadorVsJugador(Jugador*,EmpresaDots*);
	static void jugadorVsMaquina(Jugador*, EmpresaDots*);
	static int menuEstrategias();
	static int opcionesTablero();
	static Partida* campoCompuesto(Jugador*,Jugador*);
	static Partida* campoSeisPuntos(Jugador*,Jugador*);
	static Partida* campoNuevePuntos(Jugador*, Jugador*);
	static Partida* campoQuincePuntos(Jugador*, Jugador*);
	static Coordenada* nueva();
	static void recrearPartidas(EmpresaDots*);
	static Estrategia* cambiaEstrategia(CampoAbs*);
	static void CamposCombinados();


};