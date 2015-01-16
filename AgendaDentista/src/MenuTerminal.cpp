/*
 * MenuTerminal.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i32marej
 */

#include <iostream>
#include <list>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include "MenuTerminal.h"
#include "RedSocial.h"
#include "Direccion.h"
#include "Paciente.h"
#include "Agenda.h"

using namespace std;

namespace dentista {

MenuTerminal::MenuTerminal(Agenda *a) {
	a_ = a;
	// Añadiendo las dos próximas líneas, cargamos en la agenda del programa los pacientes que hay en nuestro fichero externo
	// y ordenamos la lista (Por si se hubiera manipulado la lista manualmente). Así aumentamos drásticamente la comodidad
	// del encargado de la Agenda, ya que siempre que abra el programa, tendrá su lista cargada y ordenada correctamente.
	a_->cargar();
	a_->ordenar();
}

MenuTerminal::~MenuTerminal() {
}

void MenuTerminal::cabecera(){
	system("clear");
		cout << "##########################################" << endl;
		cout << "##########################################" << endl;
		cout << "#####                                #####" << endl;
		cout << "#####             Agenda             #####" << endl;
		cout << "#####           OranGITops           #####" << endl;
		cout << "#####                                #####" << endl;
		cout << "#####                          v 1.2 #####" << endl;
		cout << "##########################################" << endl;
		cout << "##########################################" << endl << endl;
}

int MenuTerminal::menuPrincipal() {
	int opcion = 0;
	cabecera();
	cout << "Opciones de la agenda:" << endl;
	cout << "\t1) Visualizar agenda. (Se mostrarán todos los pacientes)" << endl;
	cout << "\t2) Buscar contacto por apellido. (Se mostrarán todos los pacientes con apellido coincidente)" << endl;
	cout << "\t3) Visualizar contactos favoritos. (Se mostrarán todos los pacientes favoritos)" << endl;
	cout << "\t4) Añadir paciente." << endl;
	cout << "\t5) Guardar agenda." << endl;
	cout << "\t6) Salir del programa." << endl << endl;
	cout << "Elija qué opción desea realizar: ";
	cin >> opcion;

	return (opcion);
}

void MenuTerminal::visualizarAgenda() {
	mostrarLista(&(a_->getPacientes()));
}

void MenuTerminal::mostrarLista(list<Paciente> *pacientes, bool eliminar) {
	int j = 1, opcion=0;
	Paciente aux;
	list<Paciente>::iterator i,k;
	for (i = pacientes->begin(); i != pacientes->end(); ++i) {
		cout << "Paciente " << j << ": " << (*i).getApellidosNombre() << endl;
		j++;
	}
	j--;
	cout << endl
			<< "¿Quieres ver algun paciente en especial? Introduce el número o 0 si ninguno de ellos: ";
	cin >> opcion;
	if (opcion == 0) {
		cabecera();
		cout << "Volviendo al menú principal." << endl;
		sleep(2);
	}
	else{
		if ((opcion<0) || (opcion>j)) {
			cabecera();
			cout << "Número no válido. Volviendo al menú principal." << endl;
			sleep(2);
		}
		else {
			for (i = pacientes->begin(), j = 1; j < opcion; ++j, ++i);
			aux = *i;
			llamarPaciente(&aux);
			*i = aux;
			cout << "Opciones disponibles:" << endl;
			cout << "\t1) Modificar paciente." << endl;
			if(eliminar) cout << "\t2) Eliminar paciente." << endl;
			cout << "\tCualquier otro numero para volver al menú principal."
					<< endl;
			cout << "Elija una opción: ";
			cin >> opcion;
			switch (opcion) {
				case 1:
					aux.setFrecuencia((*i).getFrecuencia());
					*i = rellenaPaciente();
					(*i).setFrecuencia(aux.getFrecuencia());
					break;
				case 2:
					/*for (k = a_->getPacientes().begin(); k != a_->getPacientes().end() ; ++k) {
						if (!((*i).getApellidosNombre().compare((*k).getApellidosNombre()))) {
							a_->getPacientes().erase(k);
						}
					}*/
					if(eliminar) pacientes->erase(i);
					else{
						cout << "volviendo al menú principal.";
						sleep(2);
					}
					break;
				default:
					cout << "volviendo al menú principal.";
					sleep(2);
				}
		}
	}
}

void MenuTerminal::visualizarPaciente(Paciente p) {
	cout << "\tNombre: " << p.getApellidosNombre() << endl;
	cout << "\tDNI: " << p.getDni() << endl;
	cout << "\tTeléfono: " << p.getTelefono() << endl;
	cout << "\tCuenta Facebook: " << p.getRedSocial().getCuentaFacebook()
			<< endl;
	cout << "\tCuenta Twitter: " << p.getRedSocial().getCuentaTwitter() << endl;
	cout << "\tDirección: " << p.getDireccion().getTipoVia() << " " << p.getDireccion().getCalle() << " nº " << p.getDireccion().getNumPortal() << ", Escalera " << p.getDireccion().getEscalera() << " " << p.getDireccion().getNumPiso() << "º " << p.getDireccion().getNumPuerta() << endl;
	cout << "\tNotas: " << p.getNotas() << endl;
	if (p.isFavorito())
		cout << "\tFavorito: Sí" << endl;
	else
		cout << "\tFavorito: No" << endl;
	cout << "\tFrecuencia: " << p.getFrecuencia() << endl << endl;
}

void MenuTerminal::llamarPaciente(Paciente *p) {
	p->setFrecuencia(p->getFrecuencia() + 1);
	visualizarPaciente(*p);
}

Paciente MenuTerminal::rellenaPaciente() {
	Paciente auxP;
	RedSocial auxR;
	Direccion auxD;
	string auxS;
	cout << "Nombre: ";
	getchar();
	getline(cin, auxS, '\n');
	auxP.setNombre(auxS);
	cout << "Apellidos: ";
	getline(cin, auxS, '\n');
	auxP.setApellidos(auxS);
	cout << "DNI: ";
	cin >> auxS;
	auxP.setDni(auxS);
	cout << "Teléfono: ";
	cin >> auxS;
	getchar();
	auxP.setTelefono(auxS);
	cout << "Cuenta facebook: ";
	getline(cin, auxS, '\n');
	auxR.setCuentaFacebook(auxS);
	cout << "Cuenta twitter: ";
	getline(cin, auxS, '\n');
	auxR.setCuentaTwitter(auxS);
	auxP.setRedSocial(auxR);
	cout << "Tipo de vía: ";
	getline(cin, auxS, '\n');
	auxD.setTipoVia(auxS);
	cout << "Calle: ";
	getline(cin, auxS, '\n');
	auxD.setCalle(auxS);
	cout << "Portal: ";
	getline(cin, auxS, '\n');
	auxD.setNumPortal(auxS);
	cout << "Escalera: ";
	getline(cin, auxS, '\n');
	auxD.setEscalera(auxS);
	cout << "Nº Piso: ";
	getline(cin, auxS, '\n');
	auxD.setNumPiso(atoi(stringToChar(auxS)));
	cout << "Nº Puerta: ";
	getline(cin, auxS, '\n');
	auxD.setNumPuerta(auxS);
	auxP.setDireccion(auxD);
	cout << "Notas del paciente: ";
	getline(cin, auxS, '\n');
	auxP.setNotas(auxS);

	return (auxP);
}
//Función que transforma a favorito cualquier paciente con frecuencia superior a 10.
void MenuTerminal::checkFavoritos(void) {
	list<Paciente>::iterator i;
	for (i = a_->getPacientes().begin(); i != a_->getPacientes().end(); ++i) {
		if ((*i).getFrecuencia() > 10) {
			(*i).setFavorito(true);
		}
	}
}
//Función que fusiona dos listas de pacientes, comprobando por cada paciente de 'aux',
//si su nombre y apellidos coincide con el de los pacientes de la agenda para actualizarlo.
//Función vulnerable a que cambien el nombre o apellido.
void MenuTerminal::fusionLista(list<Paciente> aux) {
	list<Paciente>::iterator i, j;
	for (i = aux.begin(); i != aux.end(); ++i) {
		for (j = a_->getPacientes().begin(); j != a_->getPacientes().end();++j) {
			if (!((*i).getApellidosNombre().compare((*j).getApellidosNombre()))) {
				*j = *i;
			}
		}
	}
}

} /* namespace dentista */

