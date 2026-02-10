#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    bool visited[100001];
    fill(visited, visited + 100001, false);

    queue<pair<int, int>> Q;
    Q.push({ N,0 }); //위치, 타임
    int min = 1000000; //최소타임 저장


    while (!Q.empty()) {
        int now = Q.front().first;
        int time = Q.front().second;
        Q.pop();

        if (now == M) {
            cout << time << endl;
            return 0; // BFS는 먼저 도착하는 게 무조건 최단시간입니다.
        }

        int next_points[] = { now - 1, now + 1, now * 2 };

        for (int next : next_points) {
            if (next >= 0 && next <= 100000 && !visited[next]) {
                visited[next] = true;
                Q.push({ next, time + 1 });
            }
        }
    }

}
