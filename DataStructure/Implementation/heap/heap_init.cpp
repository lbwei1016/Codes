/*
***Heap***
    Description:
        Initialize heap in O(n).
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 11;

void init(vector<int> &heap) {
    // 最右下方非葉的節點
    int at = SIZE / 2;
    // 自最右下方更新至根節點
    while (at > 0) {
        int trav_at = at;
        while (trav_at <= SIZE/2) {
            int val = heap[trav_at];
            int lch = 2 * trav_at, rch = 2 * trav_at + 1;
            if (heap[lch] <= val && heap[rch] <= val)
                break;

            // 找左右子節點中大的與自己交換
            int mx = 0, mx_at;
            if (heap[lch] > heap[rch]) {
                mx = heap[lch];
                mx_at = lch;
            }
            else {
                mx = heap[rch];
                mx_at = rch;
            }
            swap(heap[mx_at], heap[trav_at]);
            trav_at = mx_at;
        }
        --at; 
    }
}

int main() {
    // 1-indexed
    vector<int> heap(SIZE+1);
    for (int i=1; i<=SIZE; ++i)
        heap[i] = i;
    init(heap);
    for (int i=1; i<=SIZE; ++i) {
        cout << heap[i] << ' ';
    }
    cout << '\n';
    return 0;
}