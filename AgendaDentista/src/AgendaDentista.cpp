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
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"


using namespace std;

int main() {
	// Fichero hereda de interfaz y por eso se admite como parámetro en el constructor
	// de Agenda
	string auxS;
	list<Paciente> auxL;
	list<Paciente>::iterator i;
	salir=false;
	Fichero* f = new Fichero("almacen.txt");
	Agenda a = Agenda(f);
	MenuTerminal m(a); //El programa carga por defecto la base de datos de contactos y la guarda al finalizar el programa.
	do{
		switch(m.menuPrincipal()) {
			case 1:
				system("clear");
				m.visualizarAgenda();

				break;
			case 2:
				system("clear");
				cout << "Introduce el apellido del contacto: ";
				getline(cin,auxS,'\n');
				auxL=m.getAgenda().buscarApellido(auxS);
				cout << "Lista de pacientes con apellido " << auxS << endl;
				mostrarLista(auxL);
				break;
			case 3:
				system("clear");
				cout << "Lista de favoritos." << endl;
				auxL=m.getAgenda().buscarFavoritos();
				mostrarLista(auxL);
				break;
			case 4:
				system("clear");
				m.getAgenda().insertarPaciente(m.rellenaPaciente());
				m.getAgenda().ordenar();
				break;
			case 5:
				system("clear");
				cout << "Guardando agenda." << endl;
				m.getAgenda().guardar();
				cout << "Agenda guardada." << endl;
				break;
			case 6:
			  system("clear");
				cout << endl << "Gracias por usar el programa. Adios." << endl;
				salir=true;
				break;
			default:
			  system("clear");
				cout << "Opción no válida. Escriba una entre 1 y 6" << endl;

		}
	}while(!salir);

	return 0;
}
