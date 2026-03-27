#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

// Pre:
// Post: Retorna la mida de t


void sizeOfTree2(BinaryTree<int> &t, int &mida){
	
	if (t.isEmpty()){
		mida = 0;
	}
	else{
		mida++;
		if (not t.getLeft().isEmpty()){
			sizeOfTree2(t.getLeft(), mida);
		}
		if (not t.getRight().isEmpty()){
			sizeOfTree2(t.getRight(), mida);
		}
	}
}

int sizeOfTree(BinaryTree<int> t){
	int mida = 0;
	sizeOfTree2(t, mida);
	return mida;
}
