#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int stair[301];
    int score[301];

    for (int i = 1;i <= N;i++)
        cin >> stair[i];


    score[1] = stair[1];

    if (N >= 2) score[2] = stair[1] + stair[2];
    if (N >= 3) score[3] = max(stair[3] + stair[1], stair[2] + stair[3]);

    for (int i = 4;i <= N;i++) {
        score[i] = max(score[i - 2] + stair[i], score[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << score[N] << "\n";
}