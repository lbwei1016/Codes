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
    // i 指向最後一個小於等於 pivot 的位置，j 指向當前比較到的位置
    // 以最右為基準點
    // 為何以最右當基準點? 因為如此在 swap() 的過程中，pivot 才不會被移動。
    int i = l;
    int pivot = arr[r-1];
    /* 
        another way to choose "pivot":
            pivot = median(arr[l], arr[r-1], arr[(l+r)/2])
            swap(arr[r-1], arr[pos_of_pivot]);
        如此要紀錄 pivot 被換到哪裡
    */
    for (int j=l; j<r; ++j) {
        if(arr[j] < pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    // 插入 pivot
    swap(arr[i], arr[r-1]);
    quick_sort(l, i); quick_sort(i+1, r);
}

// 找第 k 大的值
void quick_select(vector<int>::iterator l, vector<int>::iterator k, vector<int>::iterator r) {
    if (r - l <= 1) return;
    auto i = l; // position of the last one smaller or greater than *pivot
    auto pivot = r - 1;
    for (auto j = l; j < r; ++j) {
        if (*j < *pivot) {
            swap(*i, *j);
            i++;
        }
    }
    swap(*i, *pivot);
    if (k == i) return;
    else if (k > i) return quick_select(i+1, k, r);
    else return quick_select(l, k, i);
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

// 飛快的 quick select (甚至可比 std::nth_element() 快)
// credit: https://hackmd.io/@XYFC128/HyA0tyxfj (Daniel Liu)
// Hoare’s partition scheme
// note: pivot must not be a reference
inline std::vector<int>::iterator partition(std::vector<int>::iterator l, std::vector<int>::iterator r, int pivot) {
    while (1) {
        while (*l < pivot)
            ++l;
        
        do {
            --r;
        } while (pivot < *r);
        
        if (l >= r)
            return l;

        swap(*l, *r);
        ++l;
    }
}

inline void kth_element(std::vector<int>::iterator l, std::vector<int>::iterator r, size_t k) {
    auto target = l + k;
    while (r - l > 1) {
        auto pivot = l + (r - l) / 2;

        auto cut = partition(l, r, *pivot); // cut will be the first element in the array that >= pivot

        if (target < cut)
            r = cut;
        else
            l = cut;
    }
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