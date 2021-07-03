#pragma once
#include <sstream>
#include <iostream>
#include "Vista.h"
#include "EmpresaDots.h"
using namespace std;


class Controlador
{
private:
	EmpresaDots* empresa;
public:
	Controlador();
	virtual ~Controlador();
	void control1();
	void control2();
	void control3();
	void control4();
	void control5();
	void control6(Jugador*);
	void control7();
	void control8(Jugador*);
};

