#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

void Aux(BinaryTree<int>& t, BinaryTree<int>& res, int& compt, int& suma){
	
	if (not t.isEmpty()){
		if (t.getRoot() == 0) res = BinaryTree<int>(suma, BinaryTree<int>(), BinaryTree<int>());
		else res = BinaryTree<int>(t.getRoot(), BinaryTree<int>(), BinaryTree<int>());
		
		if (compt%2 == 0) suma += t.getRoot();
		
		if (not t.getLeft().isEmpty()){
			compt++;
			Aux(t.getLeft(), res.getLeft(), compt, suma);
			compt--;
		}
		if (not t.getRight().isEmpty()){
			compt++;
			Aux(t.getRight(), res.getRight(), compt, suma);
			compt--;
		}
		if (compt%2 == 0) suma -= t.getRoot();
	}
}

BinaryTree<int> replace0sWithAboveSumDepthEven(BinaryTree<int> t){
	BinaryTree<int> res;
	int compt = 0;
	int suma = 0;
	Aux(t,res,compt,suma);
	return res;
}
