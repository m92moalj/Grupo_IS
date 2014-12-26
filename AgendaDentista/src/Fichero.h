#ifndef FICHERO_H_
#define FICHERO_H



class Fichero: Public Interfaz {
private:
    std::string fichero_;
public:
    Fichero(std::string fichero):fichero_(fichero){};
    std::list<Paciente> cargar();
    bool guardar(std::list<Paciente> pacientes);
};



#endif
