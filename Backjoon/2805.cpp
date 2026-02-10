#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<int> v;
    int H = 0;
    for (int i = 0;i < N;i++) {
        long long c;
        cin >> c;
        v.push_back(c);
        if (c > H) H = c;
    }

    long long low = 0;
    long long high = H;
    long long result;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0;i < N;i++) {
            if (v[i] > mid)
                sum += v[i] - mid;

        }
        if (sum >= M) {
            result = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << result << "\n";
}