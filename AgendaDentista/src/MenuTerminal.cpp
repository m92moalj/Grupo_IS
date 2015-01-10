/*
 * MenuTerminal.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i32marej
 */

#include <iostream>
#include <list>
#include <cstdio>
#include "Fichero.h"
#include "MenuTerminal.h"
#include "RedSocial.h"
#include "Direccion.h"
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"

using namespace std;

namespace dentista {

MenuTerminal::MenuTerminal(Agenda a) {
	// TODO Auto-generated constructor stub
	a_=a;
	a_.cargar();
	a_.ordenar();
	list<Paciente>::iterator i;
	for( i=a_.getPacientes().begin() ; i!=a_.getPacientes().end() ; ++i){
		if(!(*i).getFavorito() && (*i).getFrecuencia()<10 ) (*i).setFavorito(true);
	}
}

MenuTerminal::~MenuTerminal() {
	// TODO Auto-generated destructor stub
}

void MenuTerminal::menuPrincipal() {
	int opcion=0;
	system("clear");
	cout << "##########################################";
	cout << "##########################################";
	cout << "#####                                #####";
	cout << "#####             Agenda             #####";
	cout << "#####           OranGITops           #####";
	cout << "#####                                #####";
	cout << "#####                          v 1.0 #####";
	cout << "##########################################";
	cout << "##########################################" << endl;
	cout << "\e[1mOpciones de la agenda:" << endl;
	cout << "\t\e[31m1)\e[0m Visualizar agenda. (Se mostrarán todos los pacientes)" << endl;
	cout << "\t\e[1;31m2)\e[0m Buscar contacto por apellido. (Se mostrarán todos los pacientes con apellido coincidente)" << endl;
	cout << "\t\e[1;31m3)\e[0m Visualizar contactos favoritos. (Se mostrarán todos los pacientes favoritos)" << endl;
	cout << "\t\e[1;31m4)\e[0m Añadir paciente.";
	cout << "\t\e[1;31m5)\e[0m Guardar agenda." << endl;
	cout << "\t\e[1;31m6)\e[0m Salir del programa." << endl;
	cout << "Elija qué pción desea realizar: ";
	cin >> opcion;

	return opcion;
}

void MenuTerminal::visualizarAgenda(){
	mostrarLista(a_.getPacientes());
}

void MenuTerminal::mostrarLista(list<Paciente> *pacientes){
	int j=1,opcion;
	Paciente aux;
	list<Paciente>::iterator i;
	for( i=pacientes->begin() ; i!=pacientes->end() ; ++i ){
		cout << "Paciente " <<j<< ": " << (*i).getApellidosNombre() << endl;
		j++;
	}
	cout << endl << "¿Quieres ver algun paciente en especial? Introduce el numero o 0 si ninguno de ellos: ";
	cin >> opcion;
	if(opcion==0){
		cout << "De acuerdo. Volviendo al menú principal." << endl;
	}
	else if(opcion<0 && opcion>j){
		cout << "Número no válido." << endl;
	}
	else{
		for( i=pacientes->begin() , j=1 ; j<opcion ; ++j, ++i);
		aux=*i;
		llamarPaciente(&aux);
		*i=aux;
		cout << endl << "Opciones disponibles:" << endl;
		cout << "\t\e[1;31m1)\e[0m Modificar paciente." << endl;
		cout << "\t\e[1;31m2)\e[0m Eliminar paciente." << endl;
		cout << "\tCualquier otro numero para volver al menu principal." << endl;
		cout << "Elija una opción: ";
		cin >> opcion;
		switch(opcion) {
			case 1:
			*i=rellenaPaciente();
			break;
			case 2:
			pacientes->erase(i);
			break;
		}
	}
}

void MenuTerminal::visualizarPaciente(Paciente p){
	cout << "\tNombre: " << p.getApellidosNombre() << endl;
	cout << "\tDNI: " << p.getDni() << endl;
	cout << "\tTeléfono: " << p.getTelefono() << endl;
	cout << "\tCuenta Facebook: " << p.getRedSocial().getCuentaFacebook() << endl;
	cout << "\tCuenta Twitter: " << p.getRedSocial().getCuentaTwitter() << endl;
	cout << "\tDirección: " << p.getDireccion().getTipoVia() << " " << p.getDireccion().getCalle() << " nº " << p.getDireccion().getNumPortal() << ", Escalera " << p.getDireccion().getEscalera() << " " << p.getDireccion().getNumPiso() << "º " << p.getDireccion().getNumPuerta() << endl;
	cout << "\tNotas: " << p.getNotas() << endl;
	if(p.getFavorito()) cout << "\tFavorito: Sí" << endl;
	else cout << "\tFavorito: No" << endl;
	cout << "\tFrecuencia: " << p.getFrecuencia() << endl<<endl;
}

void MenuTerminal::llamarPaciente(Paciente *p){
	p->setFrecuencia(p->getFrecuencia()+1);
	visualizarPaciente(*p);
}

Paciente MenuTerminal::rellenaPaciente(){
	Paciente auxP;
	RedSocial auxR;
	Direccion auxD;
	string auxS;
	cout << "Nombre: ";
	cin >> auxS;
	auxP.setNombre(auxS);
	cout << "Apellidos: ";
	getline(cin, auxS, '\n');
	auxP.setApellidos(auxS);
	cout << "DNI: ";
	cin >> auxS;
	auxP.setDNI(auxS);
	cout << "Teléfono: ";
	cin >> auxS;
	auxP.setTelefono(auxS);
	cout << "Cuenta facebook: ";
	getline(cin, auxS, '\n');
	auxR.setFacebook(auxS);
	cout << "Cuenta twitter: ";
	cin >> auxS;
	auxR.setTwitter(auxS);
	auxP.setRedSocial(auxP);
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
	auxD.setNumPiso(auxS);
	cout << "Nº Puerta: ";
	getline(cin, auxS, '\n');
	auxD.setNumPuerta(auxS);
	auxP.setDireccion(auxD);
	cout << "Notas del paciente: ";
	getline(cin, auxS, '\n');
	auxP.setNotas(auxS);

	return auxP;
}

} /* namespace dentista */
