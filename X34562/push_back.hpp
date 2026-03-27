#include <iostream>

using namespace std;

struct Item {
	int value;
	Item* next;
};

// Pre:  pitem apunta al primer element d'una seqüència correcta no buida d'items encadenats.
//       L'últim element de la seqüència apunta a NULL.
// Post: La funció afegeix un nou item al
//       final de la seqüència amb valor el value que li passen com a paràmetre.
void push_back(Item* pitem, int value);