/*
 * Interfaz.h
 *
 *  Created on: 09/12/2014
 *      Author: i32ropie
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "Agenda.h"

using namespace dentista;

class Interfaz: public Agenda {
public:
	Interfaz();
	virtual ~Interfaz();
	void virtual insertarPaciente(Paciente p);
private:

};

#endif /* INTERFAZ_H_ */
