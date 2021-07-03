#include "NuevePuntos.h"
NuevePuntos::NuevePuntos() :CampoAbs(5, 5)
{
	nombreMatriz = "Nueve Puntos";
}

NuevePuntos::~NuevePuntos()
{

}


bool NuevePuntos::agregar(Coordenada* x1y1, Coordenada* x2y2,int p)//2-0
{
	int x1 = x1y1->obtenerX();
	int y1 = x1y1->obternerY();
	int x2 = x2y2->obtenerX();
	int y2 = x2y2->obternerY();
	int local = 0;
	int aux = 0;


	if ((x1 >= 0 && x1 < filas) && (y1 >= 0 && y1 < columnas) && (x2 >= 0 && x2 < filas) && (y2 >= 0 && y2 < columnas)) {
		if (!estaLleno()) {

			if (matriz[x1][y1] != NULL && matriz[x2][y2] != NULL) {

				if (x1 == x2) {// impar - par
					if (y1 == y2) {
						throw new ExcepcionCoordIguales(x1y1, x2y2);
					}
					Componentes* lineaH = new LineaHorizontal();
					if (y2 > y1) {
						aux = y2 - 1;
						/*local = y2 - 2;*/
						if (y2 - y1 != 2) {
							throw new ExcepcionContiguos(x1y1, x2y2);
						}
						if (matriz[x1][aux] == NULL) {
							matriz[x1][aux] = lineaH;
							matriz[x1][aux]->setJugador(p);
							return true;
						}
						else {
							throw new ExcepcionLexistente(x1y1, x2y2);
						}
					}
					else {
						aux = y1 - 1;
						/*local = y1 - 2;*/
						if (y1 - y2 != 2) {
							throw new ExcepcionContiguos(x1y1, x2y2);
						}
						if (matriz[x1][aux] == NULL) {
							matriz[x1][aux] = lineaH;
							matriz[x1][aux]->setJugador(p);
							return true;
						}
						else {
							throw new ExcepcionLexistente(x1y1, x2y2);
						}
					}
					if (x2 == 0 && x1 == 0) {
						if (matriz[0][1] == NULL) {
							matriz[0][1] = lineaH;
							matriz[0][1]->setJugador(p);
							return true;
						}
						else {
							throw new ExcepcionLexistente(x1y1, x2y2);
						}
					}

				}
				if (y1 == y2) {// impar - par
					Componentes* lineaV = new LineaVertical();
					if (x2 == 0 && x1 == 0) {
						if (matriz[1][0] == NULL) {
							matriz[1][0] = lineaV;
							matriz[1][0]->setJugador(p);
							return true;
						}
						else {
							throw new ExcepcionLexistente(x1y1, x2y2);
						}
					}
					if (x2 > x1) {
						aux = x2 - 1;
						/*local = x2 - 2;*/
						if (x2 - x1 != 2) {
							throw new ExcepcionContiguos(x1y1, x2y2);
						}
						if (matriz[aux][y1] == NULL) {
							matriz[aux][y1] = lineaV;
							matriz[aux][y1]->setJugador(p);
							return true;
						}
						else {
							throw new ExcepcionLexistente(x1y1, x2y2);
						}
					}
					else {
						aux = x1 - 1;

						/*local = x1 - 2;*/
						if (x1 - x2 != 2) {
							throw new ExcepcionContiguos(x1y1, x2y2);
						}
						if (matriz[aux][y1] == NULL) {
							matriz[aux][y1] = lineaV;
							matriz[aux][y1]->setJugador(p);
							return true;
						}
						else {
							throw new ExcepcionLexistente(x1y1, x2y2);
						}
					}
				}
			}
			if (x1 == 2 + x2 || y1 == 2 + y2 || x2 == 2 + x1 || y2 == 2 + y1)
				throw new ExcepcionDiagonal(x1y1, x2y2);
			throw new ExcepcionContiguos(x1y1, x2y2);
		}
	}
	throw new ExcepcionMayCoInex(x1y1, x2y2);
}

string NuevePuntos::toString() const
{
	return CampoAbs::toString();
}

bool NuevePuntos::estaLleno()
{
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] == NULL) {
				return false;
			}
		}
	}
	return true;
}

bool NuevePuntos::vacio()
{
	return false;
}

bool NuevePuntos::unirCamposJuego(CampoAbs*)
{
	return false;
}

bool NuevePuntos::asignarNumeroXCuadro(int num)
{
	int contador = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 1 && j % 2 == 1 && matriz[i][j] == NULL) {
				if (matriz[i + 1][j] != NULL && matriz[i - 1][j] != NULL && matriz[i][j + 1] != NULL && matriz[i][j - 1] != NULL) {
					Componentes* numero = new Numero(num);
					matriz[i][j] = numero;
					contador++;
				}
			}
		}
	}
	if (contador == 0) {
		return false;
	}
	return true;
}

void NuevePuntos::pintarMatriz(int p)
{
	CampoAbs::pintarMatriz(p);
}
