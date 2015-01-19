/*
 * MenuTerminal.h
 *
 *  Created on: 17/12/2014
 *      Author: i32marej
 */

#ifndef MENUTERMINAL_H_
#define MENUTERMINAL_H_

#include "Paciente.h"
#include "Agenda.h"

namespace dentista {

class MenuTerminal{
private:
	Agenda* a_;
public:
	MenuTerminal(Agenda *a);
	virtual ~MenuTerminal();
	void cabecera();
	int menuPrincipal();
	void visualizarPaciente(Paciente p);
	void visualizarAgenda();
	void llamarPaciente(Paciente *p);
	Agenda* getAgenda(void){return (a_);};
	void setAgenda(Agenda* a){a_=a;};
	void mostrarLista(std::list<Paciente> *pacientes);
	Paciente rellenaPaciente();
	void checkFavoritos(void);
	void fusionLista(std::list<Paciente> aux);
};

} /* namespace dentista */

#endif /* MENUTERMINAL_H_ */
