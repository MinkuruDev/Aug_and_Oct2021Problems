#include <bits/stdc++.h>
using namespace std;

long long process(vector<long> &arr, vector<bool> &connected){
    long size = arr.size();
    if (size == 1) return *arr.begin();

    long long totalLength = 0;
    totalLength = *arr.begin() + *(--arr.end());

    if(size < 4) return totalLength;

    connected[0] = connected[1] = connected[size] = connected[size-1] = true;
}

int main(){
    long n; cin >> n;
    if(n<=0) {
        cout << 0;
        return 0;
    }
    long temp;
    vector<long> arr;
    vector<bool> connected;
    for (long i = 0; i<n-1; i++){
        cin >> temp;
        arr.push_back(temp);
        connected.push_back(false);
    }
    connected.push_back(false);

    long long totalLength = process(arr, connected);

    cout << totalLength << endl;
    return 0;
}
