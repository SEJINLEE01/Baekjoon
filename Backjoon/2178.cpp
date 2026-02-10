#include <iostream>
#include <queue>
using namespace std;

int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int N, M;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
void BFS(int, int);

int main() {
    cin >> N >> M;

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }
    BFS(1, 1);
}

void BFS(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({ i,j });
    visited[i][j] = 1;

    while (!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();

        if (r == N && c == M) {
            cout << visited[r][c] << endl;
            return;
        }

        for (int d = 0;d < 4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M) {
                if (map[nr][nc] == 1 && visited[nr][nc] == 0) {
                    visited[nr][nc] = visited[r][c] + 1;
                    Q.push({ nr, nc });
                }
            }
        }
    }
}