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
void merge(Item*& pitem1, Item*& pitem2, bool& trobat, Item*& pprimer, Item*& pant){
	if (pitem1!=NULL and pitem2!=NULL){
		Item *nou=new Item();
		int valor1=pitem1->value;
		int valor2=pitem2->value;
		if (valor1<=valor2){ //primero mayor 
			nou->value=pitem1->value;
			nou->next=NULL;
			pitem1=pitem1->next;
			//cout<<"si";
		}
		else{  //segundo mayor
			nou->value=pitem2->value;
			nou->next=NULL;
			pitem2=pitem2->next;
			//cout<<"si2";
		}
		if (trobat){
			pant->next=nou;
			pant=pant->next;
		}
		if (trobat==false){ //primero
			trobat=true;
			pprimer=nou;
			pant=nou;
		}
		merge(pitem1,pitem2,trobat,pprimer,pant);
	}
	else if (pitem1!=NULL or pitem2!=NULL){
		Item *pnou=new Item();
		if (pitem1!=NULL){	
			pnou->value=pitem1->value;
			pnou->next=NULL;
			pitem1=pitem1->next;
		}
		else if (pitem2!=NULL){
			pnou->value=pitem2->value;
			pnou->next=NULL;
			pitem2=pitem2->next;
		}
		if (trobat){
			pant->next=pnou;
			pant=pant->next;
		}
		if (trobat==false){
			trobat=true;
			pprimer=pnou;
			pant=pnou;
		}
		
		merge(pitem1,pitem2,trobat,pprimer,pant);
	}
}


Item* merge(Item* pitem1, Item* pitem2){
	Item *pant=NULL;
	Item *pprimer=NULL;
	bool trobat=false;
	merge(pitem1,pitem2,trobat,pprimer,pant);
	return pprimer;
}
