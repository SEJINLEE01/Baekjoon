#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length(); // 길이가 짧은 게 앞으로
    }
    return a < b; // 길이가 같으면 사전순(오름차순)
}

int main() {
    set<string> words;
    string word;
    int N;
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> word;
        words.insert(word);
    }

    vector<string> v(words.begin(), words.end());
    sort(v.begin(), v.end(), compare);

    for (string s : v)
        cout << s << endl;
}