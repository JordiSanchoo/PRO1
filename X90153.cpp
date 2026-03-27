#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

stack<int> uniq(stack<int> s);

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
	cout <<"La teva pila es: "<< endl;
    writeStackRec(s);
    cout<< endl;
}

#endif

//Pre: s està ordenat en ordre ascendent i s no és buida
//Post: r conté els elements de s sense repeticions
void comprova(stack<int> &s, stack<int> &r){

	if (s.size() == 1){
		r.push(s.top());
	}
	else{
		int top = s.top();
		s.pop();
		comprova(s,r);
		//HI: r conté els elements de s sense repeticions
		//FF: mida de s
		
		if (top != r.top()){
			r.push(top);
		}
	}
}


queue<int> uniq(queue<int> s){

	queue<int>r;
	while (not s.empty()){
		int x = s.front();
		s.pop();
		
		if (s.empty() or (not s.empty() and x != s.front())) r.push(x);
	}
	return r;
	 
}

int main(){
    string l;
    while (getline(cin, l))
    {
        stack<int> s = readStack(l);
        getline(cin, l);
        writeStack(uniq(s));
    }
    
    return 0;
}


