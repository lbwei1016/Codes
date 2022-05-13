/*
***Divide and Conquer / Sort***

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
}

void non_rec_merge(int arr[], int arr_sz) {
    int seg_sz = 1;
    while (seg_sz < arr_sz) {
        int i;
        for (i=0; i+seg_sz<arr_sz; i+=2*seg_sz) {
            int tmp[2*seg_sz], j = i+seg_sz;
            for (int k=i, cnt=0; k-i<seg_sz; ++k) {
                while (j<i+2*seg_sz && arr[j]<arr[k]) {
                    tmp[cnt++] = arr[j++];
                }
                tmp[cnt++] = arr[k];
            }
            for (int k=i; k<j; ++k) {
                arr[k] = tmp[k-i];
            }
        }
        seg_sz *= 2;
    }
}

int main() {
    int arr[] = {8, 5, 1, 4, 10, 9, 2, 3, 6, 7, -3, 23, -93, 12, 34};
    non_rec_merge(arr, sizeof(arr)/sizeof(int));
    // merge_sort(arr, 0, sizeof(arr)/sizeof(int));
    for(auto i : arr) 
        cout << i << ' ';
    return 0;
}