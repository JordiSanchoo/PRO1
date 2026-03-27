#include <iostream>

using namespace std;

#include "BinaryTree.hpp"


void maxOfTree2(BinaryTree<int> &t, int &max){

	if (t.getRoot() > max) max = t.getRoot();
	if (not t.getLeft().isEmpty()){
		maxOfTree2(t.getLeft(), max);
	}
	if (not t.getRight().isEmpty()){
		maxOfTree2(t.getRight(), max);
	}
}



// Pre: t és no buit
// Post: Retorna el màxim dels valors de t
int maxOfTree(BinaryTree<int> t){
	int max = t.getRoot();
	maxOfTree2(t, max);
	return max;
}
