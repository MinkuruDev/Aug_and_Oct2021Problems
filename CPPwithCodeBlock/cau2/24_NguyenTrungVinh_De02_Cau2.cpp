#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void input(long &n){
    cout << "nhap n: ";
    cin >> n;
}

bool isSquare(long num){
    float squareRootOfN = sqrt(num);
    return (long) squareRootOfN == squareRootOfN;
}

bool isPerfectNumber(long num){
    long sum = 1;
    long squareRootOfN = sqrt(num);

    for(long i = 2; i<=squareRootOfN; i-=-1){
        if(num%i==0){
            sum += i + num/i;
        }
    }

    if(isSquare(num)) sum -= squareRootOfN;

    return sum == num;
}

void output(long n){
    string perfectNumber = "";

    for(long i = 0; i<=n; i++){
        if(isPerfectNumber(i)){
            perfectNumber += " " + to_string(i);
        }
    }

    if(perfectNumber == ""){
        cout << "khong co so hoan hao nao nho hon hoac bang " << n;
    }else{
        cout << "nhung so hoan hao nho hon hoac bang " << n << " la:" << perfectNumber;
    }
}

int main(){
    long n;
    input(n);
    output(n);
    return 0;
}
