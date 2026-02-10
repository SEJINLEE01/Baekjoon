#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int type[10] = { 0, };
    vector<int> v;

    for (int i = 0;i < N;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int left = 0, right = 0;
    int max_length = 0;
    int type_length = 0;
    while (right < N) {
        if (type[v[right]] == 0)
            type_length++;
        type[v[right]]++;

        while (type_length > 2) {
            type[v[left]]--;
            if (type[v[left]] == 0) type_length--;

            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length << "\n";
}