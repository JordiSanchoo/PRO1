#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinaryTree<int> t){
	if (t.isEmpty()) return 0;

    std::stack<BinaryTree<int>> nodes;
    nodes.push(t);
    int sum = 0;

    while (!nodes.empty()) {
        BinaryTree<int> current = nodes.top();
        nodes.pop();

        sum += current.getvalue();

        if (!current.left().isEmpty()) {
            nodes.push(current.getLeft());
        }

        if (!current.right().isEmpty()) {
            nodes.push(current.getRight());
        }
    }

    return sum;
}
