/*
 * RedSocial.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef REDSOCIAL_H_
#define REDSOCIAL_H_

#include <string>
#include "Fichero.h"
#include "MenuTerminal.h"
#include "Direccion.h"
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"

namespace dentista {

class RedSocial {
private:
	std::string cuentaFacebook;
	std::string cuentaTwitter;

public:
	RedSocial();
	virtual ~RedSocial();
	const std::string& getCuentaFacebook() const;
	void setCuentaFacebook(const std::string& cuentaFacebook);
	const std::string& getCuentaTwitter() const;
	void setCuentaTwitter(const std::string& cuentaTwitter);
};

} /* namespace dentista */
#endif /* REDSOCIAL_H_ */
