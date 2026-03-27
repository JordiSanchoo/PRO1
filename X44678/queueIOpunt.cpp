#include "queueIOpunt.hpp"

//Pre: Cert
//Post: S'escriuen els punts de la cua al canal de sortida
ostream& operator<<(ostream& os, queue<Punt> q)

{   
    os << "<";
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        os << q.front() << "|";
        q.pop();
    }
    os << "<" << endl;
    return os;
}

//Pre: Cert
//Post: La cua conté els valors llegits del canal d'entrada
istream& operator>>(istream &is, queue<Punt> &q)

{
    int n;
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        Punt e;
        is >> e;
        q.push(e);
    }
    return is;
}
