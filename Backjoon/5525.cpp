#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    string check = "IOI";
    for (int i = 1;i < N;i++) {
        check = "IO" + check;
    }

    string find;
    cin >> find;

    int count = 0;

    for (int i = 0;i <= M - check.size();i++) {
        if (check == find.substr(i, check.size()))
            count++;
    }

    cout << count << "\n";
}