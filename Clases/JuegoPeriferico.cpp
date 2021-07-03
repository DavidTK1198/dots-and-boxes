#include "JuegoPeriferico.h"
#include <time.h>

JuegoPeriferico::JuegoPeriferico(CampoAbs* x):Estrategia(x)
{
	this->nombre = "Estrategia Juego Periferico";
}

JuegoPeriferico::~JuegoPeriferico()
{
}

void JuegoPeriferico::tipoDeEstrategia()
{
	
	int lim1 = 0;
	int lim2 = campito->getFilas();
	int lim = campito->getColumnas();
	bool m = false;
	string aux = "";
	bool k = false;
	string* lol = NULL;
	int valor = 0;
	int n = 0;
	srand((unsigned int)time(NULL));
	if (!analizarPosiblesCuadros(m)) {
		ingresaLineasHorizontales();
		ingresaLineasVerticales();
		agregaLineasPerifericas(lim1, lim2, lim);
		k  = verficar();
		if (k) {
			lista.limpiaLista();
			lista.iniciaPrimero();
		}
		valor = lista.genCantidad();
		if (valor == 0) {
			cambiarPeriferia();
			k = verficar();
			if (k == true) {
				lista.limpiaLista();
				lista.iniciaPrimero();
			}
			if (lista.genCantidad()==0) {
				this->recuperarPosicion();
				k = verficar();
				if (k == true) {
					lista.limpiaLista();
					lista.iniciaPrimero();
				}
				if (lista.genCantidad()==0) {
					this->recuperarPosicion();
					lol = this->JugadaMasInteligente();
					aux = *lol;
					convierteValores(aux);
					lista.limpiaLista();
					lista.iniciaPrimero();
					return;
				}
			}
			
		}
	
		valor = lista.genCantidad();
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



bool JuegoPeriferico::ingresaLineasHorizontales()
{
	Componentes*** com = campito->getMatriz();
	string campo = typeid(*campito).name();
	if (campo == "class CampoJuego") {
		for (int i = 0; i < campito->getFilas(); i++) {
			for (int j = 0; j < campito->getColumnas(); j++) {
				if (i % 2 == 0 && j % 2 == 0 && i != campito->getFilas() - 1 && com[i][j] != NULL) {
					if (i != 0) {
						if ((com[i + 2][j] == NULL && com[i][j - 1] == NULL) || (com[i + 2][j - 2] == NULL && com[i][j-2] != NULL && com[i][j-1] == NULL)) {
						
							ingresaHorizontal(i, j - 1);
							
						}
					}
				}
			}
		}
	}
	return true;
}

bool JuegoPeriferico::ingresaLineasVerticales()
{
	Componentes*** com = campito->getMatriz();
	string x = "";
	stringstream s;
	string* aux = NULL;
	string campo = typeid(*campito).name();
	if (campo == "class CampoJuego") {
		for (int i = 0; i < campito->getFilas(); i++) {
			for (int j = 0; j < campito->getColumnas(); j++) {
				if (i % 2 == 0 && j % 2 == 0 && j != campito->getColumnas() - 1 && com[i][j] != NULL) {
					if (com[i][j + 2] == NULL && com[i-1][j]==NULL) {
						
						ingresaVertical(i - 1, j);
						
					}
					if (com[i][j - 2] == NULL && com[i - 1][j] == NULL) {
					
						ingresaVertical(i - 1, j);
					
					}

				}
			}
		}
	}

	return true;
}

void JuegoPeriferico::agregaLineasPerifericas(int lim1,int lim2,int lim3)
{

	Componentes*** com = campito->getMatriz();
		for (int i = lim1; i < lim2; i++) {
			for (int j = lim1; j <lim3; j++) {
				if (i % 2 == 0 && j % 2 == 0 && com[i][j] != NULL) {
					if (j != lim3 - 2) {
						if (((i == lim1 && com[i][j + 2] != NULL) || (i == lim2 - 1 && com[i][j + 2] != NULL)) && com[i][j+1] == NULL) {
						
							ingresaHorizontal(i, j + 1);
							
						}
					}
					if(i != lim2-1)
						if (((j == lim1 && com[i+2][j] != NULL) || (j ==lim3-1 && com[i+2][j] != NULL)) && com[i+1][j] == NULL) {
							
							ingresaVertical(i + 1, j);
						
						}
				
				}
			}
		}
	
}

bool JuegoPeriferico::cambiarPeriferia()
{

	int lim1 = 2;
	int lim2 = campito->getFilas()-2;
	int lim = campito->getColumnas()-2;
	string aux = "";
	bool k = false;
	int valor = 0;
	int n = 0;
	srand((unsigned int)time(NULL));
	if (!analizarPosiblesCuadros(k)) {
		periferiaNueva(lim1, lim2, lim);
	}
	return true;
}

void JuegoPeriferico::periferiaNueva(int lim1, int lim2, int lim3)
{
	Componentes*** com = campito->getMatriz();
	string x = "";
	stringstream s;
	string* aux = NULL;
	string campo = typeid(*campito).name();
	if (campo == "class CampoJuego") {
		for (int i = lim1; i < lim2; i++) {
			for (int j = lim1; j < lim3; j++) {
				if (i % 2 == 0 && j % 2 == 0 && com[i][j] != NULL) {
					if (j != lim3 - 1) {
						if (((i == lim1 && com[i][j + 2] != NULL) || (i == lim2 - 1 && com[i][j + 2] != NULL)) && com[i][j + 1] == NULL) {
						
							ingresaHorizontal(i, j + 1);
							
						}
					}
					
					if (i != lim2 - 1)
						if (((j == lim1 && com[i + 2][j] != NULL || (j == lim3 - 1 && com[i + 2][j] != NULL))) && com[i + 1][j] == NULL) {
							
							ingresaVertical(i + 1, j);
							
						}

				}
			}
		}
	}
}








