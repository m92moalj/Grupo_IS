//============================================================================
// Name        : AgendaDentista.cpp
// Author      : OranGITops
// Version     :
// Copyright   : OranGITops
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	// Fichero hereda de interfaz y por eso se admite como parámetro en el constructor
	// de Agenda
	Fichero* f = new Fichero("almacen.txt");
	Agenda a = Agenda(f);
	cout << "OranGITops" << endl; // prints OranGITops
	return 0;
}
