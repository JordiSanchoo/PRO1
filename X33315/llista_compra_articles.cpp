#include <list>
#include <iostream>
#include "llista_compra_articles.hpp"
using namespace std;

//Pre: l = L, x>0
//Post: El resultat es el nombre d'articles de L que podem comprar amb x euros
void compra_articles(list<int> &l, int &x, int &suma){
    if (not l.empty()){
    	list<int>::const_iterator it = l.begin();
        int articulo_lista = *it;
        if (articulo_lista <= x && articulo_lista >= 10){
            suma++;
            x -= articulo_lista;
        }
        l.erase(it);
        compra_articles(l, x, suma);
    }
}

//Pre: l = L, x > 0
//Post: El resultat es el nombre d'articles de L que podem comprar amb x euros
int compra_articles(const list<int> &l, int x){
    int suma = 0;
    list<int> llistaux(l);
    compra_articles(llistaux, x, suma);
    return suma;    
}


