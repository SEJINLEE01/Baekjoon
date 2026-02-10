#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int result = 1;
    for (int i = N;i > N - K;i--)
        result *= i;

    for (int j = 1;j <= K;j++)
        result /= j;

    cout << result << endl;
}