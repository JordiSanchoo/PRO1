#ifndef VOL_HPP
#define VOL_HPP
#include <string>
#include <iostream>
using namespace std;

class Vol {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un vol del que s'indiquen 
// el seu número, ciutat origen, ciutat destinació, hora de
// sortida, hora d'arribada, estat del vol i nombre de seients
// disponibles.
	
    private:

		// IMPLEMENTACIÓ DE LA CLASSE VOL
		// (definició del tipus i nom de cada atribut)
		
    public:
	
		// ESPECIFICACIÓ DE LA CLASSE VOL
		// (especificació Pre/Post de tots els mètodes)

		//*********************************************************
		// Constructors
		//*********************************************************
	   
		//...
		
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
		~Vol();
   
   		//*********************************************************
		// Modificadors
		//*********************************************************
		
		//...
		
		//*********************************************************
		// Consultors
		//*********************************************************

		/* Pre: cert */
		/* Post: El resultat és el número del vol paràmetre implícit */
        string getNumVol() const;

		/* Pre: cert */
		/* Post: El resultat és la ciutat d'origen del vol paràmetre implícit */
        string getCiutatOrigen() const;
		
		/* Pre: cert */
		/* Post: El resultat és la ciutat destinació del vol paràmetre implícit */
        string getCiutatDest() const;

		/* Pre: cert */
		/* Post: El resultat és l'hora de sortida del vol paràmetre implícit */
        string getHoraSortida() const;

		/* Pre: cert */
		/* Post: El resultat és l'hora d'arribada del vol paràmetre implícit */
        string getHoraArribada() const;

		/* Pre: cert */
		/* Post: El resultat és l'estat del vol paràmetre implícit */
        string getEstatVol() const;
		
		/* Pre: cert */
		/* Post: El resultat és el nombre de seients disponibles del vol paràmetre implícit */
        int getSeientsDisponibles() const;
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************
		
		//...
};
#endif