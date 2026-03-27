
#include "utilitats.hpp"
#include "camiEnArbre.hpp"

int main () 
{
    string format;
    getline(cin, format);
    BinaryTree<int> a;
    a.setInputFormat(format=="INLINEFORMAT"?BinaryTree<int>::INLINEFORMAT:BinaryTree<int>::VISUALFORMAT);
    a.setOutputFormat(BinaryTree<int>::VISUALFORMAT);

	cin >> a;
//	cout << a << endl;
	
	int k;
	while (cin >> k)
	{
		T p = camiEnArbre(a,k);
		cout << (p.first ? "SI: " : "NO: ") << k << endl << endl;
		if (p.first) escriu (p.second);
	}

	return 0;
}
