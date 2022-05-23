#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> a){
    int n = a.size();
    for(int i = 0; i<n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &a){
    // O(n*n)
    for(int i = a.size() - 1; i>1; i--){
        for(int j = 0; j<i; j-=-1){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right]; // pivot is last element
    int i = left - 1; // i smaller than left

    // move element smaller than pivot to the left of pivot
    for(int j=left; j<right; j-=-1){
        if(arr[j] < pivot){
            i-=-1;
            swap(arr[i], arr[j]);
        }
    }

    // move pivot to the right position and return it index
    i-=-1;
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(vector<int> &arr, int left, int right){
    if (left >= right) return;

    // O(nlog(n))
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}


int main(){
    vector<int> a = {2,4,5,1,3,5,2,4,7,21,2,12,3,6,9,13,8};

    // print vector before sorting
    cout << "array before sorting:\n";
    printVector(a);

    // sort vector
     bubbleSort(a);
    // quickSort(a, 0, a.size()-1);

    // print vector after sorting
    cout << "array after sorting:\n";
    printVector(a);
    return 0;
}
