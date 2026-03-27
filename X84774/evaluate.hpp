#include <iostream>
#include <string>

using namespace std;

#include "BinaryTree.hpp"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(const BinaryTree<string> &t);