#include <iostream>

using namespace std;

struct Item {
	int value;
	Item* next;
};

// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: Retorna un Item* que representa una seqüència d'items nous tals que la seva
//       corresponent seqüència de valors és una còpia de la subseqüencia de valors
//       a posició parell de la seqüència original.
//       La seqüència de valors original no ha canviat.
Item* copyEvenPos2(Item* pitem, int compt){
	
	Item *nou = new Item();
	if (pitem == nullptr) return nullptr;
	else if (compt%2 == 0){
		nou->value = pitem->value;
		nou->next = copyEvenPos2(pitem->next, compt+1);
	}
	else {
		nou = copyEvenPos2(pitem->next, compt+1);
	}
	return nou;
}

Item* copyEvenPos(Item* pitem){
	Item *nou = new Item();
	nou = copyEvenPos2(pitem, 0);
	return nou;
}
