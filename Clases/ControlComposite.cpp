#include "ControlComposite.h"

ControlComposite::ControlComposite(int opc)//4--->Campos Combinados
{
	switch (opc)
	{
		case 1:
			campo = new SeisPuntos();
			break;
		case 2:
			campo = new NuevePuntos();
			break;
		case 3:
			campo = new QuincePuntos();
			break;
		case 4:
			campo = new CampoJuego();
			break;
		
	default:
		campo = NULL;
		break;
	}
}

ControlComposite::~ControlComposite()
{
	delete campo;
}

bool ControlComposite::agregarComponente(Coordenada* x,Coordenada* y,int p)
{
	return campo->agregar(x,y,p );
}

void ControlComposite::agregarMatrizACont(CampoAbs* cam)//SeisPuntos--->NuevePuntos
{
	return campo->agregarCampos(cam);
}

bool ControlComposite::estaLleno()
{
	return campo->estaLleno();
}

bool ControlComposite::estaVacio()
{
	return campo->vacio();
}

void ControlComposite::imprimirConColor(int p)
{
	campo->pintarMatriz(p);
}

bool ControlComposite::determinarNumeroXCuadroGana(int num)
{
	return campo->asignarNumeroXCuadro(num);
}

string ControlComposite::toString() const
{
	return campo->toString();
}

void ControlComposite::nuevaZonaJuegoSeisXNueve()
{
	CampoAbs* nuevo = campo->seisPuntosXnuevePuntos();//
	campo->agregarCampos(nuevo);
}

void ControlComposite::nuevaZonaJuegoSeisXQuince()
{
	CampoAbs* nuevo = campo->GrandeConCualquierPequenia();
	campo->agregarCampos(nuevo);
}

void ControlComposite::setNuevaZona(CampoAbs* p)
{
	campo = p;
}

CampoAbs* ControlComposite::getCampoAbs()
{
	return campo;
}

int ControlComposite::getkCampoJuego()
{
	return campo->obtenerK();
}

string ControlComposite::guardaCampo(int x)
{
	return campo->recuperarClase(x);
}

int ControlComposite::getCantVecMat()
{
	return campo->getCantidad();
}

CampoAbs** ControlComposite::getVector()
{
	return campo->getVector();
}

int ControlComposite::determinaGanador()
{
	return campo->determinaGanador();
}
