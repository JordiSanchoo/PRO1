#include <iostream>

using namespace std;

struct Item {
	int value;
	Item* next;
};

// Pre:  pitem1, pitem2 apunten als primers elements de seqüències correctes d'items encadenats.
//       Els últims elements de les seqüències apunten a NULL. Els propis pitem1,pitem2 podrien
//       ser NULL, cas en el qual no hi hauria elements a les respectives seqüències.
// Post: Retorna un Item* que representa la fusió ordenada de les dues seqüències originals.
//       Les seqüències de valors originals no han canviat.
Item* merge(Item* pitem1, Item* pitem2);