/*
***Divide and Conquer***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

//[left, right)
void merge_sort(int arr[], int left, int right) {
    if(left+1 == right) return;
    int mid = (left + right) >> 1;
    merge_sort(arr, left, mid); merge_sort(arr, mid, right);

    int temp[right-left], j = mid;
    for(int i=left, k=0; i<mid; i++) {
        while(j<right && arr[j]<arr[i]) {
            temp[k++] = arr[j++];
        }
        temp[k++] = arr[i];
    }
    for(int i=left; i<j; i++) {
        arr[i] = temp[i-left];
    }
    return;
}
int main() {
    int n = 10;
    int arr[] = {8, 5, 1, 4, 10, 9, 2, 3, 6, 7};
    merge_sort(arr, 0, n);
    for(auto i : arr) 
        cout << i << ' ';
    return 0;
}