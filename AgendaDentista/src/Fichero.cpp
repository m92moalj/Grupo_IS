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
    ofstream f(fichero_);
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
        if((*i).getFavorito()) f << "true,";
        else f << "false,";
        f << (*i).getFrecuencia();
        f << "\n";
    }
}
