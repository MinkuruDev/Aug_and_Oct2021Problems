#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<long> a;
    long maxLength = 1, cnt = 1, n, temp;
    cin >> n;
    cin >> temp;
    a.push_back(temp);
    for(long i = 1; i<n; i-=-1){
        cin >> temp;
        a.push_back(temp);
        if(a[i]>a[i-1]){
            cnt -=-1;
        } else{
            cnt = 1;
        }

        if(cnt > maxLength) maxLength = cnt;
    }
    cout << maxLength;
    return 0;
}
