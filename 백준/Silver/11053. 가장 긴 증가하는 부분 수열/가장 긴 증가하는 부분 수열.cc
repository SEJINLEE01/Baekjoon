#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> A;
	int d[1001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		A.push_back(x);
	}
	fill(&d[0], &d[1000], 1);
	int max_n = 1;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] < A[j]) {
				d[j] = max(d[j], d[i] + 1);
				if (max_n < d[j]) max_n = d[j];
			}
		}
	}

	cout << max_n;
}