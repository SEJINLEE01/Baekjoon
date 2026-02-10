#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct compare {
    bool operator()(const int a, const int b) {
        if (abs(a) == abs(b)) return a > b; // 절댓값이 같으면 작은 게 위로 (오름차순 기준)
        return abs(a) > abs(b);             // 절댓값이 작은 게 위로 (최소 힙 형태)
    }
};

int main(){
    priority_queue<int,vector<int>,compare> pq;

    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<"0\n";
            else {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
}