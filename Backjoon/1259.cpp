#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    int count = 0;

    while (true) {


        cin >> num;
        if (num == "0") break;
        
        if (num.length() == 1) {
            cout << "yes" << endl;
            continue;
        }

        for (int i = 0;i < num.length() / 2;i++) {
            if (num[i] != num[num.length() - i - 1])
            {
                cout << "no" << endl;
                break;
            }

            count++;
            if (count == num.length() / 2)
                cout << "yes" << endl;
        }
        count = 0;
    }


}