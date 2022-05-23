#include <iostream>
#include <cmath>
using namespace std;

bool isPalidrome(int n) {
    string num = "" + n;
    string clone = "";
    for (int i = size(num) - 1; i >= 0; i--) {
        clone += num[i];
    }

    return num == clone;
}

int main()
{
    cout << isPalidrome(121);
}
