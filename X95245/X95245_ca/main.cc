#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;

list<int> maxims_locals_llista(const list<int> &l){
	list<int>::const_iterator it = l.begin();
	it++;
	list<int>::const_iterator it_prev = l.begin();
	list<int>::const_iterator it_next = it;
	list<int> llista_final;
	it_next++; 

	while (it_next != l.end()){
		if (*it > *it_prev and *it > *it_next){
			llista_final.push_back(*it);
		}
		it_prev++;
		it++;
		it_next++;
	}
	return llista_final;
}

#ifndef IOLISTFUNCTIONS
#define IOLISTFUNCTIONS

void readList(const string &line, list<int> &l) {
	istringstream mycin(line);
	int x;
	while (mycin >> x) {
		l.push_back(x);
	}
}

void writeListRec(list<int>::const_iterator it, list<int>::const_iterator end) {
	if (it != end) {
    cout << ", " << *it;
    writeListRec(++it, end);
  }
}

void writeList(const list<int> &l) {
	if (l.empty()) {
		cout << "[]" << endl;
	}
	else {
		cout << '[' << *(l.begin());
		writeListRec(++l.begin(), l.end());
		cout << ']' << endl;
	}
}

#endif

int main() {
	string lin;
	while (getline(cin, lin)) {
		int i1 = lin.find('[');
		int i2 = lin.find(']', i1+1);
		string s = lin.substr(i1+1, i2-i1-1);
		list<int> la;
		readList(s, la);
		writeList(maxims_locals_llista(la));
	}	
	return 0;
}
