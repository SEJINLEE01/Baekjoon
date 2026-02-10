#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> Q;
    int N;
    cin >> N;

    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        Q.push(x);
    }

    while (!Q.empty()) {
        cout << Q.top() << "\n";
        Q.pop();
    }
}