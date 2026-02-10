#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N;

    cin >> N;

    while (N--) {
        string str;
        cin >> str;
        stack<char> S;

        for (int i = 0;i < str.length();i++) {
            if (str[i] == '(')
                S.push(str[i]);
            else if (str[i] == ')') {
                if (!S.empty() && S.top() == '(') S.pop();
                else S.push(str[i]);
            }
        }

        if (!S.empty()) cout << "NO\n";
        else cout << "YES\n";
    }
}