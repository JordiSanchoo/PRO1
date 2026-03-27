#include <queue>
#include <iostream>
#include "Punt.hpp"
using namespace std;

//Pre: Cert
//Post: S'escriuen els punts de la cua al canal de sortida
ostream& operator<<(ostream&, queue<Punt>q);

//Pre: Cert
//Post: La cua conté els valors llegits del canal d'entrada
istream& operator>>(istream&, queue<Punt> &q);

