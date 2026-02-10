#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[1000][1000];
int visited[1000][1000];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int N, M;

void BFS(int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int index_i, index_j;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            visited[i][j] = -1;
            cin >> map[i][j];
            if (map[i][j] == 2) {
                index_i = i;
                index_j = j;
            }
            else if (map[i][j] == 0) visited[i][j] = 0;
        }
    }

    BFS(index_i, index_j);

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void BFS(int i, int j) {
    visited[i][j] = 0;
    queue<pair<int, int>> Q;
    Q.push({ i,j });

    while (!Q.empty()) {
        int now_i = Q.front().first;
        int now_j = Q.front().second;
        Q.pop();
        
        for (int d = 0;d < 4;d++) {
            int nr = now_i + dr[d];
            int nc = now_j + dc[d];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (map[nr][nc] == 1 && visited[nr][nc] == -1) {
                    visited[nr][nc] = visited[now_i][now_j] + 1;
                    Q.push({ nr,nc });
                }
            }
        }
    }
}