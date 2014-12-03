/*
 * RedSocial.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef REDSOCIAL_H_
#define REDSOCIAL_H_

namespace dentista {

class RedSocial {
private:
	std::string cuentaFacebook;
	std::string cuentaTwitter;

public:
	RedSocial();
	virtual ~RedSocial();

	const std::string& getCuentaFacebook() const {
		return cuentaFacebook;
	}

	void setCuentaFacebook(const std::string& cuentaFacebook) {
		this->cuentaFacebook = cuentaFacebook;
	}

	const std::string& getCuentaTwitter() const {
		return cuentaTwitter;
	}

	void setCuentaTwitter(const std::string& cuentaTwitter) {
		this->cuentaTwitter = cuentaTwitter;
	}
};

} /* namespace dentista */
#endif /* REDSOCIAL_H_ */
