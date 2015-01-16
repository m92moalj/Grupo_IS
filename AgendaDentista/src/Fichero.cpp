#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Interfaz.h"
#include "Fichero.h"
#include "Paciente.h"
#include "RedSocial.h"
#include "Direccion.h"

using namespace std;

namespace dentista {

list<Paciente> Fichero::cargar(void){
    list<Paciente> auxL;
    Paciente auxP;
    RedSocial auxR;
    Direccion auxD;
    char linea[256];
    ifstream f(stringToChar(fichero_));
    while(f.getline(linea,256,',')){
        auxP.setNombre(linea);
        f.getline(linea,256,',');
        auxP.setApellidos(linea);
        f.getline(linea,256,',');
        auxP.setDni(linea);
        f.getline(linea,256,',');
        auxP.setTelefono(linea);
        f.getline(linea,256,',');
        auxR.setCuentaFacebook(linea);
        f.getline(linea,256,',');
        auxR.setCuentaTwitter(linea);
        auxP.setRedSocial(auxR);
        f.getline(linea,256,',');
        auxD.setCalle(linea);
        f.getline(linea,256,',');
        auxD.setNumPortal(linea);
        f.getline(linea,256,',');
        auxD.setNumPiso(atoi(linea));
        f.getline(linea,256,',');
        auxD.setNumPuerta(linea);
        f.getline(linea,256,',');
        auxD.setEscalera(linea);
        f.getline(linea,256,',');
        auxD.setTipoVia(linea);
        auxP.setDireccion(auxD);
        f.getline(linea,256,',');
        auxP.setNotas(linea);
        f.getline(linea,256,',');
        if(linea=="true") auxP.setFavorito(true); //Da warning, pero funciona perfecto.
        else if(linea=="false") auxP.setFavorito(false); //Da warning, pero funciona perfecto.
        else cout << "Error cargando favorito en: " << auxP.getApellidosNombre() << endl;
        f.getline(linea,256);
        auxP.setFrecuencia(atoi(linea));
        auxL.push_back(auxP);
    }
    return (auxL);
}

int Fichero::guardar(list<Paciente> pacientes){
    ofstream f(stringToChar(fichero_));
    list<Paciente>::iterator i;
    for(i=pacientes.begin() ; i!=pacientes.end() ; ++i){
        f << (*i).getNombre();
        f << "," ;
        f << (*i).getApellidos();
        f << ",";
        f << (*i).getDni();
        f << ",";
        f << (*i).getTelefono();
        f << ",";
        f << (*i).getRedSocial().getCuentaFacebook();
        f << ",";
        f << (*i).getRedSocial().getCuentaTwitter();
        f << ",";
        f << (*i).getDireccion().getCalle();
        f << ",";
        f << (*i).getDireccion().getNumPortal();
        f << ",";
        f << (*i).getDireccion().getNumPiso();
        f << ",";
        f << (*i).getDireccion().getNumPuerta();
        f << ",";
        f << (*i).getDireccion().getEscalera();
        f << ",";
        f << (*i).getDireccion().getTipoVia();
        f << ",";
        f << (*i).getNotas();
        f << ",";
        if((*i).isFavorito()) f << "true,";
        else f << "false,";
        f << (*i).getFrecuencia();
        f << "\n";
    }

    return (1);
}

}
