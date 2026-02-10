#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int node[501][501];
    int path[501];

    fill(&node[0][0], &node[500][500], 10000);

    for (int i = 0;i < M;i++) {
        int s, e;
        cin >> s >> e;
        node[s][e] = 1;
        node[e][s] = 1;
    }


    for (int k = 1;k <= N;k++) {
        for (int i = 1;i <= N;i++) {
            for (int j = 1;j <= N;j++) {
                if (i == j)
                    node[i][j] = 0;

                if (node[i][k] + node[k][j] < node[i][j])
                    node[i][j] = node[i][k] + node[k][j];
            }
        }

    }

    int result_person = 1;
    int min = 10000;
    for (int i = 1;i <= N;i++) {
        int current_sum = 0;
        for (int j = 1;j <= N;j++) {
            current_sum += node[i][j];
        }

        if (current_sum < min) {
            min = current_sum;
            result_person = i;
        }
    }
    cout << result_person << "\n";
}