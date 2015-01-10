/*
 * MenuTerminal.h
 *
 *  Created on: 17/12/2014
 *      Author: i32marej
 */

#ifndef MENUTERMINAL_H_
#define MENUTERMINAL_H_

#include "Fichero.h"
#include "RedSocial.h"
#include "Direccion.h"
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"

namespace dentista {

class MenuTerminal{
private:
	Agenda a_;
public:
	MenuTerminal(Agenda a);
	virtual ~MenuTerminal();
	void menuPrincipal();
	void visualizarPaciente(Paciente p);
	void visualizarAgenda();
	void llamarPaciente(Paciente *p);
	Agenda getAgenda(void){return a_;};
	void setAgenda(Agenda a){a_=a;};
	void visualizarAgenda();
};

} /* namespace dentista */
#endif /* MENUTERMINAL_H_ */
