// 유클리드호제 잘기억해놓을것
#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int a, b;
    cin >> a >> b;
    int result = gcd(a, b);
    int result2 = a * b / result;

    cout << result << endl;
    cout << result2 << endl;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
