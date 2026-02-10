#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    if (N == 0) { cout << "0\n"; return 0; }

    vector<int> v;
    float avg = 0;

    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int percent = round(N * 0.15);

    for (int i = percent;i < N - percent;i++) {
        avg += v[i];
    }

    cout << round(avg / (v.size() - percent * 2)) << "\n";
}