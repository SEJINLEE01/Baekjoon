#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> edge;

struct compare {
    bool operator()(const edge& a, const edge& b) {
        if (a.second == b.second) return a.first > b.first; //오름차순
        return a.second > b.second;
    }
};

int main() {
    priority_queue<edge, vector<edge>, compare> pq;
    int N;
    cin >> N;
    for (int i = 0;i < N;i++) {
        int start, end;
        cin >> start >> end;
        pq.push({ start,end });
    }

    int s = 0, e = 0, count = 0;

    while (!pq.empty()) {
        if (pq.top().first >= e) {
            s = pq.top().first;
            e = pq.top().second;
            pq.pop();
            count++;
        }
        else pq.pop();
    }

    cout << count << "\n";
}