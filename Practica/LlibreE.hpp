#ifndef LLIBREE_HPP
#define LLIBREE_HPP
#include "Data.hpp"
#include <iostream>
using namespace std;

#define nat unsigned int

class LlibreE {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un llibre electrònic
// que consta de títol, data de publicació, àrea temàtica
// i paraules clau que descriuen el seu contingut.

	public:

		//*********************************************************
		// Constructors i assignació
		//*********************************************************
		
		/* Pre: cert */ 
		/* Post: crea un llibre amb el títol, data de publicació i 
		   àrea buits, i sense paraules clau */
		LlibreE();
		
		/* Pre: cert */ 
		/* Post: crea un llibre amb el títol, data de publicació, 
		   àrea i paraules clau del llibre 'le' */
		LlibreE(const LlibreE &le);
		  
		/* Pre: cert */
		/* Post: el resultat és un llibre amb el títol, data de 
		   publicació, àrea i paraules clau del llibre 'le' */	 
		LlibreE& operator=(const LlibreE &le);
		  
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Destructor per defecte */ 
		~LlibreE();
	  
	    //*********************************************************
		// Modificadors
		//*********************************************************
	 
	 
		// ...
		// AFEGIU ELS MÈTODES QUE CALGUIN
		// ...
	  

	    //*********************************************************
		// Consultors
		//*********************************************************
		
		/* Pre: cert */ 
		/* Post: el resultat és el títol del llibre p.i. */
		string consultar_titol() const;
	  
		/* Pre: cert */ 
		/* Post: el resultat és la data de publicació del llibre p.i. */
		Data consultar_dataPub() const;
	  
		/* Pre: cert */ 
		/* Post: el resultat és l'àrea temàtica del llibre p.i. */
		string consultar_area() const;
	  
	    /* Pre: cert */
	    /* Post: retorna un booleà que indica si la data de publicació del 
		   llibre p.i. és posterior a la del llibre 'le' (true) o no ho és (false) */
	    bool compare(const LlibreE &le) const;
		
		// ...
		// AFEGIU ELS MÈTODES QUE CALGUIN
		// ...
		
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************


		// ...
		// AFEGIU ELS MÈTODES QUE CALGUIN
		// ...

	  
	private:

	    // ...
		// DONEU UNA REPRESENTACIÓ PER LA CLASSE
		// ...
  
};
#endif

