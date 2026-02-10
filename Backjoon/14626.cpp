#include <iostream>
#include <string>
using namespace std;
#define MOD 10

int main() {
    string ISBN;
    cin >> ISBN;
    int m = 0;
    int x = ISBN[ISBN.length() - 1] - '0';
    int start;

    for (int i = 0;i < ISBN.length() - 1;i++) {
        if (ISBN[i] == '*') {
            start = i;
            continue;
        }

        if (i % 2 == 0)
            m = (m + (ISBN[i] - '0')) % MOD;
        else
            m = (m + (ISBN[i] - '0') * 3) % MOD;
    }

    for (int i = 0;i < 10;i++) {
        int check;
        if (start % 2 == 0)
            check = 10 - (m + i) % MOD;
        else
            check = 10 - (m + i * 3) % MOD;

        if (check == 10)
            check = 0;

        if (x == check) {
            cout << i << endl;
            break;
        }
    }
}