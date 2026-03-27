#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "reverse.hpp"

bool readSequence(Item* (&first))
{
    string line;
	if (!getline(cin, line)) return false;
    istringstream mycin(line);
    first = NULL;
    int value;
    if (mycin >> value) {
    	first = new Item();
    	first->value = value;
        Item* current = first;
        while (mycin >> value) {
        	current->next = new Item();
            current = current->next;
            current->value = value;
        }
        current->next = NULL;
    }
    return true;
}

void writeSequence(Item* first)
{
    bool writespace = false;
    while (first != NULL) {
        if (writespace) cout << " ";
        writespace = true;
        cout << first->value;
        first = first->next;
    }
    cout << endl;
}

void deleteSequence(Item* first)
{
    while (first != NULL) {
        Item *current = first;
        first = first->next;
        delete current;
    }
}

void makeRandomSequence(Item* first)
{
    while (first != NULL) {
        first->value = rand()%1000;
        first = first->next;
    }
}

int main()
{
    Item* first;
    while (readSequence(first)) {
        Item* result = reverse(first);
        writeSequence(first);
        makeRandomSequence(first);
        deleteSequence(first);
        writeSequence(result);
        deleteSequence(result);
    }
}
