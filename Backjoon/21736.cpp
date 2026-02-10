#include <iostream>
#include <vector>
using namespace std;

int N, M;
int result = 0;
char map[600][600];
bool visited[600][600] = { false, };
void DFS(int, int);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int index_i, index_j;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            char c;
            cin >> c;
            map[i][j] = c;
            if (c == 'I') {
                index_i = i;
                index_j = j;
            }
        }
    }


    DFS(index_i, index_j);

    if (result == 0)
        cout << "TT\n";
    else
        cout << result << "\n";
}

void DFS(int r, int c) {
    if ((r < 0 || r >= N) || (c < 0 || c >= M))
        return;

    if (visited[r][c]) return;

    visited[r][c] = true;



    if (map[r][c] == 'P') result++;
    else if (map[r][c] == 'X') return;

    DFS(r + 1, c);
    DFS(r, c - 1);
    DFS(r, c + 1);
    DFS(r - 1, c);


}