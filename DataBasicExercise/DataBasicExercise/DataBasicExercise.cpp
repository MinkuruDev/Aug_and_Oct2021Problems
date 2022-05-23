#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void ageCaculator() {
    cout << "nhap nam sinh: ";
    int yearOfBirth;
    cin >> yearOfBirth;
    const int THIS_YEARS = 2021;

    cout << "tuoi cua ban: " << THIS_YEARS - yearOfBirth << endl;
}

void easyCaculator() {
    cout << "nhap 2 so a,b: ";
    int a, b;
    cin >> a >> b;

    cout << "a + b = " << a + b;
    cout << "\na - b = " << a - b;
    cout << "\na * b = " << a * b;
    cout << "\na / b = ";
    if (b == 0) {
        cout << "Infinite";
    }else {
        cout << (float)a / b;
    }

    cout << endl; // xuong dong
}

void moneyCaculator() {
    const float TAX = 0.1;
    float money, price;
    int numbers;

    cout << "nhap don gia, so luong: ";
    cin >> price >> numbers;
    
    // tinh tien
    money = price * numbers;
    money += money * TAX;

    printf("so tien phai tra la: %.0f vnd\n", money);
}

void average() {
    cout << "nhap diem 3 mon toan, ly, hoa: ";
    float math, physics, chemistry, average;
    cin >> math >> physics >> chemistry;
    average = (math + physics + chemistry) / 3;

    printf("diem trung binh 3 mon: %.1f", average);
}

bool isPalidrome(int num) {
    string n = to_string(num);
    string copy = "";
    for (int i = size(n) - 1; i >= 0; i--) {
        copy += n[i];
    }

    return n == copy;
}

void palidrome() {
    int n;
    cout << "nhap so: ";
    cin >> n;
    
    if (isPalidrome(n)) {
        cout << n << " la so doi xung\n";
        return;
    }

    cout << n << " khong la so doi xung\n";
}

bool isSquare(int n) {
    return ((int)sqrt(n) == sqrt(n));
}

void square() {
    int n;
    cout << "nhap so: ";
    cin >> n;

    if (isSquare(n)) {
        cout << n << " la so chinh phuong\n";
        return;
    }

    cout << n << " khong la so chinh phuong\n";
}

bool isPrime(int n) {
    if (n < 2) return false;

    int s = (int)sqrt(n);
    for (int i = 2; i < s; i-=-1) {
        if (n % i == 0) return false;
    }
    return true;
}

void prime() {
    int n;
    cout << "nhap so: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " la so nguyen to\n";
        return;
    }

    cout << n << " khong la so nguyen to\n";
}

int main()
{
    int selection = 0;
    do {
        cout << "\n1. tinh tuoi\n";
        cout << "2. tinh toan 2 so nguyen\n";
        cout << "3. tinh tien\n";
        cout << "4. tinh diem trung binh\n";
        cout << "5. kiem tra so doi xung\n";
        cout << "6. kiem tra so chinh phuong\n";
        cout << "7. kiem tra so nguuyen to\n";
        cout << "0. thoat\n";
        cout << "nhap lua chon: ";
        cin >> selection;

        switch (selection){
        case 0:
            break;
        case 1:
            ageCaculator();
            break;
        case 2:
            easyCaculator();
            break;
        case 3:
            moneyCaculator();
            break;
        case 4:
            average();
            break;
        case 5:
            palidrome();
            break;
        case 6:
            square();
            break;
        case 7:
            prime();
            break;
        default:
            cout << "hay chon 1 so kha dung!\n";
        }

        if (selection) {
            system("pause");
        }

    } while (selection);
    
    
}
