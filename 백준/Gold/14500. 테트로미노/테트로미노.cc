#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(int, int, int,int);
void check_T(int, int);

int visited[501][501];
int map[501][501];
int ans = 0;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N, M;

int main() {
	
	cin >> N >> M;
	fill(&visited[0][0], &visited[500][500], false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			DFS(j, i, map[i][j], 1);
			visited[i][j] = false;
			check_T(i, j);
		}
	}
	cout << ans << "\n";
}

void DFS(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				DFS(nx, ny, sum + map[ny][nx], cnt + 1);
				visited[ny][nx] = false;
			}
		}
	}
}

void check_T(int y, int x) {
	if (y + 1 < N && x - 1 >= 0 && x + 1 < M)  //ㅜ모양
		ans = max(ans, map[y][x] + map[y + 1][x] + map[y][x - 1] + map[y][x + 1]);
	if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < M) // ㅗ모양
		ans = max(ans, map[y][x] + map[y - 1][x] + map[y][x - 1] + map[y][x + 1]);
	if (y + 1 < N && y - 1 >= 0 && x - 1 >= 0) // ㅓ모양
		ans = max(ans, map[y][x] + map[y + 1][x] + map[y - 1][x] + map[y][x - 1]);
	if (y + 1 < N && y - 1 >= 0 && x + 1 >= 0) // ㅏ모양
		ans = max(ans, map[y][x] + map[y + 1][x] + map[y - 1][x] + map[y][x + 1]);
}