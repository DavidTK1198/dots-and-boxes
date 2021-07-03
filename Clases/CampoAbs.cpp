#include "CampoAbs.h"
#include <Windows.h>
CampoAbs::CampoAbs(int f, int c):Componentes()
{
	filas = f;
	columnas = c;
	matriz = new Componentes * *[filas];
	for (int i = 0; i < filas; i++) {
		matriz[i] = new Componentes*[columnas];
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] = NULL;
		}
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				Componentes* circulito = new Circulo();
				matriz[i][j] = circulito;
			}
		}
	}

}

CampoAbs::~CampoAbs()
{
	for (int i = 0; i < filas; i++) {
		delete matriz[i];
	}
	delete[]matriz;
}

string CampoAbs::toString() const
{
	int contador = 0;
	stringstream s;
	s <<"  ";
	for (int i = 0; i < columnas; i++) {
		if (i == 0) {
			s << "[" << i << "]" << "  ";
			contador++;
		}
		else {
			if (i % 2 == 0 && i!=0) {
				s << "[" << 2*i-contador << "]" << "  ";
				contador++;
			}
		}
		contador++;
	}
	s << endl;
	contador = 0;
	for (int i = 0; i < filas; i++) {
		
		if (i % 2 == 0) {
			if (i == 0) {
				s << "[" << i << "]";
				contador++;
			}
			else {
				s << "[" << 2 * i - contador << "]";
				contador++;
			}
		}
		else {
			s << "   ";
			
		}
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] != NULL) {
				if (i % 2 == 1 && j % 2 == 1 && matriz[i][j]!=NULL) {
					s << " ";

				}
				s << matriz[i][j]->toString();
			if (i % 2 == 1 && j % 2 == 1) {
				s << "  ";

				}
			}
			else if(i%2 == 1 && j%2 ==0 && matriz[i][j]==NULL) {
				s <<" ";

			}
			else if(i % 2 == 0 && j % 2 == 0 && matriz[i][j] == NULL){
				s << " ";
			}
			else {
				s << "    ";
			}
		}
		s << endl;
		contador++;
	}
	return s.str();
}

int CampoAbs::getFilas()
{
	return filas;
}

int CampoAbs::getColumnas()
{
	return columnas;
}

Componentes*** CampoAbs::getMatriz()
{
	return matriz;
}

void CampoAbs::pintarMatriz(int p)///12
{
	int contador = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
	cout << "  ";
	for (int i = 0; i < columnas; i++) {
		if (i == 0) {
			cout << "[" << i << "]" << "  ";
			contador++;
		}
		else {
			if (i % 2 == 0 && i != 0) {
				cout << "[" << 2 * i - contador << "]" << "  ";
				contador++;
			}
		}
		contador++;
	}
	cout << endl;
	contador = 0;
	for (int i = 0; i < filas; i++) {

		if (i % 2 == 0) {
			if (i == 0) {
				cout << "[" << i << "]";
				contador++;
			}
			else {
				cout << "[" << 2 * i - contador << "]";
				contador++;
			}
		}
		else {
			cout << "   ";

		}
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] != NULL) {
				if (i % 2 == 1 && j % 2 == 1 && matriz[i][j] != NULL) {
					cout << " ";

				}

				Circulo* cir = dynamic_cast<Circulo*>(matriz[i][j]);

				if (cir) {	
					
					cout << matriz[i][j]->toString();
				}
				else {
						cout << matriz[i][j]->toString();
				}
				if (i % 2 == 1 && j % 2 == 1) {
					cout << "  ";

				}
			}
			else if (i % 2 == 1 && j % 2 == 0 && matriz[i][j] == NULL) {
				cout << " ";

			}
			else if (i % 2 == 0 && j % 2 == 0 && matriz[i][j] == NULL) {
				cout << " ";
			}
			else {
				cout << "    ";
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << endl;
		contador++;
	}



}

void CampoAbs::setCampo(Componentes*** com)
{
	matriz = com;
}

string adaptadorCampo::toString() const {
	return typeid(*this).name();       
};

ostream& operator << (ostream& out, const CampoAbs& a) {
	out << a.toString();
	return out;
}

int CampoAbs::determinaGanador()
{
	int contador = 0;
	int contador2 = 0;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 1 && j % 2 == 1 && matriz[i][j] != NULL) {
				Numero* numerito = dynamic_cast<Numero*>(matriz[i][j]);
				if(numerito->getNumero()==1){
					contador++;
				}
				if (numerito->getNumero() == 2) {
					contador2++;
				}
			}
		}
	}
	if (contador > contador2) {
		return 1;
	}
	if (contador2 > contador) {
		return 2;
	}
	return 0;
}
