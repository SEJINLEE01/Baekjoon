#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    int N, M;

    for (int i = 0;i < T;i++) {
        cin >> N >> M;
        queue<pair<int, int>> Q; // 인덱스, 우선순위
        priority_queue<int> pq; //우선수위로 나열하는 우선순위 큐

        for (int j = 0;j < N;j++) {
            int V;
            cin >> V;
            Q.push(make_pair(j, V));
            pq.push(V);
        }
        int count = 0;

        while (!Q.empty()) {
            int index = Q.front().first;
            int value = Q.front().second;
            Q.pop();
            if (pq.top() == value) {
                pq.pop();
                count++;
                if (M == index) {
                    cout << count << "\n";
                    break;
                }
            }
            else Q.push({ index, value });
        }
    }
}