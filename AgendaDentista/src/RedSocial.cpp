/*
 * RedSocial.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#include <string>

#include "RedSocial.h"

namespace dentista {

RedSocial::RedSocial() {
	// TODO Auto-generated constructor stub
	setCuentaTwitter("-------");
	setCuentaFacebook("-------");

}

const std::string& RedSocial::getCuentaFacebook() const {
	return (cuentaFacebook_);
}

void RedSocial::setCuentaFacebook(const std::string& cuentaFacebook) {
	this->cuentaFacebook_ = cuentaFacebook;
}

const std::string& RedSocial::getCuentaTwitter() const {
	return (cuentaTwitter_);
}

void RedSocial::setCuentaTwitter(const std::string& cuentaTwitter) {
	this->cuentaTwitter_ = cuentaTwitter;
}

RedSocial::~RedSocial() {
	// TODO Auto-generated destructor stub
}

} /* namespace dentista */
