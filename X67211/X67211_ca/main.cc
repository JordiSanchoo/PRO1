// Add or remove includes
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

struct Test {
    queue<int> q1,q2;
};

// Pre: Rep dues cues d'enters positius q1 i q2.
// Post: Retorna una cua, on al seu front hi ha el màxim dels fronts de q1,q2, després,
// en segon lloc el màxim dels segons llocs de q1,q2, i així successivament.
// Quan una de les dues cues no té valors definits en alguna posició, la cua resultant hi té
// el valor de l'altra cua en aquella posició.
queue<int> maximumQueue(queue<int> q1,queue<int> q2){
	queue<int>aux;
	while (not q1.empty() and not q2.empty()){
		if (q1.front() >= q2.front()){
			aux.push(q1.front());
			q1.pop(); q2.pop();
		} 
		else {
			aux.push(q2.front());
			q1.pop(); q2.pop();
		}
	}
	while (not q1.empty()){
		aux.push(q1.front());
		q1.pop();
	}
	while (not q2.empty()){
		aux.push(q2.front());
		q2.pop();
	}
	return aux;
}

queue<int> readQueue(string s)
{
    istringstream mycin(s);
    queue<int> q;
    int x;
    while (mycin >> x)
        q.push(x);
    return q;
}

void writeQueue(queue<int> q)
{
    bool writespace = false;
    while (not q.empty()) {
        if (writespace) cout << " ";
        cout << q.front();
        q.pop();
        writespace = true;
    }
    cout << endl;
}
#endif

int main()  {
	vector<Test> v;
    string s;
    while (getline(cin, s)) {
        Test t;
        t.q1=readQueue(s);
        getline(cin, s);
        t.q2=readQueue(s);
        v.push_back(t);
    }
    for (int i = 0; i < int(v.size()); ++i) {
        writeQueue(maximumQueue(v[i].q1,v[i].q2));
    }
}
