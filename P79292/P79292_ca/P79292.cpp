#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

struct Client {
    string name;
    string rank;
    int arrival_index;
};

struct Compare {
    bool operator()(const Client& a, const Client& b) const {
        if (a.rank != b.rank) {
            return rankPriority(a.rank) < rankPriority(b.rank);
        }
        return a.arrival_index > b.arrival_index;
    }
};

int rankPriority(const string& rank) {
    if (rank == "soldat") return 1;
    if (rank == "sergent") return 2;
    if (rank == "capita") return 3;
    if (rank == "coronel") return 4;
    return 0;
}

int main() {
    int num_queues;
    cin >> num_queues;
    vector<priority_queue<Client, vector<Client>, Compare> > queues(num_queues);
    int arrival_index = 0;

    string line;
    getline(cin, line);  // Consume newline character after num_queues

    for (int i = 0; i < num_queues; i++) {
        getline(cin, line);
        istringstream iss(line);
        string name, rank;
        while (iss >> name >> rank) {
            queues[i].push({name, rank, arrival_index++});
        }
    }

    getline(cin, line);  // Consume the blank line

    queue<string> output;

    while (getline(cin, line)) {
        istringstream iss(line);
        string command;
        iss >> command;
        if (command == "SURT") {
            int queue_num;
            iss >> queue_num;
            if (queue_num > 0 && queue_num <= num_queues && !queues[queue_num - 1].empty()) {
                output.push(queues[queue_num - 1].top().name);
                queues[queue_num - 1].pop();
            }
        } else if (command == "ENTRA") {
            string name, rank;
            int queue_num;
            iss >> name >> rank >> queue_num;
            if (queue_num > 0 && queue_num <= num_queues) {
                queues[queue_num - 1].push({name, rank, arrival_index++});
            }
        }
    }

    cout << "SORTIDES" << endl;
    cout << "--------" << endl;

    while (!output.empty()) {
        cout << output.front() << endl;
        output.pop();
    }

    cout << endl;

    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;

    for (int i = 0; i < num_queues; i++) {
        cout << "cua " << i + 1 << ":";
        priority_queue<Client, vector<Client>, Compare> temp_queue = queues[i];
        vector<Client> clients;
        while (!temp_queue.empty()) {
            clients.push_back(temp_queue.top());
            temp_queue.pop();
        }
        sort(clients.begin(), clients.end(), [](const Client& a, const Client& b) {
            return a.arrival_index < b.arrival_index;
        });
        for (const Client& client : clients) {
            cout << " " << client.name;
        }
        cout << endl;
    }

    return 0;
}

