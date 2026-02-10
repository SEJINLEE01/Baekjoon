#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;

    count += N / 5;
    count += N / 25;
    count += N / 125;
    cout << count << endl;
}