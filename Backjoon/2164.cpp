#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    queue<int> Q;
    cin >> N;

    for (int i = 1;i <= N;i++) {
        Q.push(i);
    }

    while (Q.size() != 1) {
        Q.pop();
        int i = Q.front();
        Q.pop();
        Q.push(i);
    }

    cout << Q.front() << endl;
}