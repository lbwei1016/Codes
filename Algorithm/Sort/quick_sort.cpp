/*
***Divide and Conquer / Sort***
    Solution:
        以 pivot 為基準，將數列依照小於或大於 pivot 分類:
            [小於pivot] [pivot] [大於pivot]
    Time Complexity:
        Best: O(nlogn)
        Average: O(nlogn)
        Worst: O(nlogn)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr = {9, 1, 2, 7, 5, 6, 4, 3, 8, 0, 94, -2, 293};
void quick_sort(int l, int r) {
    if(r-l <= 1) return;
    // i 指向最後一個小於 pivot 的位置，j 指向當前比較到的位置
    // 以最右為基準點
    // 為何以最右當基準點? 因為如此在 swap() 的過程中，pivot 才不會被移動。
    int i = l-1, j = l, pivot = arr[r-1];
    /* 
        another way to choose "pivot":
            pivot = median(arr[l], arr[r-1], arr[(l+r)/2])
            swap(arr[r-1], arr[pos_of_pivot]);
        如此要紀錄 pivot 被換到哪裡
    */
    while(j < r) {
        if(arr[j] < pivot) {
            ++i; swap(arr[i], arr[j]);
        }
        ++j;
    }
    // 插入 pivot
    swap(arr[i+1], arr[r-1]);
    quick_sort(l, i+1); quick_sort(i+2, r);
}

void also_quick(int l, int r) {
    if (r - l <= 1) return;
    vector<int> tmp(r-l); // 暫存
    int tl = 0, tr = r-l;
    int pivot = arr[l];
    for (int i=l+1; tr-tl>1; ++i) {
        if (arr[i] < pivot)
            tmp[tl++] = arr[i];
        else tmp[--tr] = arr[i];
    }
    tmp[tl] = pivot;
    copy(tmp.begin(), tmp.end(), arr.begin()+l);
    also_quick(l, l+tl); also_quick(l+tr, r);
}

int main() {
    random_shuffle(arr.begin(), arr.end());
    quick_sort(0, arr.size());
    for(int v : arr) cout << v << ' ';
    cout << '\n';

    random_shuffle(arr.begin(), arr.end());
    also_quick(0, arr.size());
    for(int v : arr) cout << v << ' ';
    cout << '\n';
    return 0;
}