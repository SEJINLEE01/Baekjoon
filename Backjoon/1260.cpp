#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> node;
vector<bool> visited;

void DFS(int);
void BFS(int);

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    node.resize(N + 1);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);

    for (int i = 0;i < M;i++) {
        int s, e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
    }

    for (int i = 1; i <= N; i++) {
        sort(node[i].begin(), node[i].end());
    }
    
    visited[S] = true;
    DFS(S);
    cout << "\n";

    fill(visited.begin(), visited.end(), false);
    visited[S] = true;
    BFS(S);
}

void DFS(int i) {
    visited[i] = true;
    cout << i << " ";
    queue<int> Q;
    Q.push(i);

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();

        for (int next : node[now]) {
            if (!visited[next]) {
                DFS(next);
            }
        }
    }
}

void BFS(int i) {
    visited[i] = true;
    queue<int> Q;
    Q.push(i);

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        cout << now << " ";
        for (int next : node[now]) {
            if (!visited[next]) {
                visited[next] = true;
                Q.push(next);
            }
        }
    }
}