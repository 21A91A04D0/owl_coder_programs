#include<bits/stdc++.h>
using namespace std;
void Merge(int low, int mid, int high, int *arr) {
    int i = low;
    int j = mid + 1;
    int temp[high++];
    int k = low;
    while(i <= mid && j < high){
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j < high) {
        temp[k++] = arr[j++];
    }
    for(int i = low ; i < high ; i++) {
        arr[i] = temp[i];
    }
}
void MergeSort(int low, int *arr, int high) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    MergeSort(low, arr, mid);
    MergeSort(mid + 1, arr, high);
    Merge(low, mid, high, arr);
}
int main() {
    int arr[9] = {9, 9, 8, 9, 5, 5 ,9, 9, 9};
    int n = sizeof(arr) / sizeof(int);
    MergeSort(0, arr, n);
    for(int i = 0 ; i < n ; i ++) {
        cout << arr[i] << " ";
    }
}

//Time Complexity :- O(nlog(n))
//space complexity :- O(n)