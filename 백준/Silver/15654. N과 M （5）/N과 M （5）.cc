#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> ans;
vector<int> input_nums;
int visited[9]; // N은 최대 8

void DFS15654() {
    // 1. 종료 조건: M개를 다 골랐으면 출력
    if (ans.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 2. 반복문: 정렬된 입력 숫자들을 하나씩 검사
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { // 아직 사용하지 않은 숫자라면
            visited[i] = true;      // 사용 표시
            ans.push_back(input_nums[i]); // 바구니에 담기

            DFS15654();                  // 다음 숫자 고르러 가기

            ans.pop_back();         // 돌아오면 바구니에서 빼기
            visited[i] = false;     // 사용 표시 해제 (백트래킹)
        }
    }
}

int main() {
    // 입출력 속도 문제 방지
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        input_nums.push_back(x);
    }

    sort(input_nums.begin(), input_nums.end());

    DFS15654();
    return 0;
}