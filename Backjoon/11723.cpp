#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> S;

    for (int i = 0;i < N;i++) {
        string str;
        cin >> str;
        if (str == "add") {
            int x;
            cin >> x;
            vector<int>::iterator it = find(S.begin(), S.end(), x);
            if (it == S.end()) S.push_back(x);
        }
        else if (str == "check") {
            int x;
            cin >> x;
            vector<int>::iterator it = find(S.begin(), S.end(), x);
            if (it != S.end()) cout << "1\n";
            else cout << "0\n";
        }
        else if (str == "remove") {
            int x;
            cin >> x;
            vector<int>::iterator it = find(S.begin(), S.end(), x);
            if (it != S.end()) S.erase(it);
        }
        else if (str == "toggle") {
            int x;
            cin >> x;
            vector<int>::iterator it = find(S.begin(), S.end(), x);
            if (it != S.end()) S.erase(it);
            else S.push_back(x);
        }
        else if (str == "all") {
            S.clear();
            for (int i = 1;i <= 20;i++) S.push_back(i);
        }
        else if (str == "empty") S.clear();
    }
}