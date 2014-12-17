/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#include <list>
#include <string>
#include "Agenda.h"
#include "Paciente.h"

using namespace std;

namespace dentista {

Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}

const std::list<Paciente>& Agenda::getPacientes() const {
	return pacientes_;
}

void Agenda::setPacientes(const std::list<Paciente>& pacientes) {
	pacientes_ = pacientes;
}

list<Paciente> Agenda::buscarApellido(string apellidos) {
	list<Paciente>::iterator i;
	list<Paciente> aux;
	for (i = pacientes_.begin(); i != pacientes_.end(); ++i) {
		if ((*i).getApellidos() == apellidos) {
			aux.push_back(*i);
		}
	}
	return aux;
}
list<Paciente> Agenda::buscarFavoritos(void){
	
}

} /* namespace dentista */
