// Add or remove includes
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

// Adapt the header of the function to your case


stack<int> readStack(string line)
{
    istringstream mycin(line);
    stack<int> s;
    int x;
    while (mycin >> x)
        s.push(x);
    return s;
}

void writeStack(stack<int> &s)
{
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    bool writespace = not s.empty();
    writeStack(s);
    if (writespace) cout << " ";
    cout << x;
}

/*void gira(stack<int>&a,stack<int>&b){
	if (a.size()==1) b.push(a.top());
	else{
		b.push(a.top());
		a.pop();
		gira(a,b);
	}
}


void remove(stack<int>&s, stack <int> &r){
	
	if (s.size()==1){
		if (s.top()==0) s.pop();
		else{
			r.push(s.top());
			s.pop();
		} 
	} 
	else{
		if (not s.empty() and s.top()==1 and s.size()%2==0){
			s.pop();
		}
		else if (not s.empty() and s.top()==0 and s.size()%2==1){
			s.pop();
		}
		else{
			r.push(s.top());
			s.pop();
			
		}
		remove(s,r);
	}
}*/

void remove(stack<int> &s, int size) {
    if (size == 1){
    	if (s.top() == 0) s.pop();
    	//cout<<"Primero ";
    } 
	else{
		int top = s.top();
		s.pop();
		//cout<<"top "<<top;
		remove(s, size - 1);

		if (!((top == 0 && size % 2 == 0))){
			s.push(top);
		}
		else if (top == 1 && size % 2 == 1) {
		    s.push(top);
		}
		else {
			s.push(top);
		}
	}
    
}

stack<int> remove01(stack<int> &s) {
    stack<int> r;
    remove(s, s.size());
    return r;
}

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
    vector<stack<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readStack(s));
        
        
    for (int i = 0; i < int(v.size()); ++i) {
        stack<int> s;
        for (int j = 0; j < 100; ++j)
        	s = remove01(v[i]);
        writeStack(s); cout << endl;
    }
}

