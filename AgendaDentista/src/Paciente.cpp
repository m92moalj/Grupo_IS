/*
 * Paciente.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#include <string>
#include <cstring>
#include "RedSocial.h"
#include "Direccion.h"
#include "Paciente.h"

using namespace std;

namespace dentista {

Paciente::Paciente() {
	// TODO Auto-generated constructor stub
	favorito_ = false;
	frecuencia_ = 0;
}

const string& Paciente::getApellidos() const {
	return (apellidos_);
}

void Paciente::setApellidos(const string& apellidos) {
	apellidos_ = apellidos;
}

const Direccion& Paciente::getDireccion() const {
	return (direccion_);
}

void Paciente::setDireccion(const Direccion& direccion) {
	direccion_ = direccion;
}

const string& Paciente::getDni() const {
	return (dni_);
}

void Paciente::setDni(const string& dni) {
	dni_ = dni;
}

const string& Paciente::getNombre() const {
	return (nombre_);
}

void Paciente::setNombre(const string& nombre) {
	nombre_ = nombre;
}

const RedSocial& Paciente::getRedSocial() const {
	return (redSocial_);
}

void Paciente::setRedSocial(const RedSocial& redSocial) {
	redSocial_ = redSocial;
}

const string& Paciente::getTelefono() const {
	return (telefono_);
}

const string& Paciente::getNotas() const {
	return (notas_);
}

int Paciente::getFrecuencia() const {
	return (frecuencia_);
}

bool Paciente::isFavorito() const {
	return (favorito_);
}

void Paciente::setFavorito(bool favorito) {
	favorito_ = favorito;
}

void Paciente::setFrecuencia(int frecuencia) {
	this->frecuencia_ = frecuencia;
}

void Paciente::setNotas(const string& notas) {
	notas_ = notas;
}

void Paciente::setTelefono(const string& telefono) {
	telefono_ = telefono;
}
//Función que devuelve el apellido del paciente seguido de su nombre con el siguiente formato: apellido, nombre.
string Paciente::getApellidosNombre() {
	return (apellidos_ + ", " + nombre_);
}

bool Paciente::operator<(Paciente &p) {
	if (getApellidos().compare(p.getApellidos()) < 0) {
		return (true);
	} else {
		return (false);
	}
}

Paciente::~Paciente() {
	// TODO Auto-generated destructor stub
}

} /* namespace dentista */

char *stringToChar(string aux1) {
	int len = aux1.length();
	char *aux2 = new char[len + 1];
	strcpy(aux2, aux1.c_str());
	return (aux2);
}
