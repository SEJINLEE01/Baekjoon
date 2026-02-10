#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    set<string> d;
    vector<string> db;

    for (int i = 0;i < N;i++) {
        string str;
        cin >> str;
        d.insert(str);
    }

    for (int i = 0;i < M;i++) {
        string str;
        cin >> str;

        if (d.find(str) != d.end())
            db.push_back(str);
    }


    sort(db.begin(), db.end());

    cout << db.size() << "\n";
    for (int i = 0;i < db.size();i++)
        cout << db[i] << "\n";
}