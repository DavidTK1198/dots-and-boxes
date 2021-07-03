#include "Jugada.h"
#include <fstream>

Jugada::Jugada(Coordenada* x, Coordenada* y) 
{
	this->cord1 = x;
	this->cord2 = y;
	
}

Jugada::~Jugada()
{
}

Coordenada* Jugada::getCordenada1()
{
	return cord1;
}

Coordenada* Jugada::getCoordenada2()
{
	return cord2;
}

string Jugada::toString()
{
	stringstream s;
	s <<"[ "<< cord1->toString() << "," << cord2->toString() <<" ]"<< endl;
	return s.str();

}

void Jugada::guardaJugada(ofstream& sali)
{
	sali << cord1->obtenerX()<<','<< cord1->obternerY()<<'\t'<<cord2->obtenerX()<<','<< cord2->obternerY() << '\n';
}

Jugada* Jugada::cargaJugada(ifstream& entrada)
{
    int xx1 = 0;
    int xx2 = 0;
    int yy1 = 0;
    int yy2 = 0;
    string tabu = "";
    string coma = "";
    string x1, y1, x2, y2;
    getline(entrada, x1,',');
    getline(entrada, y1,'\t');
    getline(entrada, x2,',');
    getline(entrada, y2,'\n');
    xx1 = atoi(x1.c_str())/2;
    yy1 = atoi(y1.c_str())/2;
    xx2 = atoi(x2.c_str())/2;
    yy2 = atoi(y2.c_str())/2;
    Coordenada* cord1 = new Coordenada(xx1, yy1);
    Coordenada* cord2 = new Coordenada(xx2, yy2);
    return new Jugada(cord1, cord2);
}

bool Jugada::operator==(Jugada& j)
{
    if (cord1->obtenerX() == j.cord1->obtenerX() && cord2->obtenerX() == j.cord2->obtenerX() && cord1->obternerY() == j.cord1->obternerY() && cord2->obternerY() == j.cord2->obternerY()) {

        return true;
    }
    return false;
}

ostream& operator<<(ostream& out, Jugada& p)
{
    out << p.toString() << endl;
    return out;
}
