#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> S;
    queue<char> Q;
    int count = 1;
    int B_in=0;
    for (int i = 0;i < n;i++) {
        int in;
        cin >> in;

        if(!S.empty()&&S.top()>in){
            cout<<"NO\n";
            return 0;
        }

        if(B_in<in){
            for (int j = count;j <= in;j++) {
                S.push(count++);
                Q.push('+');
            }
            S.pop();
            Q.push('-');
        }
        else if(B_in>in){
            for(int j=0;j<B_in-in;j++){
                if(S.top()!=in) {
                    S.pop();
                    Q.push('-');
                }
                else {
                    S.pop();
                    Q.push('-');
                    break;
                }
            }
        }

        B_in = in;
    }

    while(!Q.empty()){
        cout<<Q.front()<<"\n";
        Q.pop();
    }
}   