//============================================================================
// Name        : AgendaDentista.cpp
// Author      : OranGITops
// Version     :
// Copyright   : OranGITops
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "Fichero.h"
#include "MenuTerminal.h"
#include "Paciente.h"
#include "Agenda.h"


using namespace std;
using namespace dentista;

int main() {
	// Fichero hereda de interfaz y por eso se admite como parámetro en el constructor
	// de Agenda
	string auxS;
	list<Paciente> auxL;
	list<Paciente>::iterator i;
	bool salir=false;
	// Ahora declaramos un puntero a Fichero, apuntando a Fichero("almacen.txt") que necesitamos para la declaración
	// del puntero a Agenda apuntando a Agenda(f), ya que Agenda necesita como parámetro un dato tipo *Fichero, que servirá
	// para la implementación de la base de datos de la agenda siguiendo los principios SOLID.
	// Una vez que tenemos nuestro puntero a Agenda, podemos declarar nuestro dato tipo MenuTerminal, el cual recibe como
	// parámetro el puntero a Agenda(f), por lo que al terminar de declarar m(a), ya hemos declarado un dato MenuTerminal
	// que tiene asociada la agenda recibida, la cual tenia asignado un fichero, llamado 'almacen.txt'. Así mismo, al incluir
	// en el constructor de MenuTerminal las siguientes líneas:
	// 		a_->cargar();
	//		a_->ordenar();
	// cuando declaramos m(a) conseguiremos que automáticamente se cargue en la agenda de nuestro programa todos los datos
	// que había en 'almacen.txt' en la lista interna de pacientes y que se ordenen alfabéticamente.
	Fichero* f = new Fichero("almacen.txt");
	Agenda* a = new Agenda(f);
	MenuTerminal m(a); //El programa carga por defecto la base de datos de contactos y la guarda al finalizar el programa.
	do{
		switch(m.menuPrincipal()) {
			case 1:
				m.cabecera();
				if(!m.getAgenda()->getPacientes().empty()){
					m.visualizarAgenda();
				}
				else{
					cout << "Agenda vacía, volviendo al menú principal." << endl;
					sleep(2);
				}
				break;
			case 2:
				m.cabecera();
				cout << "Introduce el apellido del contacto: ";
				getchar();
				getline(cin,auxS,'\n');
				auxL=m.getAgenda()->buscarApellido(auxS);
				cout << "Lista de pacientes con apellido " << auxS << endl;
				m.mostrarLista(&auxL,false);
				m.fusionLista(auxL);
				break;
			case 3:
				m.cabecera();
				cout << "Lista de favoritos." << endl;
				m.checkFavoritos();
				auxL=m.getAgenda()->buscarFavoritos();
				m.mostrarLista(&auxL,false);
				m.fusionLista(auxL);
				break;
			case 4:
				m.cabecera();
				m.getAgenda()->insertarPaciente(m.rellenaPaciente());
				m.getAgenda()->ordenar();
				break;
			case 5:
				m.cabecera();
				cout << "Guardando agenda." << endl;
				sleep(1);
				m.getAgenda()->guardar();
				cout << "Agenda guardada." << endl;
				break;
			case 6:
				m.cabecera();
				cout << endl << "Gracias por usar el programa. Adios." << endl;
				sleep(2);
				system("clear");
				salir=true;
				break;
			default:
				cout << "Opción no válida. Escriba una entre 1 y 6" << endl;

		}
	}while(!salir);

	return (0);
}
