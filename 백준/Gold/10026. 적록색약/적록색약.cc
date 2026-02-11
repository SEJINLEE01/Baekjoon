#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
bool visited[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
queue <pair<int, int>> Q;
int N;
int zone = 0;
int color_zone = 0;
void BFS();

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	fill(&visited[0][0], &visited[100][100], false);
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) {
				visited[i][j] = true;
				Q.push({ i,j });
				BFS();
				zone++;
			}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}

	fill(&visited[0][0], &visited[100][100], false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) {
				visited[i][j] = true;
				Q.push({ i,j });
				BFS();
				color_zone++;
			}
	}
	cout << zone << " "<<color_zone;
}

void BFS() {
	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = dx[d] + x;
			int ny = dy[d] + y;
			if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[ny][nx] && map[ny][nx] == map[y][x]) {
					visited[ny][nx] = true; // 방문 처리
					Q.push({ ny, nx });     // 다음 탐색을 위해 큐에 삽입
				}
			}
		}
	}
}