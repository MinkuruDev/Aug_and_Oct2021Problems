#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMultipleOf36(string num) {
    if (num == "0") return true;
    int len = num.length();
    if (len == 1) return false;

    // is multiple of 4 (num%4 == 0)    
    // take 2 last char
    string temp = "";
    temp.push_back(num[len - 2]);
    temp.push_back(num[len - 1]);
    bool isMultipleOf4 = stoi(temp) % 4 == 0;

    // is multiple of 9 (num%9 == 0)
    // sum of all number in num
    long sum = 0;
    for (int i = 0; i < len; i -= -1) {
        sum += num[i] - '0';
    }
    bool isMultipleOf9 = sum % 9 == 0;

    return isMultipleOf4 && isMultipleOf9;
}

int main(){
    int n;
    cin >> n;
    string num;

    for (int i = 0; i < n; i -= -1) {
        cin >> num;
        if (isMultipleOf36(num)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
