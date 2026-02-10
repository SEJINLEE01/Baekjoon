#include <iostream>
#include <string>
using namespace std;

int main() {
    string a[3];
    int num, index;
    for (int i = 0;i < 3;i++)
        cin >> a[i];
    bool is_digit = false;

    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < a[i].length();j++) {
            if (isdigit(a[i][j])) {
                is_digit = true;
                break;
            }
        }

        if (is_digit) {
            num = stoi(a[i]);
            index = i;
            is_digit = false;
        }
    }

    int result_num = num + 3 - index;

    if (result_num % 3 == 0 && result_num % 5 == 0)
        cout << "FizzBuzz" << endl;
    else if (result_num % 3 == 0)
        cout << "Fizz" << endl;
    else if (result_num % 5 == 0)
        cout << "Buzz" << endl;
    else
        cout << result_num << endl;


}