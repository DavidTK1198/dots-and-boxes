#include "Vista.h"
#include <conio.h>

void Vista::gotoxy(int valor, int valor2) { //Coloca el texto en determinados lugares de la pantalla.
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = valor;
	dwPos.Y = valor2;
	SetConsoleCursorPosition(hcon, dwPos);
}





void Vista::despedida()
{
	system("cls");
	cout << " _______________________________________" << endl;
	cout << "|                                       |" << endl;
	cout << "|         Gracias  por usar             |" << endl;
	cout << "|            el sistema                 |" << endl;
	cout << "|      Digite enter para salir          |" << endl;
	cout << "|                                       |" << endl;
	cout << "|_______________________________________|" << endl;
	system("pause");

}

void Vista::menuEspecial(EmpresaDots* em)
{
	cout << em->toString() << endl;

}

void Vista::PresentacionInicial()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	string saludo[11] = { "B","I","E","N","V","E","N","I","D","O" };
	gotoxy(40, 8);
	for (int i = 0; i < 11; i++) {
		cout << saludo[i];
		Sleep(150);
	}
	string sl[20] = { "A ","L" ,"A ","E","M","P","R","E","S","A ","D" ,"O","T","S" };
	gotoxy(40, 9);
	for (int i = 0; i < 18; i++) {
		cout << sl[i];
		Sleep(150);
	}
	Sleep(1000);

}

int Vista::MenuPrincipal(EmpresaDots* em)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	int opcion = 0;
	system("cls");
	cout << " ________________________________________________________________________" << endl;
	cout << "|                                                                        |" << endl;
	cout << "|         BIENVENIDO AL MENU PRINCIPAL DE LA EMPRESA DOTS                |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "|	DISPONE DE LAS SIGUIENTES OPCIONES                               |" << endl;
	cout << "|**1-)Suscribirse                                                        |" << endl;
	cout << "|**2-)Jugar Dots and Boxes                                               |" << endl;
	cout << "|**3-)Recrear partidas                                                   |" << endl;
	cout << "|**4-)Cambiar Dia                                                        |" << endl;
	cout << "|**5-)Salir                                                              |" << endl;
								menuEspecial(em);
	cout << "|________________________________________________________________________|" << endl;
	cout << endl << endl;
	Excepciones a;
	return opcion = a.validarInfo(1, 5);
	

}

int Vista::verPartidas()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	int opcion;
	system("cls");
	cout << " _________________________________________________________" << endl;
	cout << "|                                                         |" << endl;
	cout << "|                                                         |" << endl;
	cout << "|                                                         |" << endl;
	cout << "|           1-) Reproducir Partida                        |" << endl;
	cout << "|           2-)Volver al menu anterior                    |" << endl;
	cout << "|                                                         |" << endl;
	cout << "|_________________________________________________________|" << endl;
	Excepciones k;
	opcion = k.validarInfo(1, 2);
	return opcion;
}


int Vista::menuJugar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	int opc = 0;
	Excepciones ex;
	system("cls");
	
	  cout << "                                                                      " << endl;
	  cout << "																		 " << endl;
	  cout << "                                1.- Jugador VS Jugador				 " << endl; 
	  cout << "                                2.- Jugador VS I.A				     " << endl;
	  cout << "                                3.- Volver al menu				     " << endl;
	  cout << "																		 " << endl;
	  cout << "																		 " << endl;
	  cout << "Opcion: ";
	  opc = ex.validarInfo(1, 3);
	  return opc;
}


void Vista::subMenuCrearJugador(EmpresaDots* em)
{
	int k = 0;
	Excepciones ex;
	bool p = false;
	double mon = 0.0;
	bool bandera = false;
	while (!p) {
		bandera = false;
		Jugador* jug = NULL;
		string ced, nom;
		system("cls");
		cout << " Procediendo a suscribir a nuevo jugador." << endl;
		do {
			try {
				cout << "Ingrese su numero de cedula..." << endl;
				cin >> ced;
				jug = em->buscarJugador(ced);
				if (jug != NULL) {
					throw jug;
				}
				bandera = true;
			}
			catch (Jugador * j) {
				cout << "Imposible suscribirse." << endl;
				cout << "La cedula " << j->getCedula() << " ya corresponde a un suscriptor ingresado con anterioridad." << endl;
				cout << "Vuelva a intentarlo." << endl;
				Sleep(2500);
				system("cls");
			}
		} while (bandera == false);
		cout << endl;
		cout << "Ingrese su nombre de usuario: ";
		cin.clear();
		cin.ignore(255, '\n');
		getline(cin, nom);
		cout << endl;
		cout << "Nota: Para poder jugar el juego de Dots and Boxes, debera pagar una cuota de suscripcion de 500 colones." << endl;
		cout << "Si no la paga , solo tendra acceso al catalogo de partidas jugadas de otros jugadores, que es un servicio gratuito." << endl;
		bool m = false;
		do {
			try {
				cout << "Cuanto le gustaria depositar a su monedero para este dia?" << endl;
				if (cin >> mon) {
					if (mon < 0) {
						throw - 1;
					}
					else {
						m = true;
					}
				}
				else {
					throw -1;
				}
			
				
			}
			catch (...) {
				cout << "Error, no es posible ingresar valores negativos ni letras." << endl;
				cout << "Intente de nuevo." << endl;
				Sleep(2500);
				system("cls");
				if (!m) {
					cin.clear();
					cin.ignore(255, '\n');

				}
			}

		} while (m == false);
		jug = new JugadorPersona(nom, ced, "", mon);
		em->attach(jug);
		cout << "La persona con la cedula " << jug->getCedula() << " ha sido suscrito a la empresa correctamente." << endl;
		system("pause");
		system("cls");
		cout << "Desea suscribir a otra persona?" << endl;
		cout << "1-)Si." << endl;
		cout << "2-)No." << endl;
		k = ex.validarInfo(1, 2);
		switch (k)
		{
		case 1:
			break;
		case 2:
			p = true;
		default:
			cout << "No haga nada." << endl;
			break;
		}
	}
	
}

Jugador* Vista::Acceso(EmpresaDots* em)
{
	system("cls");
	int opc = 0;
	string ced = "";
	Jugador* jugador = NULL;
	ArregloJugador* arr = em->getArreglo();
	bool p = false;
	if (arr->getCantidad() == 0) {
		cout << "Imposible acceder a esta funcion del sistema." << endl;
		cout << "No existen suscriptores en la empresa." << endl;
		cout << "Regresando a menu anterior..." << endl;
		system("pause");
		return NULL;
	}
	while (!p) {
		try {
			cout << "Ingrese su cedula de identidad...";
			cin >> ced;
			jugador = em->buscarJugador(ced);
			if (jugador == NULL) {
				throw ced;
			}
			else {
				p = true;
			}
			
		}
		catch (string c) {
			cout << "Acceso Denegado." << endl;
			cout << "Error :La cedula " << c << " no concuerda con ningun suscriptor registrado en el sistema." << endl;
			cout << "Intentelo de nuevo." << endl;
			Sleep(4000);
			system("cls");
		}
	}
	if (jugador->getCodigo() == "") {
		cout << "El asociado con la cedula " << jugador->getCedula() << " no pago la cuota de inscripcion para poder jugar." << endl;
		cout << "Solo se le permite recrear partidas de otros usuarios en la funcion de VerPartidas del menu Principal" << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return NULL;
	}
	cout << "Acceso Concedido... " << endl;
	system("pause");
	return jugador;


}

void Vista::jugadorVsJugador(Jugador* j, EmpresaDots* em)
{
	system("cls");
	bool p = false;
	bool m1 = false;
	bool ayudante = false;
	Excepciones ex;
	int cont = 1;
	Jugada* jugada = NULL;
	ArregloJugador* arr = em->getArreglo();
	string ced = "";
	Jugador* jugador = NULL;
	Partida* partidita = NULL;
	Componentes* lin = new LineaHorizontal();
	Coordenada* co1 = NULL;
	Coordenada* co2 = NULL;
	if (arr->getCantidad() == 1) {
		cout << "No es posible acceder a este contenido" << endl;
		cout << "Se necesitan de al menos dos jugadores suscritos." << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return;
	}
	cout << "Mostrando en pantalla los suscriptores que hay en la empresa. " << endl;
	cout << em->mostrarSuscriptores() << endl << endl;
	cout << "Solamente es posible jugar con suscriptores con codigo de suscripcion..." << endl;
	while (!p) {
		try {
			cout << "Ingrese la cedula de identidad del suscriptor con el que se desea jugar...";
			cin >> ced;
			jugador = em->buscarJugador(ced);
			if (jugador == NULL || jugador->getCedula() == j->getCedula()) {
				throw ced;
			}
			else {
				p = true;
			}

		}
		catch (string c) {
			cout << "Error :La cedula " << c << " no concuerda con ningun suscriptor registrado en el sistema o bien, no es posible jugar contra si mismo." << endl;
			cout << "Intentelo de nuevo." << endl;
		}
	}
	if (jugador->getCodigo() == "") {
		cout << "El suscriptor con la cedula " << jugador->getCedula() << " no pago la cuota de inscripcion para poder jugar." << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return;
	}
	
	int tablero = opcionesTablero();
	switch (tablero)
	{
	case 1:
		partidita = campoSeisPuntos(j, jugador);
		break;
	case 2:
		partidita = campoNuevePuntos(j, jugador);
		break;
	case 3:
		partidita = campoQuincePuntos(j, jugador);
		break;
	case 4: 
		partidita = campoCompuesto(j, jugador);
		break;
	default:
		break;
	}
	system("cls");
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "|                            JUGADOR VS JUGADOR                             |" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	while (!partidita->estaLleno()) {
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Jugador 1 " << j->getNombre() << " :" << lin->toString() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Jugador 2 " << jugador->getNombre() << " :" << lin->toString() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if (m1 == false) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Turno de jugador # " << cont << ": " << j->getNombre() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			m1 = true;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Turno de jugador # " << cont << ": " << jugador->getNombre() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			m1 = false;
		}

		cout << endl << endl;
		partidita->pintaMatriz(cont);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		do {
			if (ayudante == true) {
				system("cls");
				partidita->pintaMatriz(cont);
				cout << "El jugador " << cont << " ha capturado!!! , tiene un turno adicional." << endl;
				cout << "Turno de jugador " << cont << endl;
			}
			do {

				cout << "               x y" << endl;
				cout << "Coordenada 1: ";
				cout << "(";
				co1 = nueva();
				cout << endl;
				cout << "Coordenada 2: ";
				cout << "(";
				co2 = nueva();
				cout << endl;

			} while ((ex.validarExcAgregar(co1, co2, partidita->getCampo(), cont)) == false);
			jugada = new Jugada(co1, co2);
			partidita->agregarJugada(jugada);
			ayudante = partidita->determinarNumeroXCuadroGana(cont);
		} while (ayudante == true);
		cont++;
		if (cont > 2) {
			cont = 1;
		}

		system("pause");
		system("cls");

	}
	
	partidita->pintaMatriz(1);
	int co = partidita->determinaGanador();
	if (co == 1) {
		cout << "El ganador es..." << j->getNombre() << endl;
		system("pause");
	}
	if (co == 2) {
		cout << "El ganador es..." << jugador->getNombre() << endl;
		system("pause");
	}
	if (co == 0) {
		cout << "EMPATE!!!!!!!" << endl;
		system("pause");
	}
	cout << "La partida ha concluido! " << endl;

	Sleep(3000);
	cout << "Regresando al menu anterior...." << endl;
	em->agregaPartida(partidita);
	delete lin;
	return;
	
}

void Vista::jugadorVsMaquina(Jugador* j, EmpresaDots* em)
{
	system("cls");
	bool p = false;
	bool m1 = false;
	Excepciones ex;
	int cont = 1;
	Jugada* jugada = NULL;
	ArregloJugador* arr = em->getArreglo();
	string ced = "";
	Jugador* jugador = NULL;
	Partida* partidita = NULL;
	string jue = "";
	Componentes* lin = new LineaHorizontal();
	if (arr->getCantidad() == 0) {
		cout << "No es posible acceder a este contenido" << endl;
		cout << "Se necesitan de al menos un jugador suscrito." << endl;
		cout << "Regresando a menu anterior." << endl;
		system("pause");
		return;
	}
	system("cls");
	cout << "-------------------CONFIGURACION DE SU PARTIDA--------------" << endl;
	jugador = new JugadorMaquina();
	int tablero = opcionesTablero();
	switch (tablero)
	{
	case 1:
		partidita = campoSeisPuntos(j, jugador);
		break;
	case 2:
		partidita = campoNuevePuntos(j, jugador);
		break;
	case 3:
		partidita = campoQuincePuntos(j, jugador);
		break;
	case 4:
		partidita = campoCompuesto(j, jugador);
		break;
	default:
		break;
	}
	
	system("cls");
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "|                            PARTIDA VS CPU                             |" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	bool m = false;
	Estrategia* est = cambiaEstrategia(partidita->getCampo()->getCampoAbs());
	jugador->setEstrategia(est);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	while (!partidita->estaLleno()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Jugador 1 "<<j->getNombre()<<" :" << lin->toString() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Jugador 2 " <<jugador->getNombre()<<" :"<< lin->toString() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << endl;
		cout << "La estrategia actual es: " << est->getNombreEst() << endl;
		cout << endl;
		bool nada = false;
		if (m == false) {
			cout << "Turno de jugador # " << cont << ": " << j->getNombre() << endl;

			m = true;
		}
		else {
			cout << "Turno de jugador # " << cont << ": " << jugador->getNombre() << endl;

			m = false;
		}

		cout << endl << endl;
		cout << endl;
		partidita->pintaMatriz(cont);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		Coordenada* co1 = NULL;
		Coordenada* co2 = NULL;
		if (cont != 2) {
			do {
				do {
					if (!partidita->estaLleno()) {
						if (nada == true) {
							system("cls");
							cout << "Turno de jugador # " << cont << ": " << j->getNombre() << endl;
							cout << endl << endl;
							cout << endl;
							partidita->pintaMatriz(cont);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "El jugador 1 ha capturado!!!, dispone de otro turno." << endl;
							Sleep(3000);
						}
						do {
							cout << "Cuando desee cambiar de estrategia, ingrese --->'Q' o 'q'" << endl;
							cout << "               x y" << endl;
							cout << "Coordenada 1: ";
							cout << "(";
							co1 = nueva();
							if (co1 == NULL) {
								cout << endl;
								est = cambiaEstrategia(partidita->getCampo()->getCampoAbs());
								jugador->setEstrategia(est);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								cout << "Estrategia cambiada correctamente." << endl;
								system("pause");
								system("cls");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								m = false;
								if (m == false) {
									cout << "Turno de jugador # " << cont << ": " << j->getNombre() << endl;

									m = true;
								}
								else {
									cout << "Turno de jugador # " << cont << ": " << jugador->getNombre() << endl;

									m = false;
								}
								cout << endl << endl;
								cout << endl;
								partidita->pintaMatriz(cont);
								
							}
						} while (co1 == NULL);
						do{
							
							cout << endl;
							cout << "Coordenada 2: ";
							cout << "(";
							co2 = nueva();
							cout << endl;
							if (co2 == NULL) {
								cout << endl;
								est = cambiaEstrategia(partidita->getCampo()->getCampoAbs());
								jugador->setEstrategia(est);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								cout << "Estrategia cambiada correctamente." << endl;
								system("pause");
								system("cls");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								m = false;
								if (m == false) {
									cout << "Turno de jugador # " << cont << ": " << j->getNombre() << endl;

									m = true;
								}
								else {
									cout << "Turno de jugador # " << cont << ": " << jugador->getNombre() << endl;

									m = false;
								}
								cout << endl << endl;
								cout << endl;
								partidita->pintaMatriz(cont);
							}

						}while(co2 == NULL);
					}
					else {
						break;
					}

				} while ((ex.validarExcAgregar(co1, co2,partidita->getCampo(), cont)) == false);
				jugada = new Jugada(co1, co2);

				JuegoCercano* jue = dynamic_cast<JuegoCercano*>(est);
				if (jue) {
					est->setJugada(jugada);
				}
				if (!partidita->estaLleno()) {
					partidita->agregarJugada(jugada);
					cout << "Jugada a realizar por la CPU: " << jugada->toString() << endl;
					system("pause");
				}
			
			
			nada = partidita->determinarNumeroXCuadroGana(cont);
			} while (nada == true);
		}

		if (cont == 2) {
			do {

				if (!partidita->estaLleno()) {
					if (nada == true) {
						system("cls");
						cout << "Turno de jugador # " << cont << ": " << jugador->getNombre() << endl;
						cout << endl << endl;
						cout << endl;
						partidita->pintaMatriz(cont);
						cout << "El jugador 2 ha capturado!!!, dispone de otro turno." << endl;
						Sleep(3000);

					}
					else {
						Sleep(3000);
					}

					jugador->ejecutarEstrategia();
					jugada = jugador->ultima();
					partidita->agregarJugada(jugada);
					cout << "Ultima jugada realizada: " << jugada->toString() << endl;
					system("pause");
					nada = partidita->determinarNumeroXCuadroGana(cont);
				}
				else {
					break;
				}
			} while (nada == true);
		}
	

		cont++;
		if (cont > 2) {
			cont = 1;
		}

		system("cls");

	}
	partidita->pintaMatriz(cont);
	cout << "Partida finalizada correctamente..." << endl;
	cout << "La partida ha sido guardada en nuestros registros." << endl;
	int co = partidita->determinaGanador();
	if (co == 1) {
		cout << "El ganador es..." << j->getNombre() << endl;
		system("pause");
	}
	if (co == 2) {
		cout << "El ganador es..." << jugador->getNombre() << endl;
		system("pause");
	}
	if (co == 0) {
		cout << "EMPATE!!!!!!!" << endl;
		system("pause");
	}
	em->agregaPartida(partidita);
	cout << "La partida ha concluido! " << endl;
	system("pause");
	system("cls");
	delete lin;

}

int Vista::menuEstrategias()
{
	int num = 0;
	Excepciones ex;
	cout << "----------------------------------------------------------" << endl;
	cout << "|                  ESTRATEGIAS DISPONIBLES                |" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|1-)Estrategia Aleatoria (No juega a ganar)               | " << endl;
	cout << "|2-)Estrategia Periferica                                 | " << endl;
	cout << "|3-)Estrategia Central                                    | " << endl;
	cout << "|4-)Estrategia Cercana                                    | " << endl;
	cout << "|5-)Estrategia de Islas                                   | " << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl << endl;
	cout << "Ingrese el numero de la estrategia que desea : ";
	num = ex.validarInfo(1, 5);

	return num;
}

int Vista::opcionesTablero()
{
	system("cls");
	int opc = 0;
	CampoAbs* campito1 = new SeisPuntos();
	CampoAbs* campito2 = new NuevePuntos();
	CampoAbs* campito3 = new QuincePuntos();
	Excepciones ex;
	cout << "---------------------------------------------------" << endl;
	cout << "|       Se le presentan los posibles tableros      |" << endl;
	cout << "|__________________________________________________|" << endl;
	cout << "|       1-)Seis Puntos                             |" << endl;
	cout << campito1->toString() << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "|__________________________________________________|" << endl;
	cout << "|       2-)Nueve Puntos                            |" << endl;
	cout <<campito2->toString() << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "|__________________________________________________|" << endl;
	cout << "|       3-)Quince Puntos                           |" << endl;
	cout << campito3->toString() << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << "|__________________________________________________|" << endl;
	cout << "|       4-)Combinado                               |" << endl;
	cout << "---------------------------------------------------" << endl;
	delete campito1, campito2, campito3;
	opc = ex.validarInfo(1, 4);
	system("cls");
	return opc;
}

Partida* Vista::campoCompuesto(Jugador* j1, Jugador* j2)
{
	system("cls");
	Partida* partidita = new Partida(4, j1, j2);
	int opc = 0;
	int opc2 = 0;
	int valor = 0;
	string m = "";
	int contador1 = 0;
	int con = 3;
	bool p = false;
	CampoAbs* campito = NULL;
	Excepciones ex;
	CamposCombinados();
	cout << endl;
	cout << "Tablero 1:";
	opc = ex.validarInfo(1, 3);
	cout << "Tablero 2:";
	opc2 = ex.validarInfo(1, 3);
	switch (opc)
	{
	case 1:
		campito = new SeisPuntos();
		partidita->agregarMatrizACont(campito);
		break;
	case 2:
		campito = new NuevePuntos();
		partidita->agregarMatrizACont(campito);
		break;
	case 3:
		campito = new QuincePuntos();
		partidita->agregarMatrizACont(campito);
		break;
	default:
		break;
	}

	switch (opc2)
		{
	case 1:
		campito = new SeisPuntos();
		partidita->agregarMatrizACont(campito);
		break;
	case 2:
		campito = new NuevePuntos();
		partidita->agregarMatrizACont(campito);
		break;
	case 3:
		campito = new QuincePuntos();
		partidita->agregarMatrizACont(campito);
		break;
		default:
		break;
	}

	if ((((opc == 1 || opc == 2) && (opc2 == 1 || opc2 == 2))) || (opc == 3 && opc2 == 3)) {
		partidita->nuevoCampoXfilasIguales();
	}
	else {
		partidita->nuevaCampoXfilasDispares();
	}
	cout << "El campo ha sido combinado satisfactoriamente..." << endl;
	Sleep(3500);
	system("cls");
	while (!p) {
		CamposCombinados();
		cout << endl;
		cout << "Desea combinar otro campo de juego?" << endl;
		cout << "1-)Si." << endl;
		cout << "2-)No." << endl;
		cout << "Opcion:";
		valor = ex.validarInfo(1, 2);
		switch (valor)
		{
		case 1:
			cout << "Seleccione el tablero que desea agregar a la combinacion: " << endl;
			cout << "Tablero " << con << ": ";
			opc2 = ex.validarInfo(1, 3);
			switch (opc2)
			{
			case 1:
				campito = new SeisPuntos();
				partidita->agregarMatrizACont(campito);
				break;
			case 2:
				campito = new NuevePuntos();
				partidita->agregarMatrizACont(campito);
				break;
			case 3:
				campito = new QuincePuntos();
				partidita->agregarMatrizACont(campito);
				break;
			default:
				break;
			}
			//nuevepuntos con seis puntos 


			for (int i = 0; i < partidita->getCampo()->getkCampoJuego(); i++) {
				m = partidita->getCampo()->guardaCampo(i + 1);
				if (m == "class QuincePuntos") {
					contador1++;
				}
			}
			if ((opc2 == 1 || opc2 == 2) && contador1 != 0) {
				partidita->nuevaCampoXfilasDispares();
				cout << "El campo ha sido combinado satisfactoriamente..." << endl;
				Sleep(3500);
				system("cls");
			}
			if (opc2 == 3 && contador1 != 0) {
				partidita->nuevoCampoXfilasIguales();
				cout << "El campo ha sido combinado satisfactoriamente..." << endl;
				Sleep(3500);
				system("cls");
			}
			if (opc2 == 3 && contador1 == 0) {
				partidita->nuevaCampoXfilasDispares();
				cout << "El campo ha sido combinado satisfactoriamente..." << endl;
				Sleep(3500);
				system("cls");
			}
			con++;
			break;
		case 2:
			p = true;
			break;
		default:
			break;
		}
	}
	return partidita;
}

Partida* Vista::campoSeisPuntos(Jugador* j1, Jugador* j2)
{
	Partida* partidita = new Partida(1, j1, j2);
	return partidita;
}

Partida* Vista::campoNuevePuntos(Jugador* j1, Jugador* j2)
{
	Partida* partidita = new Partida(2, j1, j2);
	return partidita;
}


Partida* Vista::campoQuincePuntos(Jugador* j1, Jugador* j2)
{
	Partida* partidita = new Partida(3, j1, j2);
	return partidita;
}

Coordenada* Vista::nueva()
{
	Coordenada* nueva = NULL;
	string cord;
	char caracter;
	caracter = _getch();
	cord = "";
	int aux2 = 0;
	int n = 0;
	char aux = (char)8;
	string aux3;
	bool valor = false;
	if (caracter == 'q' || caracter == 'Q') {
		return NULL;
	}
	if (caracter == 13) {
		caracter = 'x';
	}
	while (caracter != 13 && valor == false) {
		aux3 = "";
		aux3.push_back(caracter);
		if (aux2 = atoi(aux3.c_str()) || aux3 == "0") {
			cord.push_back(caracter);
			if (cord.size() == 1) {
				cord.push_back(',');
				cout << cord;
			}
		}
		else {
			if (aux3.length() > 0) {
				if (caracter == 8 && cord.length() > 0) {
					cord = cord.substr(0, cord.length() - 1);
					cout << aux;
				}
				if (cord.length() > 2) {
					cout << aux3;
					cout << aux;

				}
				cout << aux3;
				cout << aux;
			}
		}

		if (cord.length() == 3) {
			cout << cord[cord.length() - 1] << ")";
			caracter = (char)13;
			valor = true;
		}
		caracter = _getch();
		if (valor == false && caracter == 13) {
			caracter = 'a';
		}

	}

	aux3 = cord[0];
	cord = cord[cord.length() - 1];
	aux2 = atoi(aux3.c_str());
	n = atoi(cord.c_str());

	return nueva = new Coordenada(aux2, n);
}

void Vista::recrearPartidas(EmpresaDots* em)
{
	system("cls");
	int entero = 1;
	int num = 0;
	char caracter = ' ';
	CampoAbs* campito = NULL;
	ControlComposite* control = NULL;
	Excepciones ex;
	Partida* partida = NULL;
	Componentes* lin = new LineaHorizontal();
	Lista<Partida>* lista = em->getContenedorPar();
	if (lista->genCantidad() == 0) {
		cout << "No existen partidas guardadas en nuestro sistema." << endl;
		cout << "Regresando al menu anterior...." << endl;
		system("pause");
		return;
	}
	cout << "Bienvenido a la funcion de recreacion de partidas guardadas en nuestros servidores." << endl;
	cout << "Mostrando las partidas disponibles..." << endl << endl;
	cout << lista->verLista() << endl;
	cout << "Ingrese el numero de partida que desea visualizar." << endl;
	cout << "Numero: ";
	num = ex.validarInfo(1, lista->genCantidad());
	cout << endl;
	partida = lista->retornaElemento(num);
	system("cls");
	cout << "Partida encontrada..." << endl;
	control = partida->getCampo();
	campito = control->getCampoAbs();
	Componentes*** matriz = campito->getMatriz();
	for (int i = 0; i < campito->getFilas(); i++) {
		for (int j = 0; j < campito->getColumnas(); j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				
			}
			else {
				delete matriz[i][j];
				matriz[i][j] = NULL;
			}
		}
	}
	Lista<Jugada>* jugadas = NULL;
	Jugada* aux = NULL;
	int conta = 0;
	bool ayuda = false;
	lista->inicializarActual();
	jugadas = partida->getListaJugada();
	Coordenada* coor1 = NULL;
	Coordenada* coor2 = NULL;
	jugadas->inicializarActual();

	while (true) {
		while (conta < jugadas->genCantidad()) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Jugador 1: " << lin->toString() << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Jugador 2: " << lin->toString() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Pulse la tecla de ENTER para continuar jugada." << endl;
			conta++;
			aux = jugadas->getTipo();
			coor1 = aux->getCordenada1();
			coor2 = aux->getCoordenada2();
			partida->agregarComponente(coor1, coor2, entero);
			ayuda = partida->determinarNumeroXCuadroGana(entero);
			if (ayuda == false) {
				entero++;
				if (entero > 2) {
					entero = 1;
				}
			}
			partida->pintaMatriz(1);
			caracter = _getch();
			
			Sleep(2000);

			system("cls");
			jugadas->siguienteNodo();
		}
		break;
	}
	int ganador = partida->determinaGanador();
	if (ganador == 1) {
		cout << "El ganador es jugador 1" << endl;
	}
	if (ganador == 2) {
		cout << "El ganador es jugador 2" << endl;
	}
	if (ganador == 0) {
		cout << "ES UN EMPATE..." << endl;
	}
	system("pause");
	delete lin;
	
}

Estrategia* Vista::cambiaEstrategia( CampoAbs* c)
{
	system("cls");
	int num = menuEstrategias();
	Estrategia* est = NULL;
	switch (num)
	{
	case 1:
		est = new JuegoAleatorio(c);
		return est;
	case 2:
		est = new JuegoPeriferico(c);
		return est;
	case 3:
		est = new JuegoCentral(c);
		return est;
	case 4:
		est = new JuegoCercano(c);
		return est;
	case 5:
		est = new JuegoIslas(c);
		return est;
	default:
		return NULL;
	}

}

void Vista::CamposCombinados()
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "|       Se le presentan los posibles tableros a combinar      |" << endl;
	cout << "|       1-)Seis Puntos                                        |" << endl;
	cout << "|       2-)Nueve Puntos                                       |" << endl;
	cout << "|       3-)Quince Puntos                                      |" << endl;
	cout << "-------------------------------------------------------------" << endl;
}













