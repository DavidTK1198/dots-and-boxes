#include "EmpresaDots.h"

EmpresaDots::EmpresaDots()
{
	dia = 1;
	precioSus = 500.0;
	arreglito = new ArregloJugador(20);
	codigo = "";
	partidas = new Lista<Partida>;
	nombre = "Empresa Dots";
	generarCodigoAut();
}

EmpresaDots::~EmpresaDots()
{
	delete arreglito;
	delete partidas;
}

void EmpresaDots::attach(Jugador* j)
{
	arreglito->agregarJugador(j);
	this->notifyV2(j);
	
}

void EmpresaDots::notify()
{
	arreglito->actualizarCodigo(codigo, precioSus);
}

void EmpresaDots::notifyV2(Jugador* j)
{
	arreglito->actualizaCodigoV2(j, codigo, precioSus);
}

void EmpresaDots::changeDay()
{
	dia++;
	if (dia == 8) {
		dia = 1;
	}
	delete arreglito;
	arreglito = NULL;
	arreglito = new ArregloJugador(20);
	this->generarCodigoAut();
}

void EmpresaDots::setCodigo(string cod)
{
	codigo = cod;
}

void EmpresaDots::generarCodigoAut()
{
	stringstream s;
	char aux;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++) {
		aux = 97 + rand()%(122 - 97);
		s << aux << i;
	}
	this->setCodigo(s.str());
}

string EmpresaDots::mostrarSuscriptores()
{
	return arreglito->toString();
}

void EmpresaDots::cargaTodo()
{
	ifstream in;
	string info = "prueba.txt";
	string num = "";
	int num2 = 0;
	Partida partidita;
	in.open(info, ios::in);
	Partida* nuevecita = NULL;
	getline(in, num, '\n');
	num2 = atoi(num.c_str());
	int contador = 0;
	while (contador < num2) {
		contador++;
		nuevecita = partidita.recuperar(in);
		partidas->agregarFinal(nuevecita);
	}
	in.close();
}

void EmpresaDots::GuardaTodo()
{
	ofstream out;
	string  info = "prueba.txt";
	Partida* nueva = NULL;
	int contador = 0;
	out.open(info, ios::out);
	out << partidas->genCantidad() << '\n';
	partidas->inicializarActual();
	while (contador<partidas->genCantidad()) {
		contador++;
		nueva = partidas->getTipo();
		nueva->guardar(out);
		partidas->siguienteNodo();
	}
	out.close();
}

Lista<Partida>* EmpresaDots::getContenedorPar()
{
	return partidas;
}

Jugador* EmpresaDots::buscarJugador(string p)
{
	return arreglito->buscarJugador(p);
}

ArregloJugador* EmpresaDots::getArreglo()
{
	return arreglito;
}

void EmpresaDots::agregaPartida(Partida* par)
{
	partidas->agregarFinal(par);
}

string EmpresaDots::toString()
{
	stringstream s;
	string m = cambiaNombreDia();
	s <<"\t\t\t"<< "-----------------------------------" << endl;
	s <<"\t\t\t" << "Precio por suscripcion: " << precioSus << " colones." << endl;
	s <<"\t\t\t" << "Dia de la semana: " <<m<<endl;
	s <<"\t\t\t" << "Codigo valido del dia: " << codigo << endl;
	s <<"\t\t\t" << "-----------------------------------" << endl;
	return s.str();

}

string EmpresaDots::cambiaNombreDia()
{
	switch (dia)
	{
	case 1:
		return "Lunes";
		break;
	case 2:
		return "Martes";
		break;
	case 3:
		return "Miercoles";
		break;
	case 4:
		return "Jueves";
		break;
	case 5:
		return "Viernes";
		break;
	case 6:
		return "Sabado";
		break;
	case 7:
		return "Domingo";
		break;
	default:
		return "Nada";
		break;
	}
	return "";
}
