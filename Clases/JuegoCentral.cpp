#include "JuegoCentral.h"
#include <time.h>
JuegoCentral::JuegoCentral(CampoAbs* c):Estrategia(c)
{
	this->nombre = "Estrategia Central";
	lim1 = ((campito->getColumnas()-1)/2) + 2;// 4----> 6
	lim2 = ((campito->getColumnas()-1)/2) - 2;//4---->2
}

JuegoCentral::~JuegoCentral()
{
}

void JuegoCentral::tipoDeEstrategia()
{
	bool m = false;
	bool p = false;
	string aux = "";
	int valor = 0;
	int n = 0;
	string* lol = NULL;
	srand((unsigned int)time(NULL));
	Componentes*** com = campito->getMatriz();
	if (!analizarPosiblesCuadros(m)) {
		lista.inicializarActual();
		while (verficar() && lim2 != -1 && lim2 != 0) {
			lista.limpiaLista();
			lista.iniciaPrimero();
			m = devuelveCuadradoMasCentrico();
		
		}
		if (lim2 == -1 || lim2 == 0) {
			m = devuelveCuadradoMasCentrico();
			p = verficar();
			if (p) {
				lista.limpiaLista();
				lista.iniciaPrimero();
			}
			if (lista.genCantidad() == 0) {
				this->recuperarPosicion();
				p = verficar();
				if (p) {
					lista.limpiaLista();
					lista.iniciaPrimero();
					this->recuperarPosicion();
					lol = JugadaMasInteligente();
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

bool JuegoCentral::devuelveCuadradoMasCentrico()
{
	int contador = 0;
	int u = 0;
	int aux = 3;
	int j = (campito->getColumnas() - 1) / 2;
	u = lim1;
	int p = (campito->getFilas() - 1) / 2;
	int h = p - p + 1;
	static int cont1, cont2 = 0;//Verificar despues
	Componentes*** com = campito->getMatriz();
	if (lim2 % 2 == 0) {
		aux = ayudante(p,j);
		if (aux != 0) {
			return true;
		}
		if (lim1 % 2 == 0 && lim2 % 2 == 0 && lim1 >= 0) {
			contador = ayudantePar(lim2, lim1, h);
			if ((contador == 0 && lim2 == 0) || (contador == 1 && lim2 == 0)) {
				recuperaPedazosPerdidos();
				completaEstrategia();
				return true;
			}
			return true;

		}
	}
	else {
		if (com[p][j] == NULL) {
			ingresaHorizontal(p, j);
			if (lista.genCantidad() == 1) {
				return true;
			}
			
		}
	
	}
	

	if ((lim1 % 2 == 1 && lim2 % 2 == 1 && lim1 >= 0 ) || lim2 ==-1) {
		contador = ayudanteImpar(lim2, lim1, h);
		if ((contador == 0 && lim2 == -1) || (contador == 1 && lim2 == -1)) {
			recuperaPedazosPerdidos();
			completaEstrategia();
			cout << lista.verLista() << endl;

			return true;
		}
		else {
			return true;
		}
	
	}
	return false;


}

int JuegoCentral::ayudante(int n,int m)
{
	int contador = 0;
	Componentes*** com = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {
			if (i == n && j == m) {
				if (com[i - 1][j] == NULL && com[i - 2][j] != NULL) {//3,4V
					if (ingresaVertical(i - 1, j) == true) {
						contador++;
					}
				}
				if (com[i + 1][j] == NULL && com[i + 2][j] != NULL) {
					if (ingresaVertical(i + 1, j) == true) {
						contador++;
					}
				}
				if (com[i][j + 1] == NULL && com[i][j + 2] != NULL) {
					if (ingresaHorizontal(i, j + 1) == true) {
						contador++;
					}
				}

				if (com[i][j - 1] == NULL && com[i][j-2] != NULL) {
					if (ingresaHorizontal(i, j - 1) == true) {
						contador++;
					}
				}

			}
		}
	}
	if (contador == 0) {
		return 0;
	}
	return 1;

}

int JuegoCentral::ayudanteImpar(int min, int max,int fil)
{
	int cont = 0;
	int cont1 = 0;
	string m = "";
	m = typeid(*campito).name();
	if (m == "class CampoJuego") {
		for (int i = 0; i < campito->obtenerK(); i++) {
			m = campito->recuperarClase(i + 1);
			if (m == "class QuincePuntos") {
				cont++;
			}
		}
	}
	int ayudante = campito->getFilas() - 2;
	if (min == 0) {
		min -= 1;
		max += 1;
		ayudante += 2;
	}
	
	int contador = 0;
	Componentes*** com = campito->getMatriz();
	for (int i = fil; i < ayudante; i++) {
		for (int j = min+1; j <= max-1; j++) {
			if (i % 2 == 0 && j % 2 == 0 && com[i][j] != NULL) {
				if (com[i][j+1]==NULL && com[i][j+2]!=NULL && j!=max-1) {
					if (ingresaHorizontal(i, j + 1) == true) {
						contador++;
					}
				}
				if (com[i + 1][j] == NULL && com[i + 2][j] != NULL && i!=ayudante-1) {
					if (ingresaVertical(i + 1, j) == true) {
						contador++;
					}
				}
			
					if (cont == 0) {
						if (com[i - 1][j] == NULL && com[i - 2][j] != NULL) {
							if (ingresaVertical(i - 1, j) == true) {
								contador++;
							}
						}
					}
			}

		}
	}
	lista.inicializarActual();
	movimientosNoPermitidos.inicializarActual();
	string* au = NULL;
	while (cont1 < movimientosNoPermitidos.genCantidad()) {
		cont1++;
		au = movimientosNoPermitidos.getTipo();
		if (lista.buscaElemento(*au)) {
			lista.eliminar(au);
		}
		movimientosNoPermitidos.siguienteNodo();
	}


	if (lista.genCantidad() != 0) {
		return 1;
	}
	else {
		if ((lim2 % 2 == 0 && lim2 >= 2)) {
			lim1 += 2;
			lim2 -= 2;
			return 0;
		}
		if ((lim2 % 2 == 1 && lim2 >= 1)) {
			lim1 += 2;
			lim2 -= 2;
			return 0;
		}
	}

	return 0;
}

int JuegoCentral::ayudantePar(int min, int max, int fil)
{
	int cont = 0;
	int cont1 = 0;
	string m = "";
	int ayudante = campito->getFilas() - 2;
	m = typeid(*campito).name();
	if (m == "class CampoJuego") {
		for (int i = 0; i < campito->obtenerK(); i++) {
			m = campito->recuperarClase(i + 1);
			if (m == "class QuincePuntos") {
				cont++;
			}
		}
	}
	int contador = 0;
	Componentes*** com = campito->getMatriz();
	for (int i = fil; i < ayudante; i++) {
		for (int j = min ; j <= max ; j++) {
			if (i % 2 == 0 && j % 2 == 0 && com[i][j] != NULL) {
				if (i % 2 == 0 && j % 2 == 0 && com[i][j] != NULL) {
					if (cont == 0) {
						if (com[i - 1][j] == NULL && com[i - 2][j] != NULL) {
							if (ingresaVertical(i - 1, j) == true) {
								contador++;
							}
						}
					}
					
						if (com[i + 1][j] == NULL && com[i + 2][j] != NULL && i!=max) {
							if (ingresaVertical(i + 1, j) == true) {
								contador++;
							}
						}
					
					if (com[i][j + 1] == NULL && com[i][j+2] !=NULL && j!=max) {
						if (ingresaHorizontal(i, j + 1) == true) {
							contador++;
						}
					}
					

				}
			}
			

		}
	}
	lista.inicializarActual();
	movimientosNoPermitidos.inicializarActual();
	string* au = NULL;
	while (cont1<movimientosNoPermitidos.genCantidad()) {
		cont1++;
		au = movimientosNoPermitidos.getTipo();
		if (lista.buscaElemento(*au)) {
			lista.eliminar(au);
		}
		movimientosNoPermitidos.siguienteNodo();
	}

	if (lista.genCantidad() != 0) {
		return 1;
	}
	else {
		if ((lim2 % 2 == 0 && lim2 >=2)) {
			lim1 += 2;
			lim2 -= 2;
			return 0;
		}
		if ((lim2 % 2 == 1 && lim2 >= 3)) {
			lim1 += 2;
			lim2 -= 2;
			return 0;
		}
	}
	return 0;
}

bool JuegoCentral::completaEstrategia()
{
	Componentes*** com = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {
			if (i % 2 == 0 && j % 2 == 0 && com[i][j] != NULL) {
				if ((i == 0 || i == campito->getFilas()-1) && j != campito->getColumnas() - 1 && com[i][j+1] == NULL && com[i][j+2] != NULL) {
					ingresaHorizontal(i, j+1);
				}
				if ((j == 0 || j == campito->getColumnas()-1) && i != campito->getFilas()- 1 && com[i+1][j] == NULL && com[i+2][j] != NULL) {
					ingresaVertical(i + 1, j);
				}
				if (j == 0 && i != campito->getFilas() - 1 && com[i][j+1]==NULL) {
					ingresaHorizontal(i, j + 1);
				}
				if (j == campito->getColumnas()-1 && i != campito->getFilas() - 1 && com[i][j - 1] == NULL) {
					ingresaHorizontal(i, j - 1);
				}
			}

		}
	}
	if (lista.genCantidad() != 0) {
		return true;
	}
	return false;
}

bool JuegoCentral::recuperaPedazosPerdidos()
{
	Componentes*** com = campito->getMatriz();
	int cont = 0;
	string m = "";
	m = typeid(*campito).name();
	if (m == "class CampoJuego") {
		for (int i = 0; i < campito->obtenerK(); i++) {
			m = campito->recuperarClase(i + 1);
			if (m == "class QuincePuntos") {
				cont++;
			}
		}
	}
	if (cont != 0) {
		for (int i = 2; i < campito->getColumnas()-2; i++) {
			if (com[0][i] != NULL && i % 2 == 0) {
				if (com[1][i] == NULL) {
					ingresaVertical(1, i);
				}
			}
		}
		for (int i = 2; i < campito->getColumnas() - 2; i++) {
			if (com[campito->getFilas()-1][i] != NULL && i % 2 == 0) {
				if (com[campito->getFilas()-2][i] == NULL) {
					ingresaVertical(campito->getFilas() - 2, i);
				}//
			}
		}
	}
	else {
		return false;
	}
	return true;
}


