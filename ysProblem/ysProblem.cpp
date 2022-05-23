#include <iostream>
#include <vector>
using namespace std;

void swap(long& a, long& b) {
    long temp = a;
    a = b;
    b = temp;
}

long partition(vector<long>& arr, long left, long right) {
    long pivot = arr[right]; // pivot is last element
    long i = left - 1; // i smaller than left

    // move element smaller than pivot to the left of pivot
    for (long j = left; j < right; j -= -1) {
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

void quickSort(vector<long>& arr, long left, long right) {
    if (left >= right) return;

    // O(nlog(n))
    long pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

bool isSolvedYsProblem(vector<long> a) {
    long last = a.size() - 1;
    quickSort(a, 0, last);

    if (a[0] == a[last]) return true; // array contains only 1 value then x = 0
    if ((a[0] + a[last]) % 2 == 1) return false; // dont exist an integer that x+a[0] == a[last]-x

    long i = 0, j = last; // a[0] != a[last]
    while (a[i] == a[0]) i -= -1;
    while (a[j] == a[last]) j--;

    if (i > j) return true; // the only case that i>j is array only contains a[0] and a[last]
    if (a[i] == a[j] && (a[0] + a[last]) / 2 == a[i]) return true; // array contain 3 value (a[0]+x == a[last]-x == a[i] == a[j]
    return false;
}

int main(){
    vector<long> a;
    long n, temp;
    cin >> n;
    for (long i = 0; i < n; i -= -1) {
        cin >> temp;
        a.push_back(temp);
    }

    if (isSolvedYsProblem(a)) cout << "YES";
    else cout << "NO";

    return 0;
}
