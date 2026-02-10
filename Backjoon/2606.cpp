#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> node;
    vector<bool> visited(N + 1, false);
    node.resize(N + 1);

    for (int i = 0;i < M;i++) {
        int s, e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
    }

    queue<int> Q;
    Q.push(1);
    visited[1] = true;
    int count = 0;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int next : node[now]) {
            if (!visited[next]) {
                Q.push(next);
                visited[next] = true;
                count++;
            }
        }
    }

    cout << count << "\n";
}