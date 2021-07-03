#include "CampoJuego.h"

CampoJuego::CampoJuego():CampoAbs()
{
	tam = 3;
	cant = 0;
	cantAr = 0;
	campos = new CampoAbs*[tam];
	for (int i = 0; i < tam; i++) {
		campos[i] = NULL;
	}
	for (int i = 0; i < 20; i++) {
		archivos[i] = "";
	}
}

CampoJuego::~CampoJuego()
{
	for (int i = 0; i < cant; i++) {
		delete campos[i];
	}
	delete[] campos;
}

bool CampoJuego::agregar(Coordenada* x, Coordenada* y,int p)
{
	CampoAbs* cam = campos[0];
	if (cam->agregar(x, y,p)) {
		return true;
	}
	return false;
}

void CampoJuego::agregarCampos(CampoAbs* cam)
{
	if (cant < tam) {
		campos[cant++] = cam;
	}
}

string CampoJuego::toString() const
{
	stringstream s;
	if (cant == 1) {
		s << campos[0]->toString() << endl;
	}
	return s.str();
}

void CampoJuego::pintarMatriz(int p)
{
	if (cant == 1) {
		campos[0]->pintarMatriz(p);
	}
}

bool CampoJuego::estaLleno()
{
	return campos[0]->estaLleno();
}

bool CampoJuego::vacio()
{
	return false;
}

bool CampoJuego::unirCamposJuego(CampoAbs*)
{
	return false;
}

bool CampoJuego::asignarNumeroXCuadro(int p)
{
	CampoAbs* cam = campos[0];
	return cam->asignarNumeroXCuadro(p);
	
}

CampoAbs* CampoJuego::seisPuntosXnuevePuntos()//Version 1.0
{
	CampoAbs* comodin1 = NULL;
	CampoAbs* comodin2 = NULL;
	CampoAbs* nuevoCampo = NULL;
	Componentes*** aux = NULL;
	Componentes*** aux2 = NULL;
	int sumaFilas = 0;
	int sumaColumnas = 0;
	if (cant == 2) {
		comodin1 = campos[0];
		comodin2 = campos[1];
		if (comodin1->getFilas() == comodin2->getFilas()) {//5
			sumaColumnas = comodin1->getColumnas() + comodin2->getColumnas() + 1;//3+5--->8
			nuevoCampo = new CampodeApoyo(comodin1->getFilas(), sumaColumnas);
			aux = nuevoCampo->getMatriz();
			aux2 = comodin1->getMatriz();
			for (int i = 0; i < comodin1->getFilas(); i++) {
				for (int j = 0; j < comodin1->getColumnas(); j++) {
					aux[i][j] = aux2[i][j];
				}
			}
			for (int z = 0; z < cant; z++) {
				string aux = typeid(*campos[z]).name();
				agregarArchivos(aux);
				campos[z] = NULL;
				
			}
			cant = 0;
			return nuevoCampo;
		}
	}
	return NULL;

}

CampoAbs* CampoJuego::GrandeConCualquierPequenia()//Version 2
{
	CampoAbs* comodin1 = NULL;
	CampoAbs* comodin2 = NULL;
	CampoAbs* nuevoCampo = NULL;
	Componentes*** aux = NULL;
	Componentes*** aux2 = NULL;
	int sumaFilas = 0;
	int sumaColumnas = 0;
	int contador = 0;
	int ayudante = 0;
	if (cant == 2) {
		comodin1 = campos[0];
		comodin2 = campos[1];
		aux2 = comodin1->getMatriz();
		for (int i = 0; i < comodin1->getFilas(); i++) {
			for (int j = 0; j < comodin1->getColumnas(); j++) {
				if (i % 2 == 0 && j % 2 == 0 && aux2[i][j] == NULL) {
					contador++;
				}
			}
		}

		if (comodin1->getFilas() != comodin2->getFilas() && comodin1->getFilas()>comodin2->getFilas()) {//5
			sumaColumnas = comodin1->getColumnas() + comodin2->getColumnas() + 1;//11
			nuevoCampo = new CampodeApoyo(comodin1->getFilas(), sumaColumnas);//(9,11)
			aux = nuevoCampo->getMatriz();
			for (int i = 0; i < comodin1->getFilas(); i++) {
				for (int j = 0; j < comodin1->getColumnas(); j++) {
					aux[i][j] = aux2[i][j];
				}
			}
			int m = 0;
			m = comodin1->getFilas() - comodin2->getFilas();//9-5--->4
			if (contador > 1) {
				ayudante = comodin1->getColumnas() + 1;
			}
			else {
				ayudante = comodin1->getColumnas() + 1;//3
			}
			for (int p = m + 2; p < comodin1->getFilas(); p++) {//matriz[6][
				for (int h = ayudante; h < sumaColumnas; h++) {
					if (p % 2 == 0 && h % 2 == 0 && aux[p][h] != NULL) {
						delete aux[p][h];
						aux[p][h] = NULL;
					}
				}
			}
		
			for (int z = 0; z < cant; z++) {
				string aux = typeid(*campos[z]).name();
				agregarArchivos(aux);
				campos[z] = NULL;
			}
			cant = 0;
			return nuevoCampo;
		}
		else {
			sumaColumnas = comodin1->getColumnas() + comodin2->getColumnas() + 1;//11
			nuevoCampo = new CampodeApoyo(comodin2->getFilas(), sumaColumnas);//(9,11)
			aux = nuevoCampo->getMatriz();
			aux2 = comodin1->getMatriz();
			for (int i = 0; i < comodin1->getFilas(); i++) {
				for (int j = 0; j < comodin1->getColumnas(); j++) {
					aux[i][j] = aux2[i][j];
				}
			}
		
			for (int p = comodin1->getFilas(); p < comodin2->getFilas(); p++) { //p = 5 --->9
				for (int h = 0; h < comodin1->getColumnas(); h++) {//0--->4
					if (p % 2 == 0 && h % 2 == 0 && aux[p][h] != NULL) {
						delete aux[p][h];
						aux[p][h] = NULL;
					}
				}
			}
			for (int z = 0; z < cant; z++) {
				string aux = typeid(*campos[z]).name();
				agregarArchivos(aux);
				campos[z] = NULL;
			}
			cant = 0;
			return nuevoCampo;
		}
	}
	return NULL;

}

void CampoJuego::agregarArchivos(string arr)
{
	if (cantAr < 20) {
		archivos[cantAr++] = arr;
	}
}

int CampoJuego::obtenerK() {
	return cantAr;
}

string CampoJuego::recuperarClase(int i) {
	return archivos[i - 1];
}

int CampoJuego::getCantidad()
{
	return cant;
}

CampoAbs** CampoJuego::getVector()
{
	return campos;
}

int CampoJuego::determinaGanador()
{
	return campos[0]->determinaGanador();
}

int CampoJuego::getFilas()
{
	return campos[0]->getFilas();
}

int CampoJuego::getColumnas()
{
	return campos[0]->getColumnas();
}

Componentes*** CampoJuego::getMatriz()
{
	return campos[0]->getMatriz();
}

