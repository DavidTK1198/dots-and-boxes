#include "Partida.h"


Partida::Partida(int n,Jugador* J,Jugador* j1)
{
	this->campoJuego = new ControlComposite(n);
	this->list = new Lista<Jugada>;
	jugador1 = J;
	jugador2 = j1;
}

Partida::~Partida()
{
	delete campoJuego;
	delete list;
}

Lista<Jugada>* Partida::getListaJugadas()
{
	return list;
}

ControlComposite* Partida::getCampo()
{
	return campoJuego;
}

void Partida::setControlCompo(ControlComposite* con)
{
	campoJuego = con;
}

bool Partida::agregarComponente(Coordenada* x, Coordenada* y, int p)
{
	return campoJuego->agregarComponente(x, y, p);
}

void Partida::agregarMatrizACont(CampoAbs* c)
{
	campoJuego->agregarMatrizACont(c);
}

void Partida::agregarJugada(Jugada* j)
{
	list->agregarFinal(j);
}

bool Partida::estaLleno()
{
	return campoJuego->estaLleno();
}

bool Partida::determinarNumeroXCuadroGana(int p)
{
	return campoJuego->determinarNumeroXCuadroGana(p);
}

string Partida::toString() const
{
	stringstream s;
	list->inicializarActual();
	int cont = 0;
	Jugada* jug = NULL;
	while (cont < list->genCantidad()) {
		cont++;
		jug = list->getTipo();
		s << "-----------------------------------" << endl;
		if (cont % 2 == 1) {
			s << "Movimiento de jugador..." << jugador1->getNombre() << endl;
		}
		if (cont % 2 == 0) {
			s << "Movimiento de jugador...." << jugador2->getNombre() << endl;
		}
		s << "Jugada #. " << cont << endl;
		s << "\t" << jug->toString() << endl;
		list->siguienteNodo();
	}
	return s.str();
}

void Partida::nuevoCampoXfilasIguales()
{
	campoJuego->nuevaZonaJuegoSeisXNueve();
}

void Partida::nuevaCampoXfilasDispares()
{
	campoJuego->nuevaZonaJuegoSeisXQuince();
}

void Partida::setNuevaZona(CampoAbs* c)
{
	campoJuego->setNuevaZona(c);
}

string Partida::toStringMatriz()
{
	return campoJuego->toString();
}

string Partida::mostrandoPartidas()
{
	stringstream s;
	CampoAbs* campo = NULL;
	int contador = 0;
	string m = "";
	s << "----------------------DATOS DE LA PARTIDA------------------" << endl;
	s << "Jugador 1: " << jugador1->getNombre() << " vs " << "Jugador 2: " << jugador2->getNombre() << endl;
	m = typeid(*campoJuego->getCampoAbs()).name();
	if (m == "class CampoJuego") {
		/*contador = campoJuego->getkCampoJuego();*/
		s << "La partida se desarrollo en un campo compuesto." << endl;
		//for (int i = 0; i < contador; i++) {
		//	m = campoJuego->guardaCampo(i);
		//	if (m == "class SeisPuntos") {
		//		campo = new SeisPuntos();
		//		s << campo->toString();
		//		delete campo;
		//		campo = NULL;
		//	}
		//	if (m == "class NuevePuntos") {
		//		campo = new NuevePuntos();
		//		s << campo->toString();
		//		delete campo;
		//		campo = NULL;
		//	}
		//	if (m == "class QuincePuntos") {
		//		campo = new QuincePuntos();
		//		s << campo->toString();
		//		delete campo;
		//		campo = NULL;
		//	}
		//}
		//s << endl;
	}
	else {
		m = typeid(*campoJuego->getCampoAbs()).name();
		if (m == "class SeisPuntos") {
			campo = new SeisPuntos();
			s << campo->toString();
			delete campo;
			campo = NULL;
		}
		if (m == "class NuevePuntos") {
			campo = new NuevePuntos();
			s << campo->toString();
			delete campo;
			campo = NULL;
		}
		if (m == "class QuincePuntos") {
			campo = new QuincePuntos();
			s << campo->toString();
			delete campo;
			campo = NULL;
		}
	}
	s << "----------------------------------------------------------" << endl;
	return s.str();
	
	
}

void Partida::pintaMatriz(int m)
{
	campoJuego->imprimirConColor(m);
}

void Partida::guardar(ofstream& v) {
	string camp = typeid(*campoJuego->getCampoAbs()).name();
	string aux="";
	int cont = 1;
	int co = 0;
	if (camp == "class CampoJuego") {
		int n = campoJuego->getkCampoJuego();
		v << camp << '\n';
		v << n << '\n';
		v << jugador1->getNombre() << '\n';
		v << jugador2->getNombre() << '\n';
		while (cont <= n) {
			aux = campoJuego->guardaCampo(cont);
			v << aux << "\t";
			cont++;
		}
		v << "completo"<< '\n';

		Jugada* nueva = NULL;
		list->inicializarActual();
		v << list->genCantidad() << '\n';
		while (co<list->genCantidad()) {
			co++;
			nueva = list->getTipo();
			nueva->guardaJugada(v);
			list->siguienteNodo();
		}
		v << "fin" << '\n';
	}
	else {
		v << camp << '\n';
		v << jugador1->getNombre() << '\n';
		v << jugador2->getNombre() << '\n';
		Jugada* nueva = NULL;
		list->inicializarActual();
		co = 0;
		v << list->genCantidad() << '\n';
		while (co<list->genCantidad()) {
			co++;
			nueva = list->getTipo();
			nueva->guardaJugada(v);
			list->siguienteNodo();
		}
		v << "fin" << '\n';
	}
	
}

int Partida::getCantMatCom()
{
	return campoJuego->getCantVecMat();
}

Partida* Partida::recuperar(ifstream& p)
{
	int cantM = 0;
	int contador = 0;
	int numerito = 0;
	Jugada jugadota;
	string pp = "";
	string aux1 = "";
	string cant = "";
	string jug1, jug2;
	Partida* comodin = NULL;
	Jugada* jugadita = NULL;
	Jugador* jugador = NULL;
	Jugador* jugador2 = NULL;
	CampoAbs* campo = NULL;
	CampoAbs** vec = NULL;
	string m = "";
	int contador1 = 0;
	getline(p, pp, '\n');
	if (pp == "class CampoJuego") {
		getline(p, cant, '\n');
		cantM = atoi(cant.c_str());
		getline(p, jug1, '\n');
		getline(p, jug2, '\n');
		jugador = new JugadorPersona(jug1, "", "", 0);
		if (jug2 != "CPU") {
			jugador2 = new JugadorPersona(jug2, "", "", 0);
		}
		else {
			jugador2 = new JugadorMaquina();
		}
		numerito = cantM + 1;
		comodin = new Partida(4, jugador, jugador2);
		//tenemos agregar la matriz al vector
		vec = comodin->getVector();
		while (contador < cantM+1) {
			contador++;
			if (contador == numerito) {
				getline(p, aux1, '\n');
			}
			else {
				getline(p, aux1, '\t');
			}
			contador1 = 0;
			if (comodin->getCantMatCom() == 2) {
				string type = typeid(*vec[0]).name();
				string type2 = typeid(*vec[1]).name();
				if (type == "class CampodeApoyo") {
					for (int i = 0; i < comodin->getCampo()->getkCampoJuego(); i++) {
						m = comodin->getCampo()->guardaCampo(i + 1);
						if (m == "class QuincePuntos") {
							contador1++;
						}
					}
				}

				if ((type == "class SeisPuntos" || type == "class NuevePuntos") && (type2 == "class SeisPuntos" || type2 == "class NuevePuntos")) {
					comodin->nuevoCampoXfilasIguales();
				}
				if (type == "class QuincePuntos" && type2 == "class QuincePuntos") {
					comodin->nuevoCampoXfilasIguales();
				}
				if ((type == "class SeisPuntos" || type == "class NuevePuntos") && type2 == "class QuincePuntos") {
					comodin->nuevaCampoXfilasDispares();
				}
				if (type == "class QuincePuntos" && (type2 == "class SeisPuntos" || type2 == "class NuevePuntos")) {
					comodin->nuevaCampoXfilasDispares();
				}
				if (contador1 == 0) {
					if (type2 == "class QuincePuntos" && type == "class CampodeApoyo") {
						comodin->nuevaCampoXfilasDispares();
					}
				}
				else {
					if (type2 == "class QuincePuntos" && type == "class CampodeApoyo") {
						comodin->nuevoCampoXfilasIguales();
					}
					if ((type2 == "class SeisPuntos" || type2 == "class NuevePuntos")  && type == "class CampodeApoyo") {
						comodin->nuevaCampoXfilasDispares();
					}
				}
			}
	
			if (aux1 == "class SeisPuntos") {
				campo = new SeisPuntos();
				comodin->agregarMatrizACont(campo);
			}
			if (aux1 == "class NuevePuntos") {
				campo = new NuevePuntos();
				comodin->agregarMatrizACont(campo);
			}
			if (aux1 == "class QuincePuntos") {
				campo = new QuincePuntos();
				comodin->agregarMatrizACont(campo);
			}
	
		
		}
		getline(p, aux1, '\n');
		cantM = atoi(aux1.c_str());
		contador = 0;
		while (contador < cantM) {
			contador++;
			jugadita = jugadota.cargaJugada(p);
			comodin->agregarJugada(jugadita);
		}
		getline(p, pp, '\n');
		if (pp == "fin") {
			return comodin;
		}
		
	}
	else {
		getline(p, jug1, '\n');
		getline(p, jug2, '\n');
		jugador = new JugadorPersona(jug1, "", "", 0);
		if (jug2 != "CPU") {
			jugador2 = new JugadorPersona(jug2, "", "", 0);
		}
		else {
			jugador2 = new JugadorMaquina();
		}
		
		if (pp == "class SeisPuntos") {
			comodin = new Partida(1, jugador, jugador2);
		}
		if (pp == "class NuevePuntos") {
			comodin = new Partida(2, jugador, jugador2);
		}
		if (pp == "class QuincePuntos") {
			comodin = new Partida(3, jugador, jugador2);
		}
		getline(p, aux1, '\n');
		cantM = atoi(aux1.c_str());
		contador = 0;
		while (contador < cantM) {
			contador++;
			jugadita = jugadota.cargaJugada(p);
			comodin->agregarJugada(jugadita);
		}
		getline(p, pp, '\n');
		if (pp == "fin") {
			return comodin;
		}
	}
	return nullptr;
}

CampoAbs** Partida::getVector()
{
	return campoJuego->getVector();
}

Lista<Jugada>* Partida::getListaJugada()
{
	return list;
}

int Partida::determinaGanador()
{
	return campoJuego->determinaGanador();
}

Jugada* Partida::ultimaJugada()
{
	return list->retornaElemento(list->genCantidad());
}

string Partida::toStringJugadas()
{
	return list->verLista();
}

ostream& operator<<(ostream& out, Partida& par)
{
	out << par.mostrandoPartidas() << endl;
	return out;
}
