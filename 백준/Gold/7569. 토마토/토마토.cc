#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int BFS();

bool visited[101][101][101];
int map[101][101][101];

queue<tuple<int, int, int>> Q;
int N, M, H;
int fresh_Tomato = 0;

int main() {
	
	cin >> M >> N >> H;	
	fill(&map[0][0][0], &map[100][100][100], -1);
	
	

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int num;
				cin >> num;
				map[i][j][k] = num;
				if (num == 1) Q.push({ i,j,k }); // 1,좌표저장
				else if (num == 0)fresh_Tomato++;
			}
		}
	}

	int result = BFS();

	if (fresh_Tomato != 0) cout << "-1\n";
	else cout << result;
}
int BFS() {
	int day=0;

	while (!Q.empty()) {
		int q_size = Q.size();
		bool progressed = false;
		
		for (int i = 0; i < q_size; i++) {
			int z = get<0>(Q.front());
			int y = get<1>(Q.front());
			int x = get<2>(Q.front());
			Q.pop();
			for (int d = 0; d < 6; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				int nz = z + dz[d];
				if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

				if (map[nz][ny][nx] == 0) {
					map[nz][ny][nx] = map[z][y][x] + 1;
					fresh_Tomato--;
					Q.push({ nz,ny,nx });
					progressed = true;
				}
			}
			
		}
		if (progressed) day++;
	}
	return day;
}
