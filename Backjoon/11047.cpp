#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, money;
    cin >> N >> money;
    int count = 0;
    vector<int> cent;

    for (int i = 0;i < N;i++) {
        int x;
        cin >> x;
        cent.push_back(x);
    }

    for (int i = 0;i < N;i++) {
        count += money / cent.back();
        money = money % cent.back();
        cent.pop_back();
    }

    cout<<count<<"\n";
}