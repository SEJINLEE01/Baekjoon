#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[50001] = { 0, };
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2;i <= N;i++) {
        int minvalue = INT_MAX;
        for (int j = 1;j * j <= i;j++) {
            int index = i - j * j;
            minvalue = min(minvalue, dp[index]);
        }
        dp[i] = minvalue + 1;
    }

    cout << dp[N] << "\n";
}