/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32ropie
 */

#include <list>
#include <string>
#include "Interfaz.h"
#include "Paciente.h"
#include "Agenda.h"
using namespace std;

namespace dentista {

Agenda::Agenda(Interfaz (*i)):db_(i) {
	// TODO Auto-generated constructor stub
	//db_ = i;
}
//Función que devuelve la lista de pacientes.
const std::list<Paciente>& Agenda::getPacientes() const {
	return pacientes_;
}
//Función que asigna la lista de pacientes.
void Agenda::setPacientes(const std::list<Paciente>& pacientes) {
	pacientes_ = pacientes;
}
//Función que devuelve una lista con los pacientes que tengan el mismo apellido que el recibido como parámetro.
list<Paciente> Agenda::buscarApellido(string apellidos) {
	list<Paciente>::iterator i; //Declaro iterador de lista de pacientes.
	list<Paciente> aux; //Creo una lista auxiliar donde guardaré los pacientes con apellido coincidente.
	for ( i=pacientes_.begin() ; i!=pacientes_.end() ; ++i) { //Recorro la lista de pacientes mediante un bucle.
		if ((*i).getApellidos() == apellidos) { //Compruebo si el apellido del paciente i-ésimo coincide con el recibido como parámetro.
			aux.push_back(*i); //En tal caso, lo introduzco en la lista de pacientes con mismo apellido.
		}
	}
	return aux; //Y al finalizar la función, devolvemos dicha lista.
}
//Función que devuelve una lista con los pacientes favoritos. Sigue mismo formato que 'buscarApellido'.
list<Paciente> Agenda::buscarFavoritos(void){
	list<Paciente>::iterator i;
	list<Paciente> aux;
	for( i=pacientes_.begin() ; i!=pacientes_.end() ; ++i) {
		if((*i).isFavorito()){ //Compruebo si el paciente es favorito.
			aux.push_back(*i);
		}
	}
	return aux;
}
//Función que elimina de la lista de pacientes el cual cuyo apellido coincida con el pasado a la función como parámetro.
void Agenda::eliminarPaciente(string DNI){
	list<Paciente>::iterator i; //Declaro iterador de pacientes.
	bool encontrado=false; //Declaro un dato tipo bool que me evite recorrer toda la lista de pacientes si ya ha eliminado el que se quería.
	for( i=pacientes_.begin() ; i!=pacientes_.end() && !encontrado ; ++i) { //Recorro la lista, teniendo en cuenta que no hayamos encontrado aún el paciente a eliminar.
		if((*i).getDni()==DNI){ //Comprobamos si el DNI del paciente coincide con el pasado a la función.
			pacientes_.erase(i); //En tal caso, borro dicho paciente de la lista.
			encontrado=true; //Y actualizamo 'encontrado' para salir del bucle.
		}
	}
}
//Función que ordena los pacientes de la lista por su apellido. Comprueba también el nombre para que sea más exacta.
void Agenda::ordenar(void){
	list<Paciente>::iterator i; //Declaro un iterador de paciente
	list<Paciente> auxP; //Declaro una lista de pacientes auxiliar, donde guardaremos los pacientes ordenados.
	list<string> auxL; //Declaro una lista de string, donde guardaremos el apellido+nombre de los pacientes.
	list<string>::iterator j; //Declaro un iterador de string.
	bool encontrado=false;

	for( i=pacientes_.begin() ; i!=pacientes_.end() ; ++i){ //Recorro la lista de pacientes.
		auxL.push_back((*i).getApellidosNombre()); //Guardo en la lista de string todos los nombres.
	}

	auxL.sort(); //Ordeno alfabéticamente esa lista con la función predefinida 'sort'.

	for( j=auxL.begin() ; j!=auxL.end() ; ++j ){ //Posteriormente, recorro dicha lista.
		for( i=pacientes_.begin() ; i!=pacientes_.end() && !encontrado ; ++i){ //Y por cada nombre, recorro la lista de pacientes.
			if((*i).getApellidosNombre()==(*j)){ //Compruebo si coincide el apellido+nombre del paciente i-ésimo con el de la lista de string.
				auxP.push_back(*i); //En tal caso, lo añado a lista auxiliar de pacientes.
				pacientes_.erase(i);
				encontrado=true;
			}
		}
		encontrado=false;
	}
	//Al terminal el bucle, tendremos en la lista auxP los pacientes ordenados alfabéticamente.
	setPacientes(auxP); //Guardamos en nuestra lista de pacientes la lista ya ordenada.
}
//
void Agenda::guardar(void){
	db_->guardar(pacientes_);
}
//
void Agenda::cargar(void){
	pacientes_=db_->cargar();
}



Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}

} /* namespace dentista */
