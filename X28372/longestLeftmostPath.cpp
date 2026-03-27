#include "BinaryTree.hpp"

void treeOfHeights(BinaryTree<int> &t, BinaryTree<int> &ht){
	if (not t.isEmpty()){//Cas base 1: t està buit, no cal fer res;
		if (t.getLeft().isEmpty() and t.getRight().isEmpty()){//Cas base 2: és una fulla, ht és una fulla valor 1; 
		ht = BinaryTree<int>(1,BinaryTree<int>(),BinaryTree<int>());
		}
		else{
			ht = BinaryTree<int>(0,BinaryTree<int>(),BinaryTree<int>()); //El 0 da igual el valor que le pongas
			treeOfHeights(t.getLeft(), ht.getLeft());
			treeOfHeights(t.getRight(), ht.getRight());
			if (not ht.getLeft().isEmpty() and not ht.getRight().isEmpty()){ //té 2 fills
				ht.getRoot() = 1 + max(ht.getLeft().getRoot(), ht.getRight().getRoot());
			}
			else{//només té 1 fill
				if (not ht.getLeft().isEmpty()) {//només fill esquerre
					ht.getRoot() = 1 + ht.getLeft().getRoot();
				}
				else{
					ht.getRoot() = 1 + ht.getRight().getRoot();
				}
			}
		}
	}
}

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a arrel la seva alçada.
BinaryTree<int> treeOfHeights(BinaryTree<int> t){
	BinaryTree<int> alcades;
	treeOfHeights(t, alcades);
	return alcades;
}

void longestLeftmostPath(BinaryTree<int> &t, list<int> &cami){
	
}

// Pre:
// Post: Retorna la llista d'elements que es troben a t, baixant des de l'arrel i
//       seguint el camí més llarg. En cas de varis camins màxims,
//       escull el de més a l'esquerra.
list<int> longestLeftmostPath(BinaryTree<int> t){
	list<int> cami;
	if (not t.isEmpty()){
		BinaryTree<int> ht;
	}
	
	return cami;
}
