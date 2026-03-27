#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

void elimina(stack<int>& s, int& max_act, bool& trobat, int& compt) {
	int size = s.size();
    if (size == compt) {
        max_act = s.top();
    }
	else{
		int top = s.top();
    	s.pop();
    	elimina(s, max_act,trobat,compt);

		if (top >= max_act){
			s.push(top);
		    trobat = true;
		}
	}
}

// Pre: s és una pila d'enters positius.
// Post: Retorna la pila resultant d'esborrar en s tots els elements per als quals podem
// trobar un altre element per sota seu que és estríctament més gran que ells.
void removeThoseWithBiggerUnder2(stack<int>& s, int& compt) {
	
	bool trobat = false;
	int max_act = 0;
	elimina(s,max_act,trobat,compt);
    if (not trobat) return;
	else{
		compt++;
		removeThoseWithBiggerUnder2(s,compt);
	}
}
stack<int> removeThoseWithBiggerUnder(stack<int> s) {
	int compt = 1;
	if (s.size() > 1){
		removeThoseWithBiggerUnder2(s,compt);
	}
	
	return s;
}



#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS
static stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

static void writeStack(stack<int> &s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStack(s);
    if (writespace) cout << " ";
    cout << x;
}
#endif

int main()  {
  
    vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 50; ++j)
        	s = removeThoseWithBiggerUnder(v[i]);
        writeStack(s); cout << endl;
    }
}
