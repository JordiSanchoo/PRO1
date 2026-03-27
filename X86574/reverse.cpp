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
//       corresponent seqüència de valors és el revessat de seqüència de valors original.
//       La seqüència original no ha canviat.
void reverse(Item *pitem, Item*& pprimer, Item*& pant, bool& trobat){
	
	if (pitem != nullptr){
		
		int valor = pitem->value;
		reverse(pitem->next,pprimer,pant,trobat);
		Item *nou = new Item();
		nou->value = valor;
		nou->next = nullptr;
		if (trobat){
			pant->next = nou;
			pant = nou;
		}
		else{
			trobat = true;
			pprimer = nou;
			pant = nou;
		}
		
	}
		
}

Item* reverse(Item* pitem){
	Item *pprimer = nullptr;
	Item *pant = nullptr;
	bool trobat = false;
	reverse(pitem,pprimer,pant,trobat);
	return pprimer;
}
