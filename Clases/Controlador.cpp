#include "Controlador.h"

Controlador::Controlador()
{
	empresa = new EmpresaDots();
	empresa->cargaTodo();
	control1();
}
Controlador::~Controlador()
{
	empresa->GuardaTodo();
	delete empresa;
}

void Controlador::control1()
{
	Vista::PresentacionInicial();
	int p = 0;
	do {
		p = Vista::MenuPrincipal(empresa);
		switch (p)
		{
		case 1:
			control4();
			break;

		case 2:
			control3();
			break;
		case 3:
			control2();
			break;
		case 4:
			control5();
			break;
		default:
			break;
		}
	} while (p != 5);

}

void Controlador::control2()
{
	int z = 0;
	do {
		z = Vista::verPartidas();
		switch (z)
		{
		case 1:
			control7();
			break;
		default:
			break;
		}

	} while (z != 2);
}

void Controlador::control4()
{
	Vista::subMenuCrearJugador(empresa);
}

void Controlador::control5()
{
	empresa->changeDay();
}

void Controlador::control6(Jugador* j)
{
	Vista::jugadorVsJugador(j, empresa);
}

void Controlador::control7()
{
	Vista::recrearPartidas(empresa);
}

void Controlador::control8(Jugador* j)
{
	Vista::jugadorVsMaquina(j, empresa);
}

void Controlador::control3()
{
	int z = 0;
	Jugador* nuevo = Vista::Acceso(empresa);
	if (nuevo != NULL) {
		do {
			z = Vista::menuJugar();
			switch (z)
			{
			case 1:
				control6(nuevo);
				break;
			case 2:
				control8(nuevo);
				break;
			default:
				break;
			}

		} while (z != 3);
	}
	else {
		Vista::MenuPrincipal(empresa);
	}
}



