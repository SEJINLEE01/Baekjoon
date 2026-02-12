#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	multiset<int,greater<int>> dq;
	int N;
	cin >> N;
	while (N--) {
		int c;
		cin >> c;
		for (int i = 0; i < c; i++) {
			char input;
			int num;
			cin >> input >> num;
			if (input == 'I') {
				dq.insert(num);
			}
			else if (input == 'D') {
				if (!dq.empty()) {
					if (num == -1) dq.erase(prev(dq.end()));
					else if (num == 1) dq.erase(dq.begin());
				}
			}
		}
		if (dq.empty()) cout << "EMPTY\n";
		else {
			cout << *dq.begin() << " " << *dq.rbegin() << "\n";
		}
		dq.clear();
	}
}