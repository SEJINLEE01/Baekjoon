#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int getSum(string block) {
    int sum = 0;
    stringstream ss(block);
    string temp;

    while (getline(ss, temp, '+')) {
        sum += stoi(temp);
    }

    return sum;
}

int main() {
    string expression;
    cin >> expression;
    stringstream ss(expression);
    string temp;
    vector<int> groupSums;

    while (getline(ss, temp, '-')) {
        groupSums.push_back(getSum(temp));
    }

    int result = result + groupSums[0];

    for (int i = 1;i < groupSums.size();i++)
        result = result - groupSums[i];

    cout << result << "\n";
    return 0;
}