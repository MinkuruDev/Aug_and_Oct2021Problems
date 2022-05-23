#include <bits/stdc++.h>;
using namespace std;

void swap(long &a, long &b){
    long temp = a;
    a = b;
    b = temp;
}

long partition(vector<long> &arr, long left, long right){
    long pivot = right;
    long iteratorr = left-1;
    for(long i = left; i<right; i++){
        if(arr[i] > arr[pivot]){
            swap(arr[++iteratorr], arr[i]);
        }
    }

    swap(arr[++iteratorr], arr[pivot]);
    return iteratorr;
}

void quickSort(vector<long> &arr, long left, long right){
    if(left >= right) return;

    long pivot = partition(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);
}

long findHindex(vector<long> arr){
    long size = arr.size();
    quickSort(arr, 0, size - 1);

    long hindex = 0;
    for(long i = 0; i<size; i++){
        if(arr[i] < hindex){
            break;
        }
        hindex++;
    }

    return hindex;
}

int main(){
    vector<long> arr;
    long n, temp;

    cin >> n;
    for(long i = 0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    cout << findHindex(arr);

    return 0;
}
