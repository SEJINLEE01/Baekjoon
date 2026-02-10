#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M; // 도감수 , 문제수;
    cin >> N >> M;
    vector<string> v(N + 1); // 도감번호 -> 이름
    map<string, int> a; // 이름, 도감번호 이름 -> 도감번호
    for (int i = 0;i < N;i++) {
        string name;
        cin >> name;
        a[name] = i + 1;
        v[i + 1] = name;
    }

    for (int i = 0;i < M;i++) {
        string problem;
        cin >> problem;
        if (all_of(problem.begin(), problem.end(), ::isdigit)) {
            int x = stoi(problem);
            cout << v[x] << "\n";
        }
        else {
            cout << a[problem] << "\n";
        }
    }
}