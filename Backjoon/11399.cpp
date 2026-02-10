#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int sum = 0;
    int result = 0;
    
    for (int i = 0;i < v.size();i++) {
        sum = sum + v[i];
        result += sum;
    }
    cout << result << "\n";
}