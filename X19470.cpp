#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;


void unico(stack<int>& s, stack<int> aux){
	
	if (s.size() == 1){
		aux.push(s.top());
	}
	else{
		int top = s.top();
		s.pop();
		uncio(s);
		
		if (top != aux.top()){
			s.push(top);
		}
	}
}

stack<int> uniq(stack<int> s){
	stack<int> aux;
	if (not s.empty()){
		unico(s,aux);
	}
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


stack<int> uniq(stack<int> s){

	stack<int>r;
	if (not s.empty()){
		comprova(s,r);
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


