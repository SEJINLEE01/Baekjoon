// 때로는 메모리가 부족하면 수의 개수배열만큼 선언하는 것을 기억할것
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int num[10001] = { 0, };

    cin >> N;
    for (int i = 0;i < N;i++)
    {
        short a;
        cin >> a;
        num[a]++;
    }

    for (int i = 1;i <= 10000;i++) {
        while (num[i]--) {
            cout << i << "\n";
        }
    }

}