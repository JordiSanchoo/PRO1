#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

queue<int> replace0sWithPreviousSumPosEven(queue<int> q){
	queue<int> copia;
	int index = 0;
	int suma = 0;
	while (not q.empty()){
		if (index%2 == 0){
			suma+= q.front();
		}
		if (q.front() == 0){
			q.front() = suma;
		}
		copia.push(q.front());
		q.pop();
		index++;
	}
	return copia;
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
	vector<queue<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readQueue(s));
    for (int i = 0; i < int(v.size()); ++i)
        writeQueue(replace0sWithPreviousSumPosEven(v[i]));
}
