AgendaDentistaEJECUTABLE : Agenda.o AgendaDentista.o Direccion.o Fichero.o Interfaz.o MenuTerminal.o Paciente.o RedSocial.o
	g++ Agenda.o AgendaDentista.o Direccion.o Fichero.o Interfaz.o MenuTerminal.o Paciente.o RedSocial.o -o AgendaDentistaEJECUTABLE

Agenda.o : Agenda.cpp Agenda.h Paciente.h Interfaz.h
	gcc -c Agenda.cpp

AgendaDentista.o : AgendaDentista.cpp Agenda.h Paciente.h Interfaz.h MenuTerminal.h Fichero.h
	gcc -c AgendaDentista.cpp

Direccion.o : Direccion.cpp Direccion.h
	gcc -c Direccion.cpp

Fichero.o : Fichero.cpp Fichero.h Interfaz.h Paciente.h RedSocial.h Direccion.h
	gcc -c Fichero.cpp

Interfaz.o : Interfaz.cpp Interfaz.h
	gcc -c Interfaz.cpp

MenuTerminal.o : MenuTerminal.cpp MenuTerminal.h RedSocial.h Direccion.h Paciente.h Agenda.h
	gcc -c MenuTerminal.cpp

Paciente.o : Paciente.cpp Paciente.h RedSocial.h Direccion.h
	gcc -c Paciente.cpp

RedSocial.o : RedSocial.cpp RedSocial.h
	gcc -c RedSocial.cpp

clean :
	rm *.o
