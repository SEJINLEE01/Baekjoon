#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A;

    for (int i = 0;i < N;i++) {
        int x, y;
        cin >> x >> y;
        A.push_back(make_pair(x, y));
    }

    for (int i = 0;i < A.size();i++) {
        int grade = 0;
        for (int j = 0;j < A.size();j++) {
            if (i == j) continue;

            if (A[i].first < A[j].first && A[i].second < A[j].second)
                grade++;
        }

        cout << grade + 1 << " ";
    }
    cout << "\n";
}