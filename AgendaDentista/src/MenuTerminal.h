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

class MenuTerminal:public Paciente{
private:
	void menuPrincipal();

public:
	MenuTerminal();
	virtual ~MenuTerminal();
	void visualizarPaciente(Paciente p);
	void visualizarAgenda(Agenda a);


};

} /* namespace dentista */
#endif /* MENUTERMINAL_H_ */
