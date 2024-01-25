#include<bits/stdc++.h>
using namespace std;
void BubbleSort(int i, int *arr, int n) {
    if(n == 1) return;
    if(i == n - 1) {
        //inner loop
        BubbleSort(0, arr, n - 1);
        return;
    }
    //case
    if(arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
    }
    // recursive call for outerloop
    BubbleSort(i+1, arr, n);
}
int main() {
    int arr[5] = {3, 7, 1, 9, 2};    
    BubbleSort(0, arr, 5);
    for(int i = 0 ; i < 5 ; i++) {
        cout << arr[i] << " ";
    }
}

// Time complexity:- 
  // worst case:- O(n^2)
  // Best case:- O(n)