#include <iostream>
#include <vector>
#include <cstdlib>

struct TimeToSolve{
    int a,b;
};

int partition(std::vector<TimeToSolve> &arr, int left, int right, char option){
    /* srand(time(NULL));
    int r = rand() % (left - right) + left;
    std::swap(arr[r], arr[right]); */
    TimeToSolve pivot = arr[right];
    int i = left - 1;

    for (auto j = left; j<right; j-=-1){
        if (option == 'a'){
            if(arr[j].a - arr[j].b > pivot.a - pivot.b){
                std::swap(arr[j], arr[++i]);
            }
        }else{
            if(arr[j].b - arr[j].a > pivot.b - pivot.a){
                std::swap(arr[j], arr[++i]);
            }
        }

    }
    std::swap(arr[++i], arr[right]);
    return i;
}

void quickSort(std::vector<TimeToSolve> &arr, int left, int right, char option){
    if (left >= right) return;

    int pivotIndex = partition(arr, left, right, option);

    quickSort(arr, left, pivotIndex-1, option);
    quickSort(arr, pivotIndex+1, right, option);
}

std::vector<TimeToSolve> merge(std::vector<TimeToSolve> left, std::vector<TimeToSolve> right, char option){
    std::vector<TimeToSolve> target;
    int i = 0, j = 0;
    int leftSize = left.size(), rightSize = right.size();

    if(option == 'a'){
        while(i<leftSize && j<rightSize){
            if(left[i].a - left[i].b > right[j].a - right[j].b){
                target.push_back(left[i]);
                i++;
            }else{
                target.push_back(right[j]);
                j++;
            }
        }
        while(i<leftSize){
            target.push_back(left[i]);
            i++;
        }
        while(j<rightSize){
            target.push_back(right[j]);
            j++;
        }
    }else{
        while(i<leftSize && j<rightSize){
            if(left[i].b - left[i].a > right[j].b - right[j].a){
                target.push_back(left[i]);
                i++;
            }else{
                target.push_back(right[j]);
                j++;
            }
        }
        while(i<leftSize){
            target.push_back(left[i]);
            i++;
        }
        while(j<rightSize){
            target.push_back(right[j]);
            j++;
        }
    }

    return target;
}

void mergeSort(std::vector<TimeToSolve> &arr, char option){
    int size = arr.size();
    if (size <= 1) return;
    std::vector<TimeToSolve> arrLeft, arrRight;

    for(int i = 0; i<(int) size/2; i++){
        arrLeft.push_back(arr[i]);
    }
    for(int i = (int) size/2; i<size; i++){
        arrRight.push_back(arr[i]);
    }

    mergeSort(arrLeft, option);
    mergeSort(arrRight, option);

    arr = merge(arrLeft, arrRight, option);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<TimeToSolve> aSolve, bSolve;
    int n; std::cin >> n;
    TimeToSolve temp;
    for(auto i = 0; i<2*n; i++){
        std::cin >> temp.a;
        std::cin >> temp.b;
        if (temp.a < temp.b){
            aSolve.push_back(temp);
        }else{
            bSolve.push_back(temp);
        }
    }
    int aSize = aSolve.size();
    int bSize = bSolve.size();
    if(aSize < bSize){
        //quickSort(bSolve, 0, bSize - 1, 'a');
        mergeSort(bSolve, 'a');
        while(aSize < n){
            aSolve.push_back(bSolve.back());
            bSolve.pop_back();
            aSize++;
        }
    }
    if(aSize > bSize){
        //quickSort(aSolve, 0, aSize - 1, 'b');
        mergeSort(aSolve, 'b');
        while(bSize < n){
            bSolve.push_back(aSolve.back());
            aSolve.pop_back();
            bSize++;
        }
    }

    long long sum = 0;
    for(int i = 0; i<n; i++){
        // << aSolve[i].a << " " << aSolve[i].b << endl;
        sum += aSolve[i].a + bSolve[i].b;
    }

    std::cout << sum;

    return 0;
}
