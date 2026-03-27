#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

void ceros(stack<int>& s, int& suma){
	
	if (s.empty()){
		return;
	}
	else{
		int top = s.top();
		s.pop();
		ceros(s,suma);
		if (top == 0) s.push(suma);
		else s.push(top);
		if (s.size()%2 != 0){
			suma+= top;
		}
		
	}
}

stack<int> replace0sWithBelowSumPosEven(stack<int> s){
	int suma = 0;
	ceros(s, suma);
	return s;
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}


void writeStackRec(stack<int> &s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStackRec(s);
    if (writespace) cout << " ";
    cout << x;
}

void writeStack(stack<int> s)
{
    writeStackRec(s);
    cout << endl;
}

#endif

int main()  {
	vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
    for (int i = 0; i < int(v.size()); ++i)
        writeStack(replace0sWithBelowSumPosEven(v[i]));
}
