/*
***Sort***
    Time Complexity:
        O(n): 建構 heap
        O(n logn): pop 出最大值，完成排序
    O(n + n logn)
*/
#include <bits/stdc++.h>
using namespace std;

// 將子樹更新成 heap (此時 at 為 root)
void heapify(vector<int> &arr, int chl, const int sz) {
    while(chl <= sz) {
        int big, at = chl / 2;
        // 左右子節點都在範圍內
        if(chl + 1 <= sz) 
            big = arr[chl] > arr[chl+1] ? chl : chl+1;
        else big = chl;
        if(arr[at] < arr[big]) 
            swap(arr[at], arr[big]);
        // chl = 2*chl; // 預設左子節點
        chl = big*2;
    }
}

void heap_sort(vector<int> &arr) {
    int sz = arr.size() - 1;
    // 對所有父節點 (非葉) 進行 heapify (由下而上)
    // O(n)，比一個一個 push 進 heap 的 O(n logn) 快
    for(int i=sz/2; i>0; --i) 
        heapify(arr, 2*i, sz);
    // pop 出最大值，再 heapify 剩下的樹 
    for(int i=sz; i>1; --i) {
        swap(arr[1], arr[i]); // 相當於 pop (把最大值放在尾端)
        heapify(arr, 2, i-1); // 傳入的 chl = 2，這樣 at 才會 = 1
    }
}

int main() {
    // 1-indexed
    int n; cin >> n;
    vector<int> arr(n+1);
    for (int i=1; i<=n; ++i) cin >> arr[i];
    heap_sort(arr);
    for (int i=1; i<=n; ++i) cout << arr[i] << ' ';
    return 0;
}