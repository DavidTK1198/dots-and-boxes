#include "JuegoCercano.h"
#include <time.h>

JuegoCercano::JuegoCercano(CampoAbs* x):Estrategia(x)
{
	this->nombre = "Estrategia Juego Cercano";
	this->nueva = NULL;
}

JuegoCercano::~JuegoCercano()
{
}

void JuegoCercano::tipoDeEstrategia()
{
	
	int lim1 = 0;
	int lim2 = campito->getFilas();
	int lim = campito->getColumnas();
	bool m = false;
	bool k = false;
	string aux = "";
	string* lol = NULL;
	int valor = 0;
	int n = 0;
	srand((unsigned int)time(NULL));
	if (!analizarPosiblesCuadros(m)) {
		cercano();
		cercanoCoor2();
		k = verficar();
		if (k == true) {
			lista.limpiaLista();
			lista.iniciaPrimero();
		}
		valor = lista.genCantidad();
		if (valor == 0) {
			this->recuperarPosicion();
			 k = verficar();
			 if (k == true) {
				 lista.limpiaLista();
				 lista.iniciaPrimero();
			 }
			if (lista.genCantidad() == 0) {
				this->recuperarPosicion();
				k = verficar();
				if (k == true) {
					lista.limpiaLista();
					lista.iniciaPrimero();
				}
				if (lista.genCantidad() == 0) {
					this->recuperarPosicion();
					lol = this->JugadaMasInteligente();
					aux = *lol;
					convierteValores(aux);
					lista.limpiaLista();
					lista.iniciaPrimero();
					return;
				}
			}
			valor = lista.genCantidad();
		}
		if (valor == 1) {
			n = 1 + rand() % (valor + 1 - 1);
		}
		else {
			n = 1 + rand() % (valor - 1);
		}
		lista.inicializarActual();
		string* x = lista.retornaElemento(n);
		aux = *x;
		convierteValores(aux);
		lista.limpiaLista();
		lista.iniciaPrimero();
	
	}

}

void JuegoCercano::setJugada(Jugada* jug)
{
	nueva = jug;
}

bool JuegoCercano::cercano()
{
	Coordenada* x1y1 = nueva->getCordenada1();
	Coordenada* x2y2 = nueva->getCoordenada2();
	int x1 = x1y1->obtenerX();//0
	int y1 = x1y1->obternerY();//2
	int contador = 0;
	static int p = 1;
	int  n = campito->getColumnas();
	int k = campito->getFilas();

	Componentes*** com = campito->getMatriz();

	for (int i = 0; i < campito->getFilas(); i++) {

		for (int j = 0; j < campito->getColumnas(); j++) {

			if (i == 0 && j != campito->getColumnas() - 1 && ((x1 == i && y1 == j))) {

				if (com[i + 2][j] != NULL && com[i + 1][j] == NULL) {

					ingresaVertical(i + 1,j);
				}
				if (x1 == 0 && y1 == 0) {

					if ((com[i][j + 1] == NULL)) {
						ingresaHorizontal(i, j + 1);
					}

				}
				if ((com[i][j - 1] == NULL)) {
					ingresaHorizontal(i, j - 1);
				
				}
				if ((com[i][j + 1] == NULL)) {
					ingresaHorizontal(i, j + 1);

				}


			}

			if (i == campito->getFilas() - 1 && ((x1 == i && y1 == j))) {

				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL) {

					ingresaVertical(i - 1, j);
				}

			}

			if (i == campito->getFilas() - 1 && j == 0 && ((x1 == i && y1 == j))) {

				if (com[i][j + 2] != NULL && com[i][j + 1] == NULL) {
					ingresaHorizontal(i, j + 1);

				}

			}

			if (x1 == campito->getFilas() - 1 && (x1 == i && y1 == j) && (j != 0 || j != campito->getColumnas() - 1)) {

				if ((com[i][j - 1] == NULL && com[i][j - 2] != NULL)) {
					ingresaHorizontal(i, j - 1);
				}
				if ((com[i][j + 1] == NULL && com[i][j + 2] != NULL)) {
					ingresaHorizontal(i, j + 1);

				}
			}

			if (j == 0 && ((x1 == i && y1 == j) && i != 0)) {

				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL) {
					ingresaVertical(i - 1, j);
				}

			}
			if (j == campito->getColumnas() - 1 && ((x1 == i && y1 == j) && (i == 0 || i == campito->getFilas() - 1))) {

				if (com[i][j - 2] != NULL && com[i][j - 1] == NULL) {

					ingresaHorizontal(i, j - 1);
				}

			}


			if (j == campito->getColumnas() - 1 && ((x1 == i && y1 == j) && i != 0)) {

				if (com[i][j - 2] != NULL && com[i][j - 1] == NULL) {

					ingresaHorizontal(i, j - 1);
				}

				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL && i != 0 && i != campito->getFilas() - 1) {

					ingresaVertical(i - 1, j);
				}

			}

			if (j == 0 && ((x1 == i && y1 == j))) {

				if (com[i][j + 2] != NULL && com[i][j + 1] == NULL) {

					ingresaHorizontal(i, j + 1);
				}


			}

			if ((i != 0 && i != campito->getFilas() - 1) && (j != 0 && j != campito->getColumnas() - 1) && (x1 == i && y1 == j)) {

				if (com[i][j - 2] != NULL && com[i][j - 1] == NULL) {
					ingresaHorizontal(i, j - 1);
				}

				if (com[i][j + 2] != NULL && com[i][j + 1] == NULL) {
					ingresaHorizontal(i, j + 1);
				}

				if (com[i + 2][j] != NULL && com[i + 1][j] == NULL) {
					ingresaVertical(i + 1, j);
				}

				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL) {
					ingresaVertical(i - 1, j);
				}

			}
		}

	}
	return true;
}

bool JuegoCercano::cercanoCoor2()
{
	Coordenada* x2y2 = nueva->getCoordenada2();
	int x2 = x2y2->obtenerX();//0
	int y2 = x2y2->obternerY();//2
	int contador = 0;
	static int p = 1;
	int  n = campito->getColumnas();
	int k = campito->getFilas();
	Componentes*** com = campito->getMatriz();

	for (int i = 0; i < campito->getFilas(); i++) {

		for (int j = 0; j < campito->getColumnas(); j++) {

			if (i == 0 && j != campito->getColumnas() - 1 && ((x2 == i && y2 == j))) {

				if (com[i + 2][j] != NULL && com[i + 1][j] == NULL) {

					ingresaVertical(i + 1, j);
				}
				if (x2 == 0 && y2 == 0) {

					if ((com[i][j + 1] == NULL)) {
						ingresaHorizontal(i, j + 1);

					}

				}

				if ((com[i][j - 1] == NULL)) {
					ingresaHorizontal(i, j - 1);
				}
				if ((com[i][j + 1] == NULL)) {
					ingresaHorizontal(i, j + 1);

				}


			}

			if (i == campito->getFilas() - 1 && ((x2 == i && y2 == j))) {

				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL) {

					ingresaVertical(i - 1, j);
				}

			}
			if (i == campito->getFilas() - 1 && j == 0 && ((x2 == i && y2 == j))) {

				if (com[i][j + 2] != NULL && com[i][j + 1] == NULL) {
					ingresaHorizontal(i, j + 1);

				}

			}

			if (x2 == campito->getFilas() - 1 && (x2 == i && y2 == j) && (j != 0 || j != campito->getColumnas() - 1)) {

				if ((com[i][j - 1] == NULL && com[i][j - 2] != NULL)) {
					ingresaHorizontal(i, j - 1);
				}
				if ((com[i][j + 1] == NULL && com[i][j + 2] != NULL)) {
					ingresaHorizontal(i, j + 1);
				}
			}

			if (j == 0 && ((x2 == i && y2 == j) && i != 0 && i!=campito->getFilas()-1)) {

				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL) {
					ingresaVertical(i - 1, j);
				}
				if (com[i + 2][j] != NULL && com[i + 1][j] == NULL) {
					ingresaVertical(i + 1, j);
				}
			}

			if (j == campito->getColumnas() - 1 && ((x2 == i && y2 == j) && (i == 0 || i == campito->getFilas() - 1))) {

				if (com[i][j - 2] != NULL && com[i][j - 1] == NULL) {

					ingresaHorizontal(i, j - 1);
				}

			}



			if (j == campito->getColumnas() - 1 && ((x2 == i && y2 == j) && i != 0 && i!= campito->getColumnas()-1)) {

				if (com[i][j - 2] != NULL && com[i][j - 1] == NULL) {
					ingresaHorizontal(i, j - 1);
				}
				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL && i != 0 && i != campito->getFilas() - 1) {
					ingresaVertical(i - 1, j);
				}
				if (i != campito->getFilas() - 1) {
					if (com[i + 2][j] != NULL && com[i + 1][j] == NULL && i != 0 && i != campito->getFilas() - 1) {
						ingresaVertical(i + 1, j);
					}
				}


			}

			if (j == 0 && ((x2 == i && y2 == j))) {

				if (com[i][j + 2] != NULL && com[i][j + 1] == NULL) {
					ingresaHorizontal(i, j + 1);
				}
			

			}

			if ((i != 0 && i != campito->getFilas() - 1) && (j != 0 && j != campito->getColumnas() - 1) && (x2 == i && y2 == j)) {

				if (com[i][j - 2] != NULL && com[i][j - 1] == NULL) {
					ingresaHorizontal(i, j - 1);
				}

				if (com[i][j + 2] != NULL && com[i][j + 1] == NULL) {
					ingresaHorizontal(i, j + 1);
				}

				if (com[i + 2][j] != NULL && com[i + 1][j] == NULL) {
					ingresaVertical(i + 1, j);
				}
				if (com[i - 2][j] != NULL && com[i - 1][j] == NULL) {
					ingresaVertical(i - 1, j);
				}

			}
		}

	}

	return true;
}

