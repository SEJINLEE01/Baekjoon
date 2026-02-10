#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int K;
    cin >> K;
    int sum = 0;
    stack<int> S;

    while (K--) {
        int c;
        cin >> c;
        if (c == 0)
            S.pop();
        else
            S.push(c);
    }

    while (!S.empty()) {
        sum += S.top();
        S.pop();
    }

    cout << sum << "\n";
}