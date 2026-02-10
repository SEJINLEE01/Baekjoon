#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    stack<int> S;
    for (int i = 0;i < N;i++) {
        string str;
        cin >> str;
        if (str == "push") {
            int x;
            cin >> x;
            S.push(x);
        }
        else if (str == "pop") {
            if (!S.empty()) {
                cout << S.top() << "\n";
                S.pop();
            }
            else cout << "-1\n";
        }
        else if (str == "top") {
            if (!S.empty()) {
                cout << S.top() << "\n";
            }
            else cout << "-1\n";
        }
        else if (str == "size") {
            cout << S.size() << "\n";
        }
        else if (str == "empty") {
            if (S.empty()) cout << "1\n";
            else cout << "0\n";
        }
    }
}
