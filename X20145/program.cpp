#include "SumBelowAtEvenDepth.hpp"

int main()
{
  string s;
  while (cin >> s) {
    BinaryTree<int> t;
    readStringTree(s, t);
    BinaryTree<int> r = SumBelowAtEvenDepth(t);
    writeStringTree(cout, r);
    cout << endl;
  }
}
