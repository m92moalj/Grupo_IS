/*
 * Interfaz.h
 *
 *  Created on: 09/12/2014
 *      Author: i32ropie
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include <list>
#include "Fichero.h"
#include "MenuTerminal.h"
#include "RedSocial.h"
#include "Direccion.h"
#include "Paciente.h"
#include "Agenda.h"

using namespace dentista;

class Interfaz: public Agenda {
public:
	Interfaz();
	virtual ~Interfaz();

	virtual std::list<Paciente> cargar() = 0;
	virtual int guardar(std::list<Paciente>) = 0;

private:

};

#endif /* INTERFAZ_H_ */
