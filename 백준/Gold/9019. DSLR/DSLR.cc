#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int from[10000];
char how[10000];

queue<int> Q;
int A, B;
void BFS();

int main() {
	int N;
	cin >> N;
	while (N--) {
		
		cin >> A >> B;
		fill(&from[0], &from[10000], -1);
		fill(&how[0], &how[10000], 'E');
		Q.push(A);
		from[A] = 10000; //시작
		how[A] = 'A'; //시작
		BFS();

		string s = "";
		int cur = B;
		while (cur != A) { // 현재 숫자가 시작점 A가 아닐 때까지
			s += how[cur]; // 현재 숫자를 만든 명령어를 추가
			cur = from[cur]; // 부모 숫자로 이동
		}

		reverse(s.begin(), s.end());
		cout << s<<"\n";

		while (!Q.empty()) Q.pop();
	}
}
void BFS() {
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int D = (2 * now) % 10000;
		int S = now == 0 ? 9999 : now - 1;
		int L = (now%1000)*10 + (now/1000);
		int R = (now % 10)*1000 + (now / 10);
		
		if (from[D] == -1) {
			from[D] = now;
			how[D] = 'D';
			Q.push(D);
			if (D == B) return;
		}
		if (from[S] == -1) {
			from[S] = now;
			how[S] = 'S';
			Q.push(S);
			if (S == B) return;
		}
		if (from[L] == -1) {
			from[L] = now;
			how[L] = 'L';
			Q.push(L);
			if (L == B) return;
		}
		if (from[R] == -1) {
			from[R] = now;
			how[R] = 'R';
			Q.push(R);
			if (R == B) return;
		}
	}
}