#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

void interca(queue<int>& q1, queue<int>& q2, queue<int>& q3){
	if (q1.empty() and q2.empty()) return;

	if (not q1.empty()){
		q3.push(q1.front());
		q1.pop();
	}
	if (not q2.empty()){
		q3.push(q2.front());
		q2.pop();
	}
	interca(q1,q2,q3);
}

// Pre:  Siguin [a1,a2,...,an] i [b1,b2,...,bm] els valors inicials de q1 i q2, respectivament.
// Post: En el cas n>=m, la cua retornada és [a1,b1,a2,b2,...,am,bm,a{m+1},a{m+2},...,an].
//       En el cas n<m, la cua retornada és [b1,a1,b2,a2,...,bn,an,b{n+1},b{n+2},...,bm].
queue<int> intercal(queue<int> q1, queue<int> q2){
	queue<int> res;
	if (q1.size() >= q2.size()) interca(q1,q2,res);
	else interca(q2,q1,res);
	return res;
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

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
    string s;
    while (getline(cin, s)) {
        queue<int> q1 = readQueue(s);
        getline(cin, s);
        queue<int> q2 = readQueue(s);
        getline(cin, s);
        writeQueue(intercal(q1, q2));
    }
}
