/*
 * MenuTerminal.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i32marej
 */

#include <iostream>

#include "MenuTerminal.h"
#include "Agenda.h"
#include "Paciente.h"

using namespace std;

namespace dentista {

MenuTerminal::MenuTerminal() {
	// TODO Auto-generated constructor stub

}

MenuTerminal::~MenuTerminal() {
	// TODO Auto-generated destructor stub
}

void MenuTerminal::menuPrincipal() {

}

void MenuTerminal::visualizarAgenda(Agenda a){

}

void MenuTerminal::visualizarPaciente(Paciente p){
	cout<<p.getDni()<<endl;
	cout<<p.getNombre()<<endl;
	cout<<p.getApellidos()<<endl;
	cout<<p.getTelefono()<<endl;
	cout<<p.getRedSocial()<<endl;
	cout<<p.getDireccion<<endl;
	cout<<p.getNotas()<<endl;



}


} /* namespace dentista */
