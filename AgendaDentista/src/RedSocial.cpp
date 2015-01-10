/*
 * RedSocial.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#include <string>
#include "Fichero.h"
#include "MenuTerminal.h"
#include "RedSocial.h"
#include "Direccion.h"
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"

namespace dentista {

RedSocial::RedSocial() {
	// TODO Auto-generated constructor stub
	setCuentaTwitter("-------");
	setCuentaFacebook("-------");

}

const std::string& RedSocial::getCuentaFacebook() const {
	return cuentaFacebook;
}

void RedSocial::setCuentaFacebook(const std::string& cuentaFacebook) {
	this->cuentaFacebook = cuentaFacebook;
}

const std::string& RedSocial::getCuentaTwitter() const {
	return cuentaTwitter;
}

void RedSocial::setCuentaTwitter(const std::string& cuentaTwitter) {
	this->cuentaTwitter = cuentaTwitter;
}

RedSocial::~RedSocial() {
	// TODO Auto-generated destructor stub
}

} /* namespace dentista */
