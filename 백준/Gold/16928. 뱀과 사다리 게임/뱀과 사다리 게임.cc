#include <iostream>
#include <queue>
using namespace std;

int dist[101];
bool visited[101];
vector<int> map;
queue<int> Q;

void BFS();

int main() {
	int N, M;
	cin >> N >> M;
	map.resize(101);
	fill(&dist[0], &dist[100], 0);
	fill(map.begin(), map.end(), -1);
	fill(&visited[0], &visited[100], false);

	for (int i = 0; i < N+M; i++) {
		int s, e;
		cin >> s >> e;
		map[s] = e;
	}
	dist[1] = 0;
	Q.push(1);
	
	BFS();
}

void BFS() {
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		if (now == 100) {
			cout << dist[100] << "\n";
			return;
		}

		for (int d = 1; d <= 6; d++) {
			int next = now + d;

			if (next <= 100) {
				if (map[next] != -1) {
					next = map[next];
				}


				if (!visited[next]) {
					dist[next] = dist[now] + 1;
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
}
