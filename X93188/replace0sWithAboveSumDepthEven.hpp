#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
//       Els valors guardats a T son majors o iguals a 0.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       A més a més, per a cada posició p de T', si T té un valor x diferent de 0 a posició p,
//       llavors T' també té x a posició p.
//       En canvi, si T té valor 0 a posició p, llavors el valor de T' a posició p és
//       la suma de tots els valors de T a profunditat parell per sobre de p.
BinaryTree<int> replace0sWithAboveSumDepthEven(BinaryTree<int> t);
