#include "Excepciones.h"
#define _SALTO_LINEA_ '\n'

int Excepciones::excepcionValor(int min, int max)
{
	int p = 0;
	if (cin >> p) {
		if (p < min) {
			throw new ExcepcionRangoInferior(min, max, p);
		}
		if (p > max) {
			throw new ExcepcionRangoSuperior(min, max, p);
		}
	}
	else {
		string k;
		throw k;
	}
	return p;
}

int Excepciones::validarInfo(int m, int max)
{
	bool finalizado = false;
	int n = 0;
	while (!finalizado) {
		try {
			n = excepcionValor(m, max);
			cout << "El valor " << n << " es correcto y aceptado." << endl;
			finalizado = true;
		}
		catch (string m) {
			cout << "Error: El valor ingresado no es un numero." << endl;

		}
		catch (ExcepcionRango* m) {
			cout << m->toString() << endl;
		}

		if (!finalizado) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return n;
}


int Excepciones::ExcepcionSoloNumeros()
{
	bool f = false;
	int m = 0;
	while (!f)
	{
		try {
			m = validarSoloNum();
			f = true;

		}

		catch (string n) {

			cout << "Error: Caracteres invalidos." << endl;
			cout << "Solo se permiten numeros." << endl;
		}
		if (!f) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return m;
}

int Excepciones::validarSoloNum()
{
	int p = 0;
	if (cin >> p) {
		return p;
	}
	string k;
	throw k;
}

bool Excepciones::validarExcAgregar(Coordenada* x, Coordenada* y,ControlComposite* c,int p)
{
	bool aux = false;
		try {
			aux = c->agregarComponente(x,y,p);
			return true;
		}
		catch (ExcepcionAgregar* e) {
			cout << e->toString() << endl;
		}
	return false;
}






