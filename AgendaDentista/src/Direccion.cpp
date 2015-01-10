/*
 * Direccion.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#include <string>

#include "Direccion.h"


namespace dentista {

const std::string& dentista::Direccion::getCalle() const {
	return calle_;
}

void dentista::Direccion::setCalle(const std::string& calle) {
	calle_ = calle;
}

const std::string& dentista::Direccion::getEscalera() const {
	return escalera_;
}

void dentista::Direccion::setEscalera(const std::string& escalera) {
	escalera_ = escalera;
}

int dentista::Direccion::getNumPiso() const {
	return numPiso_;
}

void dentista::Direccion::setNumPiso(int numPiso) {
	numPiso_ = numPiso;
}

const std::string& dentista::Direccion::getNumPortal() const {
	return numPortal_;
}

void dentista::Direccion::setNumPortal(const std::string& numPortal) {
	numPortal_ = numPortal;
}

const std::string& dentista::Direccion::getNumPuerta() const {
	return numPuerta_;
}

void dentista::Direccion::setNumPuerta(const std::string& numPuerta) {
	numPuerta_ = numPuerta;
}

const std::string& dentista::Direccion::getTipoVia() const {
	return tipoVia;
}

void dentista::Direccion::setTipoVia(const std::string& tipoVia) {
	this->tipoVia = tipoVia;
}
}
