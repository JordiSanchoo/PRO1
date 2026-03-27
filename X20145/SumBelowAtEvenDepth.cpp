#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

void Aux(BinaryTree<int>& t, BinaryTree<int>& sum, BinaryTree<int>& res, int compt){
	if (not t.isEmpty()){
		
		res = BinaryTree<int>(t.getRoot(), BinaryTree<int>(), BinaryTree<int>());
		sum = BinaryTree<int>(t.getRoot(), BinaryTree<int>(), BinaryTree<int>());
		
		
		if (not t.getLeft().isEmpty()){
			Aux(t.getLeft(), sum.getLeft(), res.getLeft(), compt+1);
		}
		if (not t.getRight().isEmpty()){
			Aux(t.getRight(), sum.getRight(), res.getRight(), compt+1);
		}	
		
		if (not t.getLeft().isEmpty()) sum.getRoot() += sum.getLeft().getRoot();
		if (not t.getRight().isEmpty()) sum.getRoot() += sum.getRight().getRoot();
		if (compt%2 == 0)  res.getRoot() = sum.getRoot();
	}
}
// Pre:  Sigui T el valor inicial de t.
// Post: Retorna un arbre d'enters R amb la mateixa estructura que T.
//       Per a cada posició p de T i R, si p és a profunditat senar,
//       llavors T i R tenen el mateix valor a posició p.
//       En canvi, si p es a profunditat parell, llavors el valor de R a posició
//       p és la suma de tots els valors que es troben a T a posició p o per sota.
BinaryTree<int> SumBelowAtEvenDepth(BinaryTree<int> t){
	BinaryTree<int> suma;
	BinaryTree<int> res;
	Aux (t,suma,res,0);
	return res;
}
