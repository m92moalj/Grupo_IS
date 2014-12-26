#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include "Fichero.h"

using namespace dentista;
using namespace std;

list<Paciente> Fichero::cargar(void){
    list<Paciente> auxL;
    Paciente auxP;
    RedSocial auxR;
    Direccion auxD;
    bool auxB;
    char linea[256];
    ifstream f(fichero_);
    while(f.getline(linea,256,',')){
        auxP.setNombre(linea);
        f.getline(linea,256,',');
        auxP.setApellidos(linea);
        f.getline(linea,256,',');
        auxP.setDni();
        f.getline(linea,256,',');
        auxP.setTelefono(linea);
        f.getline(linea,256,',');
        auxR.setCuentaFacebook(linea);
        f.getline(linea,256,',');
        auxR.setCuentaTwitter(linea);
        auxP.setRedSocial(auxR);
        /*
        *
        * Hueco para Dirección.
        *
        */
        auxP.setDireccion(auxD);
        f.getline(linea,256,',');
        auxP.setNotas(linea);
        f.getline(linea,256,',');
        if(linea=="true") auxB=true;
        else if(linea=="false") auxB=false;
        else cout << "Error cargando favorito en: " << auxP.getApellidosNombre() << endl;
        f.getline(linea,256);
        auxP.setFrequencia(atoi(linea));
        auxL.push_back(auxP);
    }
    return auxL;
}

void Fichero::guardar(list<Paciente> pacientes){
    /*
    *
    * Añadir en algún lado comprobar que ya exista el fichero y no esté vacío. Si no lo está, preguntar si sobreescribir o dejar como está.
    *
    */
    ofstream f(fichero_);
    list<Paciente>::iterator i;
    for(i=pacientes.begin() ; i!=pacientes.end() ; ++i){
        f << (*i).getNombre() << "," << (*i).getApellidos() << "," << (*i).getDni() << "," << (*i).getTelefono() << "," << (*i).getCuentaFacebook() << "," << (*i).getCuentaTwitter() << "," << /* Hueco para dirección */ << "," << (*i).getNotas() << ",";
        if((*i).getFavorito()) f << "true," << (*i).getFrecuencia() << endl;
        else f << "false," << (*i).getFrecuencia() << endl;
    }
}
