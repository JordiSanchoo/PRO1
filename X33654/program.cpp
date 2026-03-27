#include "reverseTree.hpp"

typedef BinaryTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BinaryTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinaryTree<int>::INLINEFORMAT:BinaryTree<int>::VISUALFORMAT);
    string aux;
    while (cin >> t and not t.isEmpty()) {
        t = reverseTree(t);
        cout << t << endl;
  	}
}
