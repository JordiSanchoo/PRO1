#include "arbreBin.hpp"
#include<iostream>
#include<list>
using namespace std;

//Pre: t = T
//Post = Retorna el numero de fulles de T
int num_fulles(const arbreBin<int> &T){

	int fulles = 0;
	
	if (not T.es_buit()){
		if (T.fe().es_buit() and T.fd().es_buit()){
			fulles++;
		}
		int fulles_esq = num_fulles(T.fe());
		int fulles_dre = num_fulles(T.fd());
		//HI: fulles_esq i fulles_dre son el numero de fulles del fill esq i fill dre
		//FF: Alçada de l'arbre
		fulles += fulles_esq + fulles_dre;
	}
return fulles;
}

//Pre: t = T
//Post = Retorna el numero de nodes de T
int num_nodes(const arbreBin<int> &T){
	int nodes = 0;
	
	if (not T.es_buit()){
		nodes = 1;
		int nodes_esq = num_nodes(T.fe());
		int nodes_dre = num_nodes(T.fd());
		//HI: nodes_esq i nodes_dre son el numero de nodes del fill esq i fill dre
		//FF: Alçada de l'arbre
		nodes+= nodes_esq + nodes_dre;
	}
return nodes;
}

void afegir_llista (const arbreBin<int> &T, list<int> &l){
	if(not T.es_buit()){
		afegir_llista(T.fe(), l);
		l.insert(l.end(), T.arrel());
		afegir_llista(T.fd(), l);
	}
}

//Pre: La llista no esta buida
//Post: Retorna true en cas que  la llista sigui simètria i false en cas contrari
bool es_simetric(const list<int> &llista) {
    bool simetric = true;

	list<int>::const_iterator it1 = llista.begin();
	list<int>::const_iterator it2 = llista.end();
	
	if (not llista.empty()){
	it2--;
		while (it1 != it2 and simetric == true) { //Inv: it1 i it2 avancen cap al centre de la llista
		    if (*it1 != *it2) {
		        simetric = false;
		    }
		    ++it1;
		    --it2;
		}
	}
    return simetric;
}

	
	
int main(){

    arbreBin<int> T;
    cin >> T;
    cout << T << endl;

    list<int> llist; 
    afegir_llista(T,llist);

    if (es_simetric(llist)){
    	cout<<"L'arbre és simètric"<<endl;
    }
    else {
    	cout<<"L'arbre no és simètric."<<endl; 
    }
}
	

