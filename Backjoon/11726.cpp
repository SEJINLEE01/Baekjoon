#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4;i <= N;i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    cout << dp[N] << "\n";

}