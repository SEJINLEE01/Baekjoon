#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int error = 0;
    bool isReverse;

    while (N--) {
        deque<int> list;
        string s; //명령
        cin >> s;
        int d; //배열개수
        cin >> d;
        string v; //리스트값
        cin >> v;
        isReverse = false;
        
        for (char& c : v) { //배열 정리
            if (c == '[' || c == ']' || c == ',')
                c = ' ';
        }

        stringstream ss(v);
        int temp;

        while (ss >> temp) //정수형 추출
            list.push_back(temp);

        for (char c : s) {
            if (c == 'R') {
                if (isReverse)
                    isReverse = false;
                else
                    isReverse = true;
            }
            else if (c == 'D') {
                if (!list.empty())
                    if (isReverse)
                        list.pop_back();
                    else
                        list.pop_front();
                else { //에러면 다음으로
                    cout << "error\n";
                    error = 1;
                    break;
                }
            }
        }

        if (error == 1) {
            error = 0;
            continue;
        }

        cout << "[";
        if (isReverse) {
            for (int i = 0;i < list.size();i++) {
                if (i == list.size() - 1)
                    cout << list[list.size() - 1 - i];
                else
                    cout << list[list.size() - 1 - i] << ",";
            }
        }
        else {
            for (int i = 0;i < list.size();i++) {
                if (i == list.size() - 1)
                    cout << list[i];
                else
                    cout << list[i] << ",";
            }
        }
        cout << "]\n";


    }
}