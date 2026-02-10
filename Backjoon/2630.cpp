#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[128][128];

int blue = 0, white = 0;
int N;

void solve(int, int, int);

int main() {
    cin >> N;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> map[i][j];
        }
    }
    solve(0, 0, N);
    cout << white << "\n" << blue << "\n";
}

void solve(int i, int j, int size) {
    int now_color = map[i][j];

    for (int r = i;r < size + i;r++) {
        for (int c = j;c < size + j;c++) {
            if (now_color != map[r][c]) {
                solve(i, j, size / 2);
                solve(i, j + size / 2, size / 2);
                solve(i + size / 2, j, size / 2);
                solve(i + size / 2, j + size / 2, size / 2);
                return;
            }
        }
    }

    if (now_color == 1) blue++;
    else if (now_color == 0) white++;
}
