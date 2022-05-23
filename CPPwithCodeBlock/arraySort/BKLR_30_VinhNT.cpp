#include <iostream>
using namespace std;

long caculate(int n){
    return (n*(n-1)*(n-2))/6;
}

int main(){
    cout << "nhap vao so nguyen n: ";
    int n; cin >> n;
    cout << caculate(n);
}
