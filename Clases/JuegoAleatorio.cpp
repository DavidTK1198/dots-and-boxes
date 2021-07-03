#include "JuegoAleatorio.h"
#include <time.h>

JuegoAleatorio::JuegoAleatorio(CampoAbs* c):Estrategia(c)
{
	this->nombre = "Estrategia Aleatoria";
}

JuegoAleatorio::~JuegoAleatorio()
{
}

void JuegoAleatorio::tipoDeEstrategia()
{
	string aux = "";
	int valor = 0;
	int n = 0;
	srand((unsigned int)time(NULL));
	Componentes*** com = campito->getMatriz();
		recuperarPosicion();
		lista.inicializarActual();
		valor = lista.genCantidad();
	
		if (valor == 1) {
			n = 1 + rand() % (valor + 1 - 1);
		}
		else {
			n = 1 + rand() % (valor - 1);
		}
		string* x = lista.retornaElemento(n);
		aux = *x;
		convierteValores(aux);
		lista.limpiaLista();
		lista.iniciaPrimero();
}

