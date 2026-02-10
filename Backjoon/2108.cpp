#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 4000

int main() {
    int N;
    cin >> N;
    int Mode[SIZE * 2 + 1] = { 0, };
    vector<int> mode; // 최빈값
    vector<int> v;

    double sum = 0;

    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
        Mode[x + SIZE]++;
    }

    int mean = round(sum / v.size());
    sort(v.begin(), v.end());
    int median = v[v.size() / 2];
    int max = 0;
    for (int i = 0;i <= SIZE * 2;i++) {
        if (max <= Mode[i]) max = Mode[i];
    }

    for (int i = 0;i <= SIZE * 2;i++) {
        if (max == Mode[i])
            mode.push_back(i - SIZE);
    }

    int range = v.at(v.size() - 1) - v.at(0);

    cout << mean << "\n" << median << "\n";

    if (mode.size() == 1) cout << mode[0] << "\n";
    else cout << mode[1] << "\n";

    cout << range << "\n";
}