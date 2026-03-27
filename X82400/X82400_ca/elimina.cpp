#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

queue<int> filterQueue(queue<int>& inputQueue) {
    queue<int> resultQueue;
    int sum = 0;

    while (!inputQueue.empty()) {
        int current = inputQueue.front();
        inputQueue.pop();
        if (current <= sum) {
            resultQueue.push(current);
            sum += current;
        }
    }
    return resultQueue;
}

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        queue<int> inputQueue;
        int number;
        while (ss >> number) {
            inputQueue.push(number);
        }
        queue<int> resultQueue = filterQueue(inputQueue);
        bool first = true;
        while (!resultQueue.empty()) {
            if (!first) {
                cout << " ";
            }
            first = false;
            cout << resultQueue.front();
            resultQueue.pop();
        }
        cout << endl;
    }
    return 0;
}

