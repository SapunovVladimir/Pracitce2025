#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void BFS(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    cout << "Обход BFS, начиная с узла " << startNode << ": ";

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void DFS_recursive(const vector<vector<int>>& graph, vector<bool>& visited, int currentNode) {
    visited[currentNode] = true;
    cout << currentNode << " ";

    for (int neighbor : graph[currentNode]) {
        if (!visited[neighbor]) {
            DFS_recursive(graph, visited, neighbor);
        }
    }
}

void DFS_iterative(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(startNode);
    visited[startNode] = true;

    cout << "DFS (итеративный) обход, начинающийся с узла " << startNode << ": ";

    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();
        cout << currentNode << " ";

        for (auto it = graph[currentNode].rbegin(); it != graph[currentNode].rend(); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                s.push(*it);
            }
        }
    }
    cout << endl;
}

int main() {
    setlocale(0, "ru");
    vector<vector<int>> graph = {
        {1, 2},     
        {0, 3, 4},  
        {0, 5},     
        {1},      
        {1},        
        {2}       
    };

    BFS(graph, 0);

    vector<bool> visited(graph.size(), false);
    cout << "Обход DFS (рекурсивный), начинающийся с узла 0: ";
    DFS_recursive(graph, visited, 0);
    cout << endl;

    DFS_iterative(graph, 0);
}