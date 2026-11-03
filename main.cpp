#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class CampusGraph {
private:
    vector<string> locations;
    vector<vector<int>> adj;

    int getIndex(const string& name) const {
        for (int i = 0; i < (int)locations.size(); i++) {
            if (locations[i] == name) return i;
        }
        return -1;
    }

public:
    CampusGraph() {
        locations = {
            "Main Gate", "Library", "Block 1", "Block 2",
            "Cafeteria", "Auditorium", "Parking", "Lab", "Hostel"
        };
        adj.resize(locations.size());

        // Undirected campus paths. Hostel is intentionally disconnected
        // so that the program can demonstrate an unreachable destination.
        addEdge("Main Gate", "Library");
        addEdge("Main Gate", "Parking");
        addEdge("Library", "Block 1");
        addEdge("Library", "Cafeteria");
        addEdge("Block 1", "Block 2");
        addEdge("Block 1", "Lab");
        addEdge("Block 2", "Auditorium");
        addEdge("Cafeteria", "Auditorium");
        addEdge("Parking", "Lab");
    }

    void addEdge(const string& a, const string& b) {
        int u = getIndex(a), v = getIndex(b);
        if (u == -1 || v == -1) return;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void showLocations() const {
        cout << "\nCampus locations:\n";
        for (int i = 0; i < (int)locations.size(); i++)
            cout << i + 1 << ". " << locations[i] << '\n';
    }

    void showGraph() const {
        cout << "\nGraph (Adjacency List):\n";
        for (int i = 0; i < (int)locations.size(); i++) {
            cout << locations[i] << " -> ";
            for (int v : adj[i]) cout << locations[v] << " | ";
            cout << '\n';
        }
    }

    void bfsRoute(const string& source, const string& destination) const {
        int s = getIndex(source), d = getIndex(destination);
        if (s == -1 || d == -1) {
            cout << "Invalid location name. Please use the displayed names.\n";
            return;
        }

        vector<bool> visited(locations.size(), false);
        vector<int> parent(locations.size(), -1);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == d) break;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if (!visited[d]) {
            cout << "No route exists between " << source << " and " << destination << ".\n";
            return;
        }

        vector<int> path;
        for (int at = d; at != -1; at = parent[at]) path.push_back(at);
        reverse(path.begin(), path.end());

        cout << "Shortest route (minimum number of edges):\n";
        for (int i = 0; i < (int)path.size(); i++) {
            cout << locations[path[i]];
            if (i + 1 < (int)path.size()) cout << " -> ";
        }
        cout << "\nNumber of edges: " << path.size() - 1 << '\n';
    }

    void dfsReachable(const string& source) const {
        int s = getIndex(source);
        if (s == -1) {
            cout << "Invalid location name. Please use the displayed names.\n";
            return;
        }

        vector<bool> visited(locations.size(), false);
        stack<int> st;
        st.push(s);
        cout << "DFS reachable locations from " << source << ":\n";

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (visited[u]) continue;
            visited[u] = true;
            cout << locations[u] << '\n';

            // Reverse iteration gives a predictable traversal order.
            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (!visited[v]) st.push(v);
            }
        }
    }

    void showDisconnectedFrom(const string& source) const {
        int s = getIndex(source);
        if (s == -1) {
            cout << "Invalid location name. Please use the displayed names.\n";
            return;
        }
        vector<bool> visited(locations.size(), false);
        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << "Locations not reachable from " << source << ":\n";
        bool found = false;
        for (int i = 0; i < (int)locations.size(); i++) {
            if (!visited[i]) {
                cout << locations[i] << '\n';
                found = true;
            }
        }
        if (!found) cout << "None. All locations are reachable.\n";
    }
};

int main() {
    CampusGraph campus;
    int choice;
    string source, destination;

    do {
        cout << "\n===== CAMPUS ROUTE FINDER =====\n";
        cout << "1. Show campus locations\n";
        cout << "2. Display graph (Adjacency List)\n";
        cout << "3. Find shortest route using BFS\n";
        cout << "4. Display reachable locations using DFS\n";
        cout << "5. Find disconnected locations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                campus.showLocations();
                break;
            case 2:
                campus.showGraph();
                break;
            case 3:
                cout << "Enter source location exactly as displayed: ";
                getline(cin, source);
                cout << "Enter destination location exactly as displayed: ";
                getline(cin, destination);
                campus.bfsRoute(source, destination);
                break;
            case 4:
                cout << "Enter starting location exactly as displayed: ";
                getline(cin, source);
                campus.dfsReachable(source);
                break;
            case 5:
                cout << "Enter starting location exactly as displayed: ";
                getline(cin, source);
                campus.showDisconnectedFrom(source);
                break;
            case 0:
                cout << "Thank you for using Campus Route Finder!\n";
                break;
            default:
                cout << "Please enter a valid menu choice.\n";
        }
    } while (choice != 0);

    return 0;
}
