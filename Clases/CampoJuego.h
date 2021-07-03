#pragma once
#include "CampoAbs.h"
#include "CampodeApoyo.h"
class CampoJuego :
	public CampoAbs
{
	private:
		CampoAbs** campos;
		int cant;
		int tam;
		string archivos[20];
		int cantAr;

	public:
		CampoJuego();
		virtual ~CampoJuego();
		virtual bool agregar(Coordenada*, Coordenada*,int);
		virtual void agregarCampos(CampoAbs*);
		string toString()const;
		void pintarMatriz(int);
		virtual bool estaLleno();
		virtual bool vacio();
		virtual bool unirCamposJuego(CampoAbs*);
		virtual bool asignarNumeroXCuadro(int);
		virtual CampoAbs* seisPuntosXnuevePuntos();
		virtual CampoAbs* GrandeConCualquierPequenia();
		virtual void agregarArchivos(string);
		virtual int obtenerK();
		virtual string recuperarClase(int i);
		virtual int getCantidad();
		virtual CampoAbs** getVector();
		virtual int determinaGanador();
		virtual int getFilas();
		virtual int getColumnas();
		virtual Componentes*** getMatriz();

		//combinarSeisXNueve

};

