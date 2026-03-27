#include "evaluate.hpp"
#include "utils.hpp"

int main()
{
    string format;
    getline(cin, format);
    BinaryTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinaryTree<string>::INLINEFORMAT:BinaryTree<string>::VISUALFORMAT);
    string aux;
    while (cin >> t and not t.isEmpty()) {
    	cout << evaluate(t) << endl;
  	}
}
