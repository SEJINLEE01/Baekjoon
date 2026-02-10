#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str = " ";

    while (true) {
        getline(cin, str);
        stack<char> S;

        if (str == ".") break;

        for (int i = 0;i < str.length();i++) {
            if (str[i] == '.')
                break;

            if (str[i] == '(' || str[i] == '[') // 왼쪽괄호 처리
                S.push(str[i]);
            else if (str[i] == ')') { //오른쪽 소괄호
                if (!S.empty() && S.top() == '(') S.pop();
                else  S.push(str[i]);
            }
            else if (str[i] == ']') { //오른쪽 대괄호
                if (!S.empty() && S.top() == '[') S.pop();
                else S.push(str[i]);
            }
        }

        if (S.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}