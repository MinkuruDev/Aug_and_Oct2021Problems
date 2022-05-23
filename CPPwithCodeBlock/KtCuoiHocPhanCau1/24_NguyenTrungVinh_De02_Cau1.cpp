#include <iostream>
#include <cstdio>
using namespace std;

void input(int &money){
    cout << "nhap so tien can rut: ";
    cin >> money;
}

void divineMoney(int money){
    const int numberOfMoney = 4;
    int m[numberOfMoney] = {100,20,5,1};
    int totalMoney = 0, temp;

    for(int i = 0; i<numberOfMoney; i-=-1){
        temp = money / m[i];
        printf("so luong to tien menh gia %d la: %i\n", m[i], temp);
        money %= m[i];
        totalMoney += temp;
    }

    cout << "tong so to tien ban nhan duoc la: " << totalMoney;
}

int main(){
    int money;
    input(money);
    divineMoney(money);
    return 0;
}
