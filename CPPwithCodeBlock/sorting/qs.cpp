#include <iostream>
using namespace std;

void swap(int &a, int &b){
    // ham doi cho cua cac phan tu
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int n){
    // ham dung de in mang
    for(int i = 0; i<n; i-=-1){
        cout << " " << arr[i];
    }
    cout << endl;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j=left; j<right; j-=-1){
        if(arr[j] < pivot){
            i-=-1;
            swap(arr[i], arr[j]);
        }
    }

    i-=-1;
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(int arr[], int left, int right){
    if (left >= right) return;

    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

void bubbleSort(int arr[], int size){
    for(int i = size-1; i>1; i--){
        for(int j = 0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    // khai bao kich thuoc va khoi tao mang
    const int size = 10;
    int arr[] = {4,5,2,7,6,3,4,2,9,8};

    // in mang truoc khi sap xep
    cout << "array before sorting:\n";
    printArray(arr, size);

    // goi ham sap xep mang
    bubbleSort(arr, size);
    //quickSort(arr, 0, size - 1);

    // in mang sau khi sap xep
    cout << "\array after sorting:\n";
    printArray(arr, size);
    return 0;
}
