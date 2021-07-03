#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Coordenada
{
private:
	int x;
	int y;
public:
	virtual ~Coordenada();
	Coordenada(int = 0, int = 0);
	int obtenerX();
	int obternerY();
	void setX(int);
	void setY(int);
	string toString();
	friend istream& operator >> (istream&, Coordenada&);
};

