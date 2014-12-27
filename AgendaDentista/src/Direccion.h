/*
 * Direccion.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef DIRECCION_H
#define DIRECCION_H
#include <string>

namespace dentista {

class Direccion {
private:
	std::string calle_;
	std::string numPortal_;
	int numPiso_;
	std::string numPuerta_;
	std::string escalera_;
	std::string tipoVia;

public:
	const std::string& getCalle() const;
	void setCalle(const std::string& calle);
	const std::string& getEscalera() const;
	void setEscalera(const std::string& escalera);
	int getNumPiso() const;
	void setNumPiso(int numPiso);
	const std::string& getNumPortal() const;
	void setNumPortal(const std::string& numPortal);
	const std::string& getNumPuerta() const;
	void setNumPuerta(const std::string& numPuerta);
	const std::string& getTipoVia() const;
	void setTipoVia(const std::string& tipoVia);
};

}
#endif
