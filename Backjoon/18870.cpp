#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> sort_v;
    vector<int> v;

    for (int i = 0;i < N;i++) {
        int a;
        cin >> a;
        sort_v.push_back(a);
        v.push_back(a);
    }

    sort(sort_v.begin(), sort_v.end());
    sort_v.erase(unique(sort_v.begin(), sort_v.end()), sort_v.end());

    for (int i = 0;i < N;i++) {
        vector<int>::iterator it = lower_bound(sort_v.begin(), sort_v.end(), v[i]);
        cout << distance(sort_v.begin(), it) << " ";
    }
}