#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    int max = 0;
    vector<int> v;
    cin >> K >> N;

    for (int i = 0;i < K;i++) {
        int length;
        cin >> length;
        v.push_back(length);
        if (max < length)
            max = length;
    }

    long long left = 1, right = max;
    long long mok;
    long long middle;
    while (left <= right) {
        middle = (left + right) / 2;
        mok = 0;
        for (int i = 0;i < K;i++) {
            mok += v[i] / middle;
        }
        if (N <= mok)
            left = middle + 1;
        else
            right = middle - 1;
    }

    cout << middle << "\n";
}