#include <bits/stdc++.h>
using namespace std;

// 將子樹更新成 heap (此時 at 為 root)
void heapify(vector<int> &arr, int chl, int sz) {
    while(chl < sz) {
        int big, at = chl / 2;;
        if(chl + 1 < sz) 
            big = arr[chl] > arr[chl+1] ? chl : chl+1;
        else big = chl;
        if(arr[at] < arr[big]) 
            swap(arr[at], arr[big]);
        chl = 2*chl + 1;
    }
}

void heap_sort(vector<int> &arr) {
    int sz = arr.size();
    // 對所有父節點 (非葉) 進行 heapify
    // O(n)，比一個一個 push 進 heap 的 O(n logn) 快
    for(int i=sz/2 - 1; i>=0; --i) 
        heapify(arr, 2*i+1, sz);
    // pop 出最大值，再 heapify 剩下的樹 
    for(int i=sz-1; i>0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, 1, i);
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    heap_sort(arr);
    for(auto x: arr) cout << x << ' ';

    return 0;
}