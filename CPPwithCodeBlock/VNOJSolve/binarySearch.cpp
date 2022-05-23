#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int value){
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while (low < high){
        mid = (low + high) / 2;
        if(arr[mid] == value) return mid;
        if(arr[mid] > value) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a = {1,4,5,6,8,9,10,13,16,18,21};
    for (int i = 1; i<15; i++){
        cout << binarySearch(a, i) << " ";
    }

    return 0;
}
