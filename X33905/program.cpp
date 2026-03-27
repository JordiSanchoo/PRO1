#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "list.hpp"

struct Container {
public:
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
    	word = c.word;
    }
    Container(const int x)
    {
        if (x != 0) {
            cerr << "Error: invalid initialization from int to string container" << endl;
            exit(1);
        }
    	word = "";
    }
	Container &operator=(const Container &c)
	{
    	word = c.word;
        return *this;
	}
	Container &operator+=(const Container &c)
	{
    	word += c.word;
        return *this;
	}
	Container &operator=(const int x)
	{
        if (x != 0) {
            cerr << "Error: invalid assignment from int to string container" << endl;
            exit(1);
        }
    	word = "";
        return *this;
	}
};

istream &operator>>(istream &is, Container &c)
{
    is >> c.word;
    return is;
}

ostream &operator<<(ostream &os, Container c)
{
    os << c.word;
    return os;
}

Container operator+(Container c1, Container c2)
{
    Container c;
    c.word = c1.word+c2.word;
    return c;
}
                           
void die(string message) {
    cout << message << endl;
    exit(1);
}

template <typename T>
void execute(List<T> l)
{
    typename List<T>::iterator it = l.begin();
    string command,s1,s2,s3;
    while (cin >> command) {
        if (command == "push_back") {
            T x;
            cin >> x;
            l.push_back(x);
        } else if (command == "push_front") {
            T x;
            cin >> x;
            l.push_front(x);
        } else if (command == "pop_back") {
            l.pop_back();
        } else if (command == "pop_front") {
            l.pop_front();            
        } else if (command == "it") {
            cin >> s1 >> s2;
            if (s1 != "=") die("Error: it "+s1);
            if (s2 == "begin") {
            	it = l.begin();
            } else if (s2 == "end") {
                it = l.end();
            } else if (s2 == "erase") {
                cin >> s3;
                if (s3 != "it") die("Error: it = erase "+s3);
                it = l.erase(it);
            } else die ("Error: it = "+s2);
        } else if (command == "it++") {
            it++;
        } else if (command == "it--") {
            it--;
        } else if (command == "++it") {
            ++it;
        } else if (command == "--it") {
            --it;
        } else if (command == "*it") {
            cin >> s1;
            if (s1 != "=") die("Error: *it "+s1);
            T x;
            cin >> x;
            *it = x;
        } else if (command == "insert") {
            cin >> s1;
            if (s1 != "it") die("Error: insert "+s1);
            T x;
            cin >> x;
			l.insert(it,x);
        } else if (command == "cout") {
            cin >> s1 >> s2;
            if (s1 != "<<") die("Error: cout "+s1);
            if (s2 == "*it") {
            	cout << *it << endl;
            } else if (s2 == "sum") {
                cout << l.sum() << endl;
            } else if (s2 == "l") {
                bool writespace = false;
                for (typename List<T>::iterator it2 = l.begin(); it2 != l.end(); it2++) {
                    if (writespace) cout << " ";
                    writespace = true;
                    if (it2 == it) cout << "(";
                    cout << *it2;
                    if (it2 == it) cout << ")";
                }
                if (it == l.end()) {
                    if (writespace) cout << " ";
                    cout << "()";
                }
                cout << endl;
                //cout << l << endl;
            } else die("Error: cout << "+s2);
        } else die("Error: wrong command "+command);
    }
}


int main()
{
   	string s;
    getline(cin, s);
    if (s == "int") {
        List<int> l;
        execute(l);
    } else if (s == "string") {
        List<Container> l;
        execute(l);
    } else die("Error: 'int' or 'string' not found in first line");
    
}


