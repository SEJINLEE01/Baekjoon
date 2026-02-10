#include <iostream>
using namespace std;

int solve(int, int, int);

int main() {
    int N, I, J;
    cin >> N >> I >> J;

    cout << solve(N, I, J) << "\n";
}
int solve(int n, int i, int j) { //찾는 i,j값, 2의 n승
    if (n == 0) return n;

    int half = 1 << (n - 1);
    int ans = half * half;

    if (i < half && j < half) { //1사분면
        return solve(n - 1, i, j);
    }
    else if (i < half && j >= half) { //2사분면
        return ans + solve(n - 1, i, j-half);
    }
    else if (i >= half && j < half) { //3사분면
        return ans * 2 + solve(n - 1, i-half, j);
    }
    else if (i >= half && j >= half) { //4사분면
        return ans * 3 + solve(n - 1, i-half, j-half);
    }
}