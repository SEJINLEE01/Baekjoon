#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<string, int> m;
        int count = 1;
        for (int i = 0;i < n;i++) {
            string name;
            string type;
            cin >> name >> type;
            m[type]++;
        }

        for (pair<string, int> r : m)
            count = count * (r.second + 1);

        count--;
        cout << count << "\n";
    }
}