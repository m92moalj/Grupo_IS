/*
 * Agenda.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef AGENDA_H_
#define AGENDA_H_
#include <list>
#include <iostream>
#include "Paciente.h"

namespace dentista {

class Agenda {
public:
	Agenda();
	virtual ~Agenda();
	const std::list<Paciente>& getPacientes() const;
	void setPacientes(const std::list<Paciente>& pacientes);
	std::list<Paciente> buscarApellido(std::string apellidos);
	std::list<Paciente> buscarFavoritos(void);
	void virtual insertarPaciente(Paciente p){std::cout << "Función no definida para esta clase." << std::endl;}

private:
	std::list<Paciente> pacientes_;
};

} /* namespace dentista */
#endif /* AGENDA_H_ */
