#include <iostream>
#include <queue>
using namespace std;

char map[101][101]; // 넉넉하게 101
bool visited[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
queue <pair<int, int>> Q;
int N;

void BFS() {
    while (!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = dx[d] + x;
            int ny = dy[d] + y;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[ny][nx] && map[ny][nx] == map[y][x]) {
                    visited[ny][nx] = true;
                    Q.push({ ny, nx });
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> map[i][j];
    }

    int zone = 0, color_zone = 0;

    // 1회차 초기화 및 탐색
    for(int i=0; i<101; i++) for(int j=0; j<101; j++) visited[i][j] = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                Q.push({ i,j });
                BFS();
                zone++;
            }
        }
    }

    // 적록색약용 맵 변환
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) if (map[i][j] == 'G') map[i][j] = 'R';
    }

    // 2회차 초기화 및 탐색
    for(int i=0; i<101; i++) for(int j=0; j<101; j++) visited[i][j] = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                Q.push({ i,j });
                BFS();
                color_zone++;
            }
        }
    }

    cout << zone << " " << color_zone;
    return 0;
}