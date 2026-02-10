#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, count = 0;

    cin >> N;
    int devil = 0;
    while (true) {
        devil++;
        if (to_string(devil).find("666") != string::npos)
            count++;

        if (N == count) {
            cout << devil << endl;
            break;
        }
    }
}