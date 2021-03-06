/*
 * Paciente.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <string>

#include "RedSocial.h"
#include "Direccion.h"

namespace dentista {

class Paciente {
private:
	std::string dni_;
	std::string nombre_;
	std::string apellidos_;
	std::string telefono_;
	RedSocial redSocial_;
	Direccion direccion_;
	std::string notas_;
	bool favorito_;
	int frecuencia_;

public:
	Paciente();
	virtual ~Paciente();
	const std::string& getApellidos() const;
	void setApellidos(const std::string& apellidos);
	const Direccion& getDireccion() const;
	void setDireccion(const Direccion& direccion);
	const std::string& getDni() const;
	void setDni(const std::string& dni);
	const std::string& getNombre() const;
	void setNombre(const std::string& nombre);
	const RedSocial& getRedSocial() const;
	void setRedSocial(const RedSocial& redSocial);
	const std::string& getTelefono() const;
	void setTelefono(const std::string& telefono);
	const std::string& getNotas() const;
	void setNotas(const std::string& notas);
	int getFrecuencia() const;
	void setFrecuencia(int frecuencia_);
	bool isFavorito() const;
	void setFavorito(bool favorito);
	std::string getApellidosNombre();
	bool operator<(Paciente &p);
};

} /* namespace dentista */

char *stringToChar(std::string aux1);

#endif /* PACIENTE_H_ */
