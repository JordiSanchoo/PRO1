#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

int sumOfTree2(BinaryTree<int> &t){
	int suma=0;
	if (t.isEmpty()){
		suma=0;
	}
	else{
		suma+=t.getRoot();
		suma+=sumOfTree2(t.getLeft());
		suma+=sumOfTree2(t.getRight());
	}
	return suma;
}
// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinaryTree<int> t){
	return sumOfTree2(t);
}
