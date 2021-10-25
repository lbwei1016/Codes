/*
***Divide and Conquer / Sort***
    Solution:
        以 pivot 為基準，將數列依照小於或大於 pivot 分類:
            [小於pivot] [pivot] [大於pivot]
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = {9, 1, 2, 7, 5, 6, 4, 3, 8, 0};
void quick_sort(int l, int r) {
    if(r-l <= 1) return;
    // i 指向最後一個小於 pivot 的位置，j 指向當前比較到的位置
    // 以最右為基準點
    int i = l-1, j = l, pivot = arr[r-1];
    while(j < pivot) {
        if(arr[j] < pivot) {
            ++i; swap(arr[i], arr[j]);
        }
        ++j;
    }
    // 插入 pivot
    swap(arr[i+1], arr[r-1]);
    quick_sort(l, i+1); quick_sort(i+2, r);
}
int main() {
    //random_shuffle(arr, arr+10);
    quick_sort(0, 10);
    for(int v : arr) cout << v << ' ';
    cout << '\n';
    return 0;
}
// 以下有問題
// #include <iostream>
// #include <algorithm>
// using namespace std;

// void quick_sort(int arr[], int l, int r) {
//     if(l >= r) return;
//     int pivot = l; // 以左為基準點
//     int i = l+1, j = r-1, val = arr[pivot];
//     while(i <= j) {
//         while(i < j && arr[j] > val) j--; // 由右往左搜尋
//         while(i < j && arr[i] < val) i++; // 由左往右搜尋
//         if(i == j) {
//             swap(arr[i], arr[pivot]);
//             pivot = i;
//             break;
//         }
//         else swap(arr[i], arr[j]);
//     }
//     quick_sort(arr, l, pivot); quick_sort(arr, pivot+1, r);
// }
// int main() {
//     int arr[10] = {9, 5, 1, 4, 7, 2, 3, 6, 8, 0};
//     //random_shuffle(arr, arr+10);
//     quick_sort(arr, 0, 9);
//     for(int v : arr) cout << v << ' ';
//     cout << '\n';
//     return 0;
// }