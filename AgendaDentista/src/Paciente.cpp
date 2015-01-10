/*
 * Paciente.cpp
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

using namespace std;

namespace dentista {

Paciente::Paciente() {
	// TODO Auto-generated constructor stub
	favorito_ = false;
	frecuencia = 0;
}

const std::string& Paciente::getApellidos() const {
	return apellidos_;
}

void Paciente::setApellidos(const std::string& apellidos) {
	apellidos_ = apellidos;
}

const Direccion& Paciente::getDireccion() const {
	return direccion_;
}

void Paciente::setDireccion(const Direccion& direccion) {
	direccion_ = direccion;
}

const std::string& Paciente::getDni() const {
	return dni_;
}

void Paciente::setDni(const std::string& dni) {
	dni_ = dni;
}

const std::string& Paciente::getNombre() const {
	return nombre_;
}

void Paciente::setNombre(const std::string& nombre) {
	nombre_ = nombre;
}

const RedSocial& Paciente::getRedSocial() const {
	return redSocial_;
}

void Paciente::setRedSocial(const RedSocial& redSocial) {
	redSocial_ = redSocial;
}

const std::string& Paciente::getTelefono() const {
	return telefono_;
}

const std::string& Paciente::getNotas() const {
	return notas_;
}

int Paciente::getFrecuencia() const {
	return frecuencia;
}

bool Paciente::isFavorito() const {
	return favorito_;
}

void Paciente::setFavorito(bool favorito) {
	favorito_ = favorito;
}

void Paciente::setFrecuencia(int frecuencia) {
	this->frecuencia = frecuencia;
}

void Paciente::setNotas(const std::string& notas) {
	notas_ = notas;
}

void Paciente::setTelefono(const std::string& telefono) {
	telefono_ = telefono;
}
//Función que devuelve el apellido del paciente seguido de su nombre con el siguiente formato: apellido, nombre.
string Paciente::getApellidosNombre() {
    return apellidos_+", "+nombre_;
}


Paciente::~Paciente() {
	// TODO Auto-generated destructor stub
}

} /* namespace dentista */
