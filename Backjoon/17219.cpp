#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<string, string> site; // 주소,비번

    for (int i = 0;i < N;i++) {
        string str, pass;
        cin >> str >> pass;
        site[str] = pass;
    }

    for (int i = 0;i < M;i++) {
        string find;
        cin >> find;
        cout << site[find] << "\n";
    }
}