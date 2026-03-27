// Add or remove includes
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

// Addapt the header of the function to your case
queue<int> remove01(queue<int> q) {
    queue<int> result;
    int count = 0; // contador del nombre d'elements processats
    
    while (!q.empty()) {
        int elem = q.front();
        q.pop();
        
        if ((elem == 0 && count % 2 != 0) || (elem == 1 && count % 2 == 0) || (elem != 0 && elem != 1)) {
            result.push(elem);
        }
        
        count++;
    }
    
    return result;
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

// Addapt the call to 'function_name' and the way it is called to your case.
int main()  {
    vector<queue<int> > v;
    string s;
    while (getline(cin, s))
        v.push_back(readQueue(s));
    for (int i = 0; i < int(v.size()); ++i)
        writeQueue(remove01(v[i]));
}
