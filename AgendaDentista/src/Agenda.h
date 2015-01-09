/*
 * Agenda.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef AGENDA_H_
#define AGENDA_H_
#include <list>
#include <string>
#include <iostream>
#include "Paciente.h"

namespace dentista {

class Agenda {
public:
	Agenda(Interfaz *i);
	virtual ~Agenda();
	const std::list<Paciente>& getPacientes() const;
	void setPacientes(const std::list<Paciente>& pacientes);
	std::list<Paciente> buscarApellido(std::string apellidos);
	std::list<Paciente> buscarFavoritos(void);
	void insertarPaciente(Paciente p){pacientes_.push_back(p);};
	void eliminarPaciente(std::string DNI);
	void ordenar(void);
	void guardar(void);
	void cargar(void);
private:
	std::list<Paciente> pacientes_;
	Interfaz* db_;

};

} /* namespace dentista */
#endif /* AGENDA_H_ */
