#include <stack>
#include <iostream>
#include "Punt.hpp"
using namespace std;


//Pre: cert
//Post: s'escriuen els punts de la pila al canal estàndard de sortida
ostream& operator<<(ostream&, stack<Punt>p);

//Pre: cert
//Post: la pila passa a tenir els punts llegits del canal estàndard d'entrada
istream& operator>>(istream&, stack<Punt>&p);
