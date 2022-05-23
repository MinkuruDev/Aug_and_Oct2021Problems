#include <bits/stdc++.h>

typedef long long LL;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL left, right;
    int n, bitL, bitR;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> left >> right;
        bitL = 63 - __builtin_clzll(left);
        bitR = 63 - __builtin_clzll(right);

        if(bitL<bitR)
            cout << "Case #" << i+1 << ": " << bitR << endl;
        else{
            for(int j = bitR - 1; j>0; j--){
                long k = (long)pow(right + 0.1, 1.0/j);
                LL s = (LL)pow(k,j);
                if(s >= left && s <= right){
                    cout << "Case #" << i+1 << ": " << j << endl;
                    break;
                }
            }
        }


    }

    return 0;
}
