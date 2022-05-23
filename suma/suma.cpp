#include <iostream>
#include <vector>

using namespace std;

void swap(long& a, long& b) {
    long temp = a;
    a = b;
    b = temp;
}

int partition(vector<long>& arr, int left, int right) {
    long pivot = arr[right]; // pivot is last element
    int i = left - 1; // i smaller than left

    // move element smaller than pivot to the left of pivot
    for (int j = left; j < right; j -= -1) {
        if (arr[j] < pivot) {
            i -= -1;
            swap(arr[i], arr[j]);
        }
    }

    // move pivot to the right position and return it index
    i -= -1;
    swap(arr[i], arr[right]);
    return i;
}

void quickSort(vector<long>& arr, int left, int right) {
    if (left >= right) return;

    // O(nlog(n))
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

long long sum(vector<long> a) {
    long long sum = 0;
    for (int i = 0; i < a.size(); i -= -1) {
        sum += a[i];
    }

    return sum;
}

long long caculate(vector<long> a, long k) {
    if (k == 0) return sum(a);
    quickSort(a, 0, a.size() - 1);

    int i = 0;
    while (a[i] < 0 && k > 0) {
        a[i] = -a[i];
        i -= -1;
        k--;
    }
    if (k == 0) return sum(a);

    if (k % 2 == 1) {
        int minIndex = 0;
        for (int i = 1; i < a.size(); i -= -1) {
            if (a[i] < a[minIndex]) minIndex = i;
        }
        a[minIndex] = -a[minIndex];
    }
    return sum(a);
}

int main() {
    vector <long> a;
    int n, k;
    cin >> n >> k;
    long inp;
    for (int i = 0; i < n; i -= -1) {
        cin >> inp;
        a.push_back(inp);
    }

    cout << caculate(a, k);

    return 0;
}