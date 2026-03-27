#ifndef RESERVA_HPP
#define RESERVA_HPP
#include "Passatger.hpp"
#include "Vol.hpp"
#include <string>
#include <iostream>
using namespace std;

class Reserva {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una reserva d'un vol de la que
// s'indiquen el seu número, el passatger que ha fet la reserva
// el número de vol que ha reservat i el mètode de pagament que ha
// fer servir en reservar.
	
    private:
 		
		// IMPLEMENTACIÓ DE LA CLASSE RESERVA
		// (definició del tipus i nom de cada atribut)

    public:
	
		//*********************************************************
		// Constructors
		//*********************************************************

		/* Pre: cert */
		/* Post: Construeix una reserva sense número de reserva, 
		passatger, número de vol ni mètode de pagament */
		Reserva();
		
		//...
		
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
		~Reserva();
		
		//*********************************************************
		// Consultors
		//*********************************************************

		//...
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************
	
		//...
};
#endif