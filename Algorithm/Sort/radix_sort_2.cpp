/*
***Sort*** -- subroutine: Counting Sort
    Description:
        Radix sort 分成兩種:
            LSD（Least significant digit）或 MSD（Most significant digit）
        透過將一位數一位數的比較結果暫存在 "buckets" 中，自低而高 (高而低) 的
        位數分層排序。
    O(n * log(B)m) = O(n * k)
        n: 元素數
        B: 基數，此處為 10，即進位制 (B 為 log... 的底數)
        m: 元素總堆數，此處為最大數值 => log(B)m = 9
        k: 最高位數
*/
#include <iostream>
#include <vector>
using namespace std;

void radix_sort(int arr[], int n) {
    int mx = 0, tmp[n];
    // 先找出最大值以利邊界設定
    for(int i=0; i<n; ++i) {
        if(arr[i] > mx) mx = arr[i];
    }
    // counting sort
    for(int i=1; mx/i > 0; i*=10) {
        int count[n] = {0};
        for(int j=0; j<n; ++j) ++count[(arr[j]/i) % 10]; // 先數有多少個
        // 取前綴和，代表將數字 "推至" 正確的相對位置
        for(int j=1; j<n; ++j) count[j] += count[j-1]; 
        /*
            倒著更新 tmp:
                為了要讓原本就在陣列後端的元素繼續待在相對後端的位置，
                因此不會打亂前幾次的排序 (較低位的排序)
        */
        for(int j=n-1; j>=0; --j) {
            tmp[--count[(arr[j]/i) % 10]] = arr[j];
        }
        for(int j=0; j<n; ++j) arr[j] = tmp[j]; // update
    }
    for(int i=0; i<n; ++i) cout << arr[i] << ' ';
}

// 注意 base (b != n)
// 上一版沒注意到 (因為 n 剛好等於十)
void radix_sort2(vector<int> &v) {
    int n = v.size(), b = 10, mx = 0;
    vector<int> tmp(n);
    for (auto &x: v) mx = max(mx, x);
    
    for (int i=1; mx/i>0; i*=10) {
        vector<int> count(b);
        for (int j=0; j<n; ++j) 
            ++count[v[j]/i % 10];
        for (int j=1; j<b; ++j)
            count[j] += count[j-1];
        for (int j=n-1; j>=0; --j) 
            tmp[--count[v[j]/i % 10]] = v[j];
        for (int j=0; j<n; ++j) v[j] = tmp[j];
    }
}

int main() {
    int arr[10] = {58, 888, 11, 98, 0, 2, 65, 45, 7, 15}; 
    radix_sort(arr, 10);   
    return 0;
}