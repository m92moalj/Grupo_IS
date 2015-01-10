#ifndef FICHERO_H_
#define FICHERO_H

#include <string>
#include <list>
#include "MenuTerminal.h"
#include "RedSocial.h"
#include "Direccion.h"
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"

class Fichero: Public Interfaz {
private:
    std::string fichero_;
public:
    Fichero(std::string fichero):fichero_(fichero){};
    std::list<Paciente> cargar();
    void guardar(std::list<Paciente> pacientes);
};



#endif
