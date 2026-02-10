//15829번
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long M = 1234567891;
    long long r = 1;
    int L;
    string A;

    cin >> L;
    cin >> A;
    long long sum = 0;

    for (int i = 0;i < L;i++) {
        sum = (long long)(sum + (A[i] - 'a' + 1) * r) % M;
        r = (r * 31) % M;
    }

    cout << sum << endl;
}

