/*
 * RedSocial.h
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#ifndef REDSOCIAL_H_
#define REDSOCIAL_H_

#include <string>

namespace dentista {

class RedSocial {
private:
	std::string cuentaFacebook_;
	std::string cuentaTwitter_;

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
