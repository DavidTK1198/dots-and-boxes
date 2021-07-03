#pragma once
#include <iostream>
#include "ExcepcionRango.h"
#include "ExcepcionRangoInferior.h"
#include "ExcepcionRangoSuperior.h"
#include "ExcepcionContiguos.h"
#include "ExcepcionDiagonal.h"
#include "ExcepcionMayCoInex.h"
#include "Coordenada.h"
#include "ControlComposite.h"
class ControlComposite;
using namespace std;
class Excepciones
{
public:
	int excepcionValor(int, int);
	int validarInfo(int, int);
	int ExcepcionSoloNumeros();
	int validarSoloNum();
	bool validarExcAgregar(Coordenada*,Coordenada*,ControlComposite*,int p);
};


