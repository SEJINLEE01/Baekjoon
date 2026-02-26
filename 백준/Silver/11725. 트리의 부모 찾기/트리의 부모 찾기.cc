#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int head[100001];
bool visited[100001];
vector<vector<int>> T;

int main() {
	int N;
	cin >> N;
	
	
	T.resize(N + 1);
	fill(&head[0], &head[100000], -1);
	head[1] = 0;

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		T[s].push_back(e);
		T[e].push_back(s);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i : T[now]) {
			if (!visited[i]) {
				visited[i] = true;
				head[i] = now;
				q.push(i);
			}
		}
	}

	for (int i = 2; i <= N; i++) cout << head[i] << "\n";
}