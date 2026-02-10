#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> v;
    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0;i < M;i++) {
        vector<int>::iterator low, upper;
        int find;
        cin >> find;
        low = lower_bound(v.begin(), v.end(), find);
        upper = upper_bound(v.begin(), v.end(), find);
        cout << upper - low << " ";
    }
}