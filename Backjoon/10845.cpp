#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> Q;
    for (int i = 0;i < N;i++) {
        string str;
        cin >> str;

        if (str == "push") {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if (str == "pop") {
            if (!Q.empty()) {
                cout << Q.front() << "\n";
                Q.pop();
            }
            else cout << "-1\n";
        }
        else if (str == "size") {
            cout << Q.size() << "\n";
        }
        else if (str == "empty") {
            if (Q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (str == "front") {
            if (!Q.empty()) cout << Q.front() << "\n";
            else cout << "-1\n";
        }
        else if (str == "back") {
            if (!Q.empty()) cout << Q.back() << "\n";
            else cout << "-1\n";
        }
    }
}