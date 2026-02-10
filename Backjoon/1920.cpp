#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;

    vector<int> v;
    vector<int> v2;

    cin >> N;
    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cin >> M;
    for (int i = 0;i < M;i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for (int i = 0;i < M;i++) {
        if (binary_search(v.begin(), v.end(), v2.front()))
            cout << "1\n";
        else
            cout << "0\n";

        v2.erase(v2.begin());
    }
}