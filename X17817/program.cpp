#include <iostream>
#include <vector>

#include "suma_nivells.hpp"

using namespace std;

template <typename T>
void writeVector(const vector<T> &v) {
	if (v.size() == 0) {
		cout << "[]" << endl;
	}
	else {
		cout << '[' << v[0];
		for (auto i = 1; i < v.size(); ++i) {
			cout << ", " << v[i];
		}
		cout << ']' << endl;
	}
}

int main() {
	string format;
	getline(cin, format);
	BinaryTree<int> t;
	t.setInputFormat(format=="INLINEFORMAT"?BinaryTree<int>::INLINEFORMAT:BinaryTree<int>::VISUALFORMAT);
	t.setOutputFormat(BinaryTree<int>::VISUALFORMAT);

	while (cin >> t) {
		writeVector(suma_nivells(t));

		//~ r.setInputOutputFormat(BinaryTree<string>::VISUALFORMAT);
  }
    
	return 0;
}
