#include <iostream>
#include <string>


using namespace std;

#include "BinaryTree.hpp"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(const BinaryTree<string> &t){

	int res = 0;
	
	if (t.getLeft().isEmpty() and t.getRight().isEmpty()){//Cas base1: t és una fulla, l'avaluació 		és el seu valor numèric
	res = mystoi(t.getRoot());
	}
	else {
		int r1 = evaluate(t.getLeft());
		int r2 = evaluate(t.getRight));
		if (t.getRoot() == "+"){
			res = r1 + r2;
		}
		else{
			if (t.getRoot() == "-"){
				res = r1 - r2;
			}
			else {
				res = r1 * r2;
			}
		}
	}
	return res;
}
