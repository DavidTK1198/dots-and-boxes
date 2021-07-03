#include "Estrategia.h"

Estrategia::Estrategia(CampoAbs* c)
{
	campito = c;
	ultima = NULL;
	nombre = "";
}

bool Estrategia::analizarPosiblesCuadros(bool p)
{
	int contador = 0;
	Linea* lin = NULL;
	string* k = NULL;
	Coordenada* coord = NULL;
	Coordenada* coord2 = NULL;
	Componentes*** com = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {
			if (i % 2 == 1 && j % 2 == 1 && com[i][j] == NULL) {
				if (com[i + 1][j] != NULL) {
					contador++;
				}
				if (com[i - 1][j] != NULL) {
					contador++;
				}
				if (com[i][j+1] != NULL) {
					contador++;
				}
				if (com[i][j-1] != NULL) {
					contador++;
				}
			
				if (contador == 3) {
					if (com[i][j - 1] == NULL) {
						lin = new LineaVertical();
						com[i][j - 1] = lin;
						com[i][j - 1]->setJugador(2);
						k = LineaV(i, j - 1);
						coord = convierteCoorAba(i, j - 1);
						coord2 = convierteCoorArri(i, j - 1);
						ultima = new Jugada(coord, coord2);
						if (movimientosNoPermitidos.buscaElemento(*k)) {
							movimientosNoPermitidos.eliminar(k);
						}
						return true;
					}
					if (com[i][j + 1] == NULL) {
						lin = new LineaVertical();
						com[i][j + 1] = lin;
						com[i][j + 1]->setJugador(2);
						k = LineaV(i, j + 1);
						coord = convierteCoorAba(i, j + 1);
						coord2 = convierteCoorArri(i, j + 1);
						ultima = new Jugada(coord, coord2);
						if (movimientosNoPermitidos.buscaElemento(*k)) {
							movimientosNoPermitidos.eliminar(k);
						}
						return true;
					}
					if (com[i+1][j] == NULL) {
						lin = new LineaHorizontal();
						com[i+1][j] = lin;
						com[i+1][j]->setJugador(2);
						k = LineaH(i+1, j);
						coord = convierteCoordDer(i + 1, j);
						coord2 = convierteCoordIzq(i + 1, j);
						ultima = new Jugada(coord, coord2);
						if (movimientosNoPermitidos.buscaElemento(*k)) {
							movimientosNoPermitidos.eliminar(k);
						}
						return true;
					}
					if (com[i-1][j] == NULL) {
						lin = new LineaHorizontal();
						com[i-1][j] = lin;
						com[i-1][j]->setJugador(2);
						k = LineaH(i - 1, j);
						coord = convierteCoordDer(i - 1, j);
						coord2 = convierteCoordIzq(i - 1, j);
						ultima = new Jugada(coord, coord2);
						if (movimientosNoPermitidos.buscaElemento(*k)) {
							movimientosNoPermitidos.eliminar(k);
						}
						return true;
					}
				}
			}
			contador = 0;
			
		}
	}
	return false;
}

bool Estrategia::recuperarPosicion()
{
	
	int contador = 0;
	static int p = 1;
	int  n = campito->getColumnas();
	int k = campito->getFilas();
	Linea* lin = NULL;
	Componentes*** com = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {
				if (i % 2 == 1 && j % 2 == 1 && com[i][j] == NULL) {

					if (com[i - 1][j - 1] != NULL && com[i - 1][j + 1] != NULL && com[i + 1][j - 1] != NULL && com[i + 1][j + 1] != NULL) {

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
	}
	return true;
}
bool Estrategia::verficar()
{
	
	string* test;
	string* prueba;
	Lista<string> nueva;
	int contador = 0;
	Lista<string> aux4;
	Linea* lin = NULL;
	Componentes*** com = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {

			if (i % 2 == 1 && j % 2 == 1 && com[i][j] == NULL) {

				if (com[i - 1][j - 1] != NULL && com[i - 1][j + 1] != NULL && com[i + 1][j - 1] != NULL && com[i + 1][j + 1] != NULL) {

					if (com[i + 1][j] != NULL) {
						contador++;
					}
					if (com[i - 1][j] != NULL) {
						contador++;
					}
					if (com[i][j + 1] != NULL) {
						contador++;
					}
					if (com[i][j - 1] != NULL) {
						contador++;
					}
					if (contador == 2) {
						if (com[i][j - 1] == NULL) {
							
							test = LineaV(i,j-1);
							if (nueva.buscaElemento(*test) == false) {
								nueva.agregarFinal(test);
							}
							
						}
						if (com[i][j + 1] == NULL) {
						
							test = LineaV(i, j + 1);
							if (nueva.buscaElemento(*test) == false) {
								nueva.agregarFinal(test);
							}
							

						}
						if (com[i + 1][j] == NULL) {
						
							test = LineaH(i+1, j);
							if (nueva.buscaElemento(*test) == false) {
								nueva.agregarFinal(test);
							}

						}
						if (com[i - 1][j] == NULL) {
			
							test = LineaH(i-1, j);
							if (nueva.buscaElemento(*test) == false) {
								nueva.agregarFinal(test);
							}

						}
					}
				}
			}
			contador = 0;
		}
	}
	//cout << nueva.verLista() << endl;
	contador = 0;
	nueva.inicializarActual();
	movimientosNoPermitidos.inicializarActual();
	lista.inicializarActual();
	while (lista.genCantidad() > contador) {
		contador++;
		prueba = lista.getTipo();

		if (nueva.buscaElemento(*prueba) == false) {
			prueba = new string(*prueba);
			if (aux4.buscaElemento(*prueba)==false) {
				aux4.insertaObjeto(prueba);
			}
		}
		else {
			prueba = new string(*prueba);
			if (movimientosNoPermitidos.buscaElemento(*prueba) == false) {
				movimientosNoPermitidos.insertaObjeto(prueba);
			
				contador = 0;
			
			}
			
			
		}
		lista.siguienteNodo();
		

	}
	corroboraMovimientosLegales();
	if (aux4.genCantidad() == 0) {//Guarda los movimientos permitidos   -----> Guarde los movimientos restringidos
		return true;
	}
	else {
		contador = 0;
		nueva.limpiaLista();
		lista.limpiaLista();
		lista.iniciaPrimero();
		aux4.inicializarActual();
		while (aux4.genCantidad() > contador) {
			contador++;
			prueba = aux4.getTipo();
			prueba = new string(*prueba);
			lista.insertaObjeto(prueba);
			aux4.siguienteNodo();
		}
	}
	corroboraMovimientosLegales();
	return false;
}



bool Estrategia::ingresaVertical(int n , int m)
{
	stringstream aux;
	string x = "";
	string* test;
	x = "V";
	aux << n << "," << m << x;
	test = new string(aux.str());
	if (lista.buscaElemento(aux.str()) == false) {
		lista.agregarFinal(test);
		return true;
	}

	return false;
}

bool Estrategia::ingresaHorizontal(int n , int m)
{
	stringstream aux;
	string x = "";
	string* test;
	x = "H";
	aux << n << "," << m << x;
	test = new string(aux.str());
	if (lista.buscaElemento(aux.str()) == false) {
		lista.agregarFinal(test);
		return true;
	}

	return false;
}

string* Estrategia::LineaV(int n , int m)
{
	stringstream aux;
	string x = "";
	string* test;
	x = "V";
	aux << n << "," << m << x;
	test = new string(aux.str());
	return test;
}

string* Estrategia::LineaH(int n , int m)
{
	stringstream aux;
	string x = "";
	string* test;
	x = "H";
	aux << n << "," << m << x;
	test = new string(aux.str());
	return test;
}

Jugada* Estrategia::retornaUltima()
{
	return ultima;
}

bool Estrategia::convierteValores(string aux)
{
	string aux3 = "";
	Linea* li = NULL;
	string aux2 = "";
	Coordenada* cor1 = NULL;
	Coordenada* cor2 = NULL;
	int x1 = 0;
	int y = 0;
	Componentes*** com = campito->getMatriz();
	if (aux[aux.size() - 1] == 'V') { 
		if (aux.size() == 5) {
			li = new LineaVertical();
			aux3 = aux[aux.size() - 3];
			aux2 = aux[aux.size() - 2];
			aux2 = aux3 + aux2;
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
			cor1 = convierteCoorAba(x1, y);
			cor2 = convierteCoorArri(x1, y);
			com[x1][y] = li;
			com[x1][y]->setJugador(2);
			ultima = new Jugada(cor1,cor2);
			return true;
		}
		else {
			li = new LineaVertical();
			aux2 = aux[2];
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
			cor1 = convierteCoorAba(x1, y);
			cor2 = convierteCoorArri(x1, y);
			com[x1][y] = li;
			com[x1][y]->setJugador(2);
			ultima = new Jugada(cor1, cor2);
			return true;
		}
	}

	if (aux[aux.size() - 1] == 'H') {
		if (aux.size() == 5) {
			li = new LineaHorizontal();
			aux3 = aux[aux.size() - 3];
			aux2 = aux[aux.size() - 2];
			aux2 = aux3 + aux2;
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
			cor1 = convierteCoordDer(x1, y);
			cor2 = convierteCoordIzq(x1, y);
			com[x1][y] = li;
			com[x1][y]->setJugador(2);
			ultima = new Jugada(cor1, cor2);
			return true;

		}
		else {
			li = new LineaHorizontal();
			aux2 = aux[2];
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
			cor1 = convierteCoordDer(x1, y);
			cor2 = convierteCoordIzq(x1, y);
			com[x1][y] = li;
			com[x1][y]->setJugador(2);
			ultima = new Jugada(cor1,cor2);
			return true;
		}
	}
	return false;
}

Coordenada* Estrategia::convierteCoordDer(int num,int num2)
{

	Coordenada* cor = NULL;
	num2--;
	cor = new Coordenada(num/2, num2/2);
	return cor;


}

Coordenada* Estrategia::convierteCoordIzq(int num,int num2)
{
	Coordenada* cor = NULL;
	num2++;
	cor = new Coordenada(num/2, num2/2);
	return cor;
	
}

Coordenada* Estrategia::convierteCoorArri(int num, int num2)
{
	Coordenada* cor = NULL;
	num++;
	cor = new Coordenada(num/2, num2/2);
	return cor;
}

Coordenada* Estrategia::convierteCoorAba(int num, int num2)
{
	Coordenada* cor = NULL;
	num--;
	cor = new Coordenada(num/2, num2/2);
	return cor;
}

string Estrategia::getNombreEst()
{
	return nombre;
}

int Estrategia::valoraPosibilidades()
{
	int contador = 0;
	int contador2 = 0;
	int ayudante = 0;
	stringstream s;
	stringstream ayuda;
	Linea* lin = NULL;
	string* k = NULL;
	Componentes*** com = campito->getMatriz();
	do {
		for (int i = 0; i < campito->getFilas(); i++) {
			for (int j = 0; j < campito->getColumnas(); j++) {
				ayudante = 0;
				if (i % 2 == 1 && j % 2 == 1 && com[i][j] == NULL) {
					if (com[i + 1][j] != NULL) {
						contador++;
					}
					if (com[i - 1][j] != NULL) {
						contador++;
					}
					if (com[i][j + 1] != NULL) {
						contador++;
					}
					if (com[i][j - 1] != NULL) {
						contador++;
					}

					if (contador == 3) {
						if (com[i][j - 1] == NULL) {
							lin = new LineaVertical();
							com[i][j - 1] = lin;
							if (j - 1 >= 10) {
								ayuda << i << j - 1;
							}
							else {
								s << i << j - 1;
							}
							i = 0;
							j = 0;
							contador2++;
							ayudante++;

						}
						if (i != 0 && j != 0) {
							if (com[i][j + 1] == NULL) {
								lin = new LineaVertical();
								com[i][j + 1] = lin;
								if (j + 1 >= 10) {
									ayuda << i << j + 1;
								}
								else {
									s << i << j + 1;
								}
								i = 0;
								j = 0;
								contador2++;
								ayudante++;
							}
						}
						if (i != 0 && j != 0) {
							if (com[i + 1][j] == NULL) {
								lin = new LineaHorizontal();
								com[i + 1][j] = lin;
								if (j >= 10) {
									ayuda << i+1 << j ;
								}
								else {
									s << i+1 << j;
								}
								i = 0;
								j = 0;
								contador2++;
								ayudante++;
							}
						}
						if (i != 0 && j != 0) {
							if (com[i - 1][j] == NULL) {
								lin = new LineaHorizontal();
								com[i - 1][j] = lin;
								if (j >= 10) {
									ayuda << i - 1 << j;
								}
								else {
									s << i - 1 << j;
								}
								i = 0;
								j = 0;
								contador2++;
								ayudante++;
							}
						}
					}
				}
				contador = 0;

			}
		}
	} while (ayudante != 0);
	string k1 = "";
	string g = s.str();
	string junior = ayuda.str();
	string c1 = "";
	string c2 = "";
	string c3 = "";
	stringstream ay;
	int cc1 = 0;
	int cc2 = 0;
	int cc3 = 0;
	int finalmoment = 0;
	int contadorcito = 0;
	int contadorsote = 0;
	
	for (int p = 0; p < g.size(); p+=2) {
		c1 = g[p];
		contadorcito = p + 1;
		c2 = g[contadorcito];
		cc1 = stoi(c1.c_str());
		cc2 = stoi(c2.c_str());
		delete com[cc1][cc2];
		com[cc1][cc2] = NULL;
	}
	for (int p = 0; p < junior.size(); p += 3) {
		c1 = junior[p];
		contadorcito = p + 1;
		contadorsote = p + 2;
		c2 = junior[contadorcito];
		c3 = junior[contadorsote];
		cc1 = stoi(c1.c_str());
		cc2 = stoi(c2.c_str());
		cc3 = stoi(c3.c_str());
		ay << cc2 << cc3;
		k1 = ay.str();
		finalmoment = stoi(k1.c_str());
		delete com[cc1][finalmoment];
		com[cc1][finalmoment] = NULL;
		ay.str("");
	}
	return contador2;
}

int Estrategia::posibilidades(string aux)
{
	Linea* lineacita = NULL;
	string aux3 = "";
	string aux2 = "";
	int ayudante = 0;
	int x1 = 0;
	int y = 0;
	Componentes*** com = campito->getMatriz();
	char z = aux[aux.size() - 1];
	if (aux[aux.size() - 1] == 'V') {
		if (aux.size() == 5) {
			aux3 = aux[aux.size() - 3];
			aux2 = aux[aux.size() - 2];
			aux2 = aux3 + aux2;
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());

		}
		else {
			aux2 = aux[2];
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
		
		}
	}

	if (aux[aux.size() - 1] == 'H') {
		if (aux.size() == 5) {
			aux3 = aux[aux.size() - 3];
			aux2 = aux[aux.size() - 2];
			aux2 = aux3 + aux2;
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
			

		}
		else {
			aux2 = aux[2];
			aux = aux[0];
			x1 = atoi(aux.c_str());
			y = atoi(aux2.c_str());
		
		}
	}

	if (z == 'V') {
		lineacita = new LineaVertical();
		com[x1][y] = lineacita;
	}
	if (z == 'H') {
		lineacita = new LineaHorizontal();
		com[x1][y] = lineacita;
	}
	ayudante = valoraPosibilidades();
	delete com[x1][y];
	com[x1][y] = NULL;
	return ayudante;
}

string* Estrategia::JugadaMasInteligente()
{
	int cantidad = lista.genCantidad();
	int contador = 0;
	int ayudante = 0;
	string* obj = NULL;
	string* objImpor = NULL;
	lista.inicializarActual();
	int cont = 0;
	while (contador < cantidad) {
		contador++;
		obj = lista.getTipo();
		cont = posibilidades(*obj);
		if ((cont <= ayudante) || contador == 1) {
			ayudante = cont;
			if (contador != 1) {
				objImpor = obj;
			}
		}
		lista.siguienteNodo();
	}
	return objImpor;
}

void Estrategia::corroboraMovimientosLegales()
{
	movimientosNoPermitidos.inicializarActual();
	lista.inicializarActual();
	int contador = 0;
	string* aux = NULL;
	while (contador < lista.genCantidad()) {
		contador++;
		aux = lista.getTipo();
		if (movimientosNoPermitidos.buscaElemento(*aux) == true) {
			lista.eliminar(aux);
		}
		lista.siguienteNodo();
	}

}
