#include "reverseTree.hpp"

// Pre: t = T i rt = RT i RT està buit
//Post: rt té el revessat de t.
void reverseTree(BinaryTree<int> &t, BinaryTree<int> &rt){

	if (not t.isEmpty()){//Cas base1: t està buit, no cal fer res
		if (t.getLeft().isEmpty() and t.getRight().isEmpty()){//Cas base2: t és una fulla, rt serà 			una fulla amb el mateix valor que l'arrel de t
			rt = BinaryTree<int> (t.getRoot(), BinaryTree<int>(), BinaryTree<int>());
		}
		else {//Cas recursiu: t té almenys un fill
			rt = BinaryTree<int> (t.getRoot(), BinaryTree<int>(), BinaryTree<int>());
			reverseTree(t.getRight(), rt.getLeft());
			//Hipotesis inducció: el fill esquerre de rt té el revessat del fill dret de t
			//Funció fita: La mida de t
			reverseTree(t.getLeft(), rt.getRight());
			//Hipotesis inducció: el fill dret de rt té el revessat del fill esquerre de t
			//Funció fita: La mida de t
			rt = BinaryTree<int>(t.getRoot(), rt.getLeft(), rt.getRight());
		}
	}
}

// Pre:
//Post: retorna el revessat de t.
BinaryTree<int> reverseTree(BinaryTree<int> t){

	BinaryTree<int> rt;
	reverseTree (t, rt);
	return rt;
}
