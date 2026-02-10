#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int map[500][500];

int main() {
    int N, M, B;
    cin >> N >> M >> B;
    int min_h = 256, max_h = 0;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            int a;
            cin >> a;
            map[i][j] = a;
            if (a > max_h) max_h = a;
            if (a < min_h) min_h = a;
        }
    }

    int min_time = INT_MAX;
    int best_height = 0;

    for (int h = min_h;h <= max_h;h++) {
        int time = 0;
        int inventory = B;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int diff = map[i][j] - h;
                if (diff > 0) { // 깎기 (2초)
                    time += (diff * 2);
                    inventory += diff;
                }
                else if (diff < 0) { // 쌓기 (1초)
                    time += (diff * -1);
                    inventory -= (diff * -1);
                }
            }
        }

        // 인벤토리가 음수가 아니면 유효한 경우
        if (inventory >= 0) {
            if (time <= min_time) { // 시간이 같으면 더 높은 높이를 선택해야 하므로 <= 사용
                min_time = time;
                best_height = h;
            }
        }
    }

    cout << min_time << " " << best_height << "\n";
}