#pragma once
#include "CampoAbs.h"
#include "LineaVertical.h"
#include "LineaHorizontal.h"
#include "Numero.h"
#include "Excepciones.h"
#include "ExcepcionDiagonal.h"
#include "ExcepcionMayCoInex.h"
#include "ExcepcionContiguos.h"
#include "ExcepcionCoordIguales.h"
#include "ExcepcionLexistente.h"
class SeisPuntos :
	public CampoAbs
{
	private:
		string nombreMatriz;
	public:
		SeisPuntos();
		virtual ~SeisPuntos();
		virtual bool agregar(Coordenada*, Coordenada*,int);
		string toString()const;
		virtual bool estaLleno();
		virtual bool vacio();
		virtual bool unirCamposJuego(CampoAbs*);
		virtual bool asignarNumeroXCuadro(int);
		virtual void agregarCampos(CampoAbs*) { throw; }
		virtual CampoAbs* seisPuntosXnuevePuntos() { throw; }
		virtual CampoAbs* GrandeConCualquierPequenia() { throw; }
		void pintarMatriz(int);
		virtual int obtenerK() { throw; }
		virtual string recuperarClase(int i) { throw; }
		virtual int getCantidad() { throw; }
		virtual CampoAbs** getVector() { throw; }
};

