#include <iostream>

using namespace std;

struct Item {
	int value;
	Item* next;
};

// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: retorna la suma dels valors guardats en els items a posició parell en la seqüència.
int sumOfValuesEvenPosition2(Item *pitem, int compt){
	int suma = 0;
	if (pitem == NULL) suma = 0;
	else if (compt%2 == 0){
			suma = pitem->value + sumOfValuesEvenPosition2(pitem->next,compt+1);
		}
	else suma = sumOfValuesEvenPosition2(pitem->next,compt+1);
	return suma;
}

int sumOfValuesEvenPosition(Item *pitem){
	int compt = 0;
	int suma = sumOfValuesEvenPosition2(pitem, compt);
	return suma;
}
