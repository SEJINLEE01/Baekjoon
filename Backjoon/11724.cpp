#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> node;
int visited[1001] = { false, };
int Edge = 0;

void BFS(int);

int main() {
    int N, M;
    cin >> N >> M;
    node.resize(N + 1);

    for (int i = 0;i < M;i++) {
        int s, e;
        cin >> s >> e;
        node[s].push_back(e);
        node[e].push_back(s);
    }

    for (int i = 1;i <= N;i++) BFS(i);

    cout << Edge << "\n";
}
void BFS(int n) {
    if (visited[n])
        return;

    visited[n] = true;
    queue<int> Q;
    Q.push(n);

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int next : node[now]) {
            if (!visited[next]) {
                visited[next] = true;
                Q.push(next);
            }
        }
    }
    Edge++;
}