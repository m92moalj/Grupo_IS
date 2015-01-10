AgendaDentistaEJECUTABLE : Agenda.o AgendaDentista.o Direccion.o Fichero.o Interfaz.o MenuTerminal.o Paciente.o RedSocial.o
  gcc -o AgendaDentistaEJECUTABLE

Agenda.o : Agenda.cpp Agenda.h Paciente.h
  gcc -c Agenda.cpp

AgendaDentista.o : AgendaDentista.cpp
  gcc -c AgendaDentista.cpp

Direccion.o : Direccion.cpp Direccion.h
  gcc -c Direccion.cpp

Fichero.o : Fichero.cpp Fichero.h
  gcc -c Fichero.cpp

Interfaz.o : Interfaz.cpp Interfaz.h Agenda.h
  gcc -c Interfaz.cpp

clean :
  rm *.o
