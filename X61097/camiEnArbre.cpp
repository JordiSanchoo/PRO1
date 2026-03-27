#include <iostream>
#include <stack>

using namespace std;

#include "BinaryTree.hpp"

typedef pair<bool,stack<int>> T;

T camiEnArbre (BinaryTree<int> t, int n){

	T parella;
	if (t.isEmpty()){
		parella.first = false;
	}
	else if(t.getRoot() == n){
		parella.first = true;
		parella.second.push(n);
		return parella;
	}
	else{
		parella = camiEnArbre(t.getLeft(), n);
		parella.second.push(t.getRoot());		
		if (parella.first == false){
			parella = camiEnArbre(t.getRight(), n);
			parella.second.push(t.getRoot());
		}
	}
	return parella;
}

/// Donat un arbre (sense repetitions) i un int k,
/// torna true (false altrament) si hi ha un camí de
/// l'arrel a k a dins de l'arbre, i en cas que hi sigui,
/// també torna, en una pila, el camí de l'arrel a k:
/// l'arrel es trobarà al cim de la pila, i k al fons de la pila.
