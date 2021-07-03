#include "JuegoIslas.h"

JuegoIslas::JuegoIslas(CampoAbs* p) :Estrategia(p)
{
	this->nombre = "Estrategia Juego de Islas";
}

JuegoIslas::~JuegoIslas()
{
}

void JuegoIslas::tipoDeEstrategia()
{
	bool m = false;
	string aux = "";
	int valor = 0;
	int n = 0;
	srand((unsigned int)time(NULL));
	Componentes*** com = campito->getMatriz();
	if (!analizarPosiblesCuadros(m)) {
		if (!misLineas()) {
			recuperarPosicion();
			verficar();
			if (lista.genCantidad() == 0) {
				recuperarPosicion();
			}
		}
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
}

bool JuegoIslas::misLineas()
{
	int contador = 0;
	Linea* lin = NULL;
	int contador2 = 0;
	Componentes*** com = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {
			if (i % 2 == 1 && j % 2 == 1 && com[i][j] == NULL) {
				if (com[i - 1][j - 1] != NULL && com[i - 1][j + 1] != NULL && com[i + 1][j - 1] != NULL && com[i + 1][j + 1] != NULL) {
					if (com[i + 1][j] != NULL && com[i + 1][j]->getJugador() == 2) {
						contador++;
					}
					if (com[i - 1][j] != NULL && com[i - 1][j]->getJugador() == 2) {
						contador++;
					}
					if (com[i][j + 1] != NULL && com[i][j + 1]->getJugador() == 2) {
						contador++;
					}
					if (com[i][j - 1] != NULL && com[i][j - 1]->getJugador() == 2) {
						contador++;
					}

					if (com[i + 1][j] != NULL && com[i + 1][j]->getJugador() == 1) {
						contador2++;
					}
					if (com[i - 1][j] != NULL && com[i - 1][j]->getJugador() == 1) {
						contador2++;
					}
					if (com[i][j + 1] != NULL && com[i][j + 1]->getJugador() == 1) {
						contador2++;
					}
					if (com[i][j - 1] != NULL && com[i][j - 1]->getJugador() == 1) {
						contador2++;
					}

					if (contador == 1 && contador2 == 0) {
						if (com[i][j - 1] == NULL) {
							ingresaVertical(i, j - 1);
						}
						if (com[i][j + 1] == NULL) {
							ingresaVertical(i, j + 1);
						}
						if (com[i + 1][j] == NULL) {
							ingresaHorizontal(i + 1, j);
						}
						if (com[i - 1][j] == NULL) {
							ingresaHorizontal(i - 1, j);
						}
					}
				}
			}
			contador2 = 0;
			contador = 0;

		}
	}
	if (lista.genCantidad() == 0) {
		return false;
	}
	return true;
}
