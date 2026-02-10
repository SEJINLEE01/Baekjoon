#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A;

    for (int i = 0;i < N;i++) {
        int x, y;
        cin >> x >> y;
        A.push_back(make_pair(x, y));
    }

    sort(A.begin(), A.end(), compare);

    for (pair<int, int> p : A) {
        cout << p.first << " " << p.second << "\n";
    }
}