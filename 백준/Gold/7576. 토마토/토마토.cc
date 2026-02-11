#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int fresh_Tomato = 0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int N, M;

queue<pair<int, int>> Q;
int BFS();

int main() {
	fill(&map[0][0], &map[1000][1000], -1);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) Q.push({ i,j });
			else if (map[i][j] == 0) fresh_Tomato++;
		}
	}

	int result = BFS();

	if (fresh_Tomato == 0) cout << result;
	else cout << "-1\n";
}

int BFS() {
	int day = 0;

	while (!Q.empty()) {
		int q_size = Q.size();
		int progress = false;

		for (int i = 0; i < q_size; i++) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

				if (map[nx][ny] == 0) {
					fresh_Tomato--;
					map[nx][ny] = map[x][y] + 1;
					Q.push({ nx,ny });
					progress = true;
				}
			}
		}
		if (progress) day++;
	}
	return day;
}