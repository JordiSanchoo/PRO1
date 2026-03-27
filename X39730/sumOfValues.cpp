#include <iostream>

using namespace std;

struct Item {
	int value;
	Item* next;
};

// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: retorna la suma dels valors guardats a la seqüència.
int sumOfValues(Item *pitem){
	int suma = 0;
	if (pitem == NULL) suma =  0;
	else{
		suma += pitem->value + sumOfValues(pitem->next);
	}
	return suma;
}
