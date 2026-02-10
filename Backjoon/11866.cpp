#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    queue<int> Q;

    for (int i = 1;i <= N;i++)
        Q.push(i);

    cout << "<";
    int count = 0;
    while (!Q.empty()) {
        count++;
        if (count % K == 0) {
            if(Q.size()>1){
                cout << Q.front() << ", ";
                Q.pop();
            }
            else{
                cout << Q.front();
                Q.pop();
            }
        }
        else {
            int x = Q.front();
            Q.pop(); Q.push(x);
        }
    }

    cout << ">\n";
}