#ifndef FICHERO_H_
#define FICHERO_H

#include <string>
#include <list>

#include "Interfaz.h"
#include "Paciente.h"


class Fichero: Public Interfaz {
private:
    std::string fichero_;
public:
    Fichero(std::string fichero):fichero_(fichero){};
    std::list<Paciente> cargar();
    void guardar(std::list<Paciente> pacientes);
};



#endif
