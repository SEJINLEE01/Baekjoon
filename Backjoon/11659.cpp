// 누적합 잘 생각할것.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<long long> prefix_sum(N + 1, 0);

    for (int i = 1;i <= N;i++) {
        int n;
        cin >> n;
        prefix_sum[i] = prefix_sum[i - 1] + n;
    }

    while (M--) {
        int i, j;
        cin >> i >> j;

        cout << prefix_sum[j] - prefix_sum[i - 1]<<"\n";
    }
}