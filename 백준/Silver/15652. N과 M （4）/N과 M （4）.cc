#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void DFS(int start) {
    // 숫자를 M개 다 골랐을 때 출력!
    if (ans.size() == M) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // start부터 N까지 루프
    for (int i = start; i <= N; i++) {
        ans.push_back(i);    // 숫자 넣기
        DFS(i);          // 다음 숫자는 무조건 지금보다 큰 값으로
        ans.pop_back();      // 숫자 빼기 (백트래킹)
    }
}

int main() {
    // 입출력 속도 문제 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    DFS(1);

    return 0;
}