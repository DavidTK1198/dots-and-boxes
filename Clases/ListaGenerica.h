#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
template <class T>
class nodo {
private:
	nodo* sig;
	T* objetoPtr;
public:
	nodo(T*, nodo*);
	virtual ~nodo();
	T* getObjetoPtr();
	nodo* getSiguiente();
	void setObjetoPtr(T*);
	void setSiguiente(nodo*);
};

template<class T>
nodo<T>::nodo(T* ptr, nodo* nod) :
	objetoPtr(ptr), sig(nod)
{}

template<class T>
nodo<T>::~nodo() {
	delete objetoPtr;
}

template<class T>
T* nodo<T>::getObjetoPtr() {
	return objetoPtr;
}

template<class T>
nodo<T>* nodo<T>::getSiguiente() {
	return sig;
}

template<class T>
void nodo<T>::setObjetoPtr(T* ptr) {
	objetoPtr = ptr;
}

template<class T>
void nodo<T>::setSiguiente(nodo* nod) {
	sig = nod;
}

//-----------------------LISTA-----------------
template <class T>
class Lista {
private:
	nodo<T>* primero;
	nodo<T>* actual;
	nodo<T>* ultimo;
	int n;

public:
	Lista();
	virtual ~Lista();
	nodo<T>* getPrimero();
	void limpiaLista();
	int genCantidad();
	bool listaVacia();
	T* getTipo();
	void inicializarActual();
	void siguienteNodo();
	T* retornaElemento(int);
	bool insertaObjeto(T*);
	string verLista();
	void grabaLista(string);
	void leeLista(string);
	bool agregarFinal(T*);
	T* eliminarFinal();
	bool masElementos();
	void iniciaPrimero();
	void eliminar(string*);
	bool buscaElemento(string);
	T* eliminarInicio();
	T* devuelteUltimaPos(int);
};

template <class T>
Lista<T>::Lista() {
	primero = NULL;
	actual = NULL;
	ultimo = NULL;
	n = 0;
}

template <class T>
Lista<T>::~Lista() {
	this->limpiaLista();
}

template<class T>
void Lista<T>::limpiaLista() {
	nodo<T>* actuall = NULL;
	while (primero != NULL)
	{
		actuall = primero;
		n--;
		primero = actuall->getSiguiente();  // Hab�a un error...
		delete actuall;
	}
}

template<class T>
int Lista<T>::genCantidad()
{
	return n;
}


template<class T>
bool Lista<T>::masElementos() {
	if (actual->getSiguiente() != nullptr) {
		actual = actual->getSiguiente();
		return true;
	}
	return false;
}
template<class T>
 void Lista<T>::iniciaPrimero()
{
	 primero = NULL;
	 actual = primero;
}

 template<class T>
  void Lista<T>::eliminar(string *p)
 {
	  int cuentaNodos = 1;
	  nodo<T>* actual = primero;
	  nodo<T>* anterior = NULL;
	  T* _piloto = NULL;
	  if (primero != NULL) {
		  _piloto = actual->getObjetoPtr();
		  if (*p == *_piloto && cuentaNodos ==1) {
			  eliminarInicio();
			  n--;
			  return;
		  }
		  else {
			  cuentaNodos++;
			  while (actual!= NULL) {
				  anterior = actual;
				  actual = actual->getSiguiente();
				 _piloto = actual->getObjetoPtr();
				  if (cuentaNodos == n && *p == *_piloto) {
					  anterior->setSiguiente(NULL);
					  actual = NULL;
					  ultimo = anterior;
					  n--;
					  return;
				  }
				  if (*p == *_piloto) {
					  anterior->setSiguiente(actual->getSiguiente());
					  actual = NULL;
					  n--;
					  return;
				  }
				  
				  cuentaNodos++;
			  }
			
		  }
	  }
 }

 template<class T>
 bool Lista<T>::buscaElemento(string g)//1,3V
 {
	 nodo<T>* actual = primero;
	 T* aux = NULL;
	 while (actual != NULL) {
		 aux = actual->getObjetoPtr();
		 if (aux != NULL) {
			 if (*aux == g) {
				 return true;
			 }
		 }
		 actual = actual->getSiguiente();
	 }
	 return false;
 }

template<class T>
bool Lista<T>::listaVacia()
{
	return primero == NULL;
}

template<class T>
T* Lista<T>::getTipo()
{
	T* p = actual->getObjetoPtr();
	//actual = actual->getSig();
	return p;
}

template<class T>
void Lista<T>::inicializarActual()
{
	actual = primero;
}

template<class T>
void Lista<T>::siguienteNodo()
{
	
	if (actual->getSiguiente() != NULL) {
		actual = actual->getSiguiente();
	}

}

template <class T>
T* Lista<T>::retornaElemento(int pos)
{
	int cont = 1;
	nodo<T>* p = primero;
	while (p != NULL && cont < pos)
	{
		p = p->getSiguiente();
		cont++;
	}
	if (cont == pos) {
		return p->getObjetoPtr();
	}
	return NULL;

}
template<class T>
nodo<T>* Lista<T>::getPrimero()
{
	return primero;
}


template <class T>
bool Lista<T>::insertaObjeto(T* objeto)
{
	primero = new nodo<T>(objeto, primero);
	n++;
	return true;
}


template <class T>
string Lista<T>::verLista()
{
	nodo<T>* p = primero;
	int cont = 1;
	stringstream s;
	if (p == NULL) {
		s << "\t\tNO HAY ELEMENTOS EN LA LISTA\t\t" << endl;
	}
	else {
		while (p != NULL) {
			s << " #. " << cont << " -----> " << endl;
			s<< *(p->getObjetoPtr()) << endl;

			p = p->getSiguiente();
			cont++;
		}
	}
	return s.str();
}
template<class T>
void Lista<T>::grabaLista(string valor) {
	nodo<T>* aux = primero;
	ofstream out;
	out.open(valor, ios::out);

	while (aux != NULL) {
		T* obj1 = aux->getObjetoPtr();
		(*obj1)(out);
		aux = aux->getSiguiente();
	}
	out.close();
}

template<class T>
void Lista<T>::leeLista(string valor) {
	ifstream in;
	in.open(valor, ios::in);
	T* obj = NULL;
	T* aux = (*obj)(in);
	while (!in.eof()) {
		insertaObjeto(aux);
		aux = (*obj)(in);
	}
	in.close();
}

template<class T>
bool Lista<T>::agregarFinal(T* p)
{
	nodo<T>* ultimo = NULL;
	if (n == 0) {
		insertaObjeto(p);
		return true;
	}
	actual = primero;
	while (actual != NULL ) {
		ultimo = actual;
		actual = actual->getSiguiente();
	}
	nodo<T>* nuevo = new nodo<T>(p, NULL);
	ultimo->setSiguiente(nuevo);
	this->ultimo = ultimo;
	n++;
	return true;
}

	template<class T>
T* Lista<T>::eliminarInicio() {
	T* p = primero->getObjetoPtr();
	nodo<T> * auxiliar = primero;
	primero = primero->getSiguiente();
	 auxiliar=NULL;
	 return NULL;
}

template<class T>
T* Lista<T>::devuelteUltimaPos(int pos)
{
	nodo<T>* actual = primero;
	int cuentaNodos = 0;
	T* aux = NULL;
	while (actual != NULL) {
		cuentaNodos++;
		if (pos == cuentaNodos) {
			aux = actual->getObjetoPtr();
			return aux;
		}
	}
	return aux;
}

template<class T>
T* Lista<T>::eliminarFinal() {
	nodo<T>* actual = primero;
	nodo<T>* anterior=NULL;
	T* p = NULL;
	while (actual->getSiguiente() != NULL) {
		anterior = actual;
		actual = actual->getSiguiente();
	}
	anterior->setSiguiente(actual->getSiguiente());
	ultimo = anterior;
	p = actual->getObjetoPtr();
	 actual=NULL;
	return actual;
}

