#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const tuple<int, string, int>& a, const tuple<int, string, int>& b) {
    if (get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b); //나이 오름차순
    return get<2>(a) < get<2>(b); // 나이가 같으면 들어온순서
}

int main() {
    int N;
    cin >> N;
    vector<tuple<int, string, int>> A;

    for (int i = 0;i < N;i++) {
        int age;
        string name;
        cin >> age >> name;
        A.push_back(make_tuple(age, name, i));
    }

    sort(A.begin(), A.end(), compare);

    for (tuple<int, string, int> temp : A) {
        cout << get<0>(temp) << " " << get<1>(temp) << "\n";
    }
}