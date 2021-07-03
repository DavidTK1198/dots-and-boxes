#pragma once
#include "Componentes.h"
#include "Circulo.h"
#include "Numero.h"
#include "LineaVertical.h"
#include <stdio.h>

class CampoAbs :
	public Componentes
{
	protected:
		Componentes*** matriz;
		int filas;
		int columnas;
	public:
		CampoAbs(int = 0 ,int = 0);
		virtual ~CampoAbs();
		virtual bool agregar(Coordenada*, Coordenada*,int) = 0;
		string toString()const;
		virtual int getFilas();
		virtual int getColumnas();
		virtual Componentes*** getMatriz();
		virtual void pintarMatriz(int);
		virtual bool estaLleno() = 0;
		virtual bool vacio() = 0;
		virtual void setCampo(Componentes***);
		virtual void agregarCampos(CampoAbs*) = 0;
		virtual bool unirCamposJuego(CampoAbs*) = 0;
		virtual bool asignarNumeroXCuadro(int) = 0;
		virtual CampoAbs* seisPuntosXnuevePuntos() = 0;
		virtual CampoAbs* GrandeConCualquierPequenia() = 0;
		virtual void setJugador(int) { throw; }
		virtual int getJugador() { throw; }
		virtual int obtenerK() = 0;
		virtual string recuperarClase(int i) = 0;
		virtual int getCantidad() = 0;
		virtual CampoAbs** getVector() = 0;
		virtual int determinaGanador();


	
};
class adaptadorCampo :public CampoAbs {
public:
	virtual string toString()const;
};


ostream& operator << (ostream&, const CampoAbs&);
