#include <iostream>
#include <vector>

using namespace std;

#include "BinaryTree.hpp"


int suma_nivell (BinaryTree<int> &t, int nivell){
	bool trobat = false;
	int suma = 0;
	if (t.isEmpty()){
		return;
	}
	else{
		if (compt == nivell){
			t.getLeft(t,nivell);
			t.getRight(t,nivell);
		}
	}
}

vector<int> suma_nivells(const BinaryTree<int> &t){
	
}
