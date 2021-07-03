#include "Jugador.h"
#include"EmpresaDots.h"
#include "Controlador.h"
#include "SeisPuntos.h"
#include "Componentes.h"
#include "ControlComposite.h"
#include "Partida.h"
#include "Excepciones.h"
#include <conio.h>
#include "JugadorPersona.h"
#include "Estrategia.h"
#include "JuegoPeriferico.h"
#include "JuegoAleatorio.h"
#include "JuegoCercano.h"
#include "JuegoCentral.h"
#include "JuegoIslas.h"
Coordenada* nueva();
int main() {
	Controlador control;
	system("pause");
	return 0;
}
Coordenada* nueva()
{
	Coordenada* nueva = NULL;
	string cord;
	char caracter;
	caracter = _getch();
	cord = "";
	int aux2 = 0;
	int n = 0;
	char aux = (char)8;
	string aux3;
	bool valor = false;
	if (caracter == 13) {
		caracter = 'x';
	}
	while (caracter != 13 && valor == false) {
		aux3 = "";
		aux3.push_back(caracter);
		if (aux2 = atoi(aux3.c_str()) || aux3 == "0") {
			cord.push_back(caracter);
			if (cord.size() == 1) {
				cord.push_back(',');
				cout << cord;
			}
		}
		else {
			if (aux3.length() > 0) {
				if (caracter == 8 && cord.length() > 0) {
					cord = cord.substr(0, cord.length() - 1);
					cout << aux;
				}
				if (cord.length() > 2) {
					cout << aux3;
					cout << aux;

				}
				cout << aux3;
				cout << aux;
			}
		}

		if (cord.length() == 3) {
			cout << cord[cord.length() - 1] << ")";
			caracter = (char)13;
			valor = true;
		}
		caracter = _getch();
		if (valor == false && caracter == 13) {
			caracter = 'a';
		}

	}

	aux3 = cord[0];
	cord = cord[cord.length() - 1];
	aux2 = atoi(aux3.c_str());
	n = atoi(cord.c_str());

	return nueva = new Coordenada(aux2, n);

}