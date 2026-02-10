#include <iostream>
#include <queue>
using namespace std;

int map[25][25];
bool visited[25][25] = { false, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int Snum = 1;

int BFS(int, int, int);

int main() {
    int N;
    cin >> N;
    int result;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                if ((result = BFS(i, j, N)) != -1)
                    pq.push(result);
            }

        }
    }

    cout << Snum - 1 << "\n";
    int size = pq.size();
    for (int i = 0;i < size;i++) {
        cout << pq.top() << "\n";
        pq.pop();
    }
}
int BFS(int i, int j, int size) {
    int count = 1;

    if (visited[i][j]) return -1;

    visited[i][j] = true;
    map[i][j] = Snum;
    queue<pair<int, int>> q;
    q.push({ i, j });

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0;d < 4;d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < size && nc >= 0 && nc < size) {
                if (map[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    map[nr][nc] = Snum; // 같은 섬 번호 부여
                    q.push({ nr, nc });
                    count++;
                }
            }
        }
    }

    Snum++;
    return count;
}