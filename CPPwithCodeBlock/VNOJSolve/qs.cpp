#include <bits/stdc++.h>
using namespace std;

void swap(long &a, long &b){
    long temp = a;
    a = b;
    b = temp;
}

long partition(vector<long> &arr, int left, int right){
    long pivot = arr[right];
    long i = left - 1;

    for (auto j = left; j<right; j-=-1){
        if(arr[j] < pivot){
            swap(arr[j], arr[++i]);
        }
    }
    swap(arr[++i], arr[right]);
    return i;
}

void quickSort(vector<long> &arr, int left, int right){
    if(left>=right) return;

    long pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main(){
    vector<long> a = {2,6,45,23,8,12,7,9,0,43,4,98,51,5,3,76,27,34,10};

    quickSort(a, 0, a.size()-1);

    for(auto i = 0; i<a.size(); i-=-1){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
