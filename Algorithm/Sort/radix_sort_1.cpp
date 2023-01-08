/*
***Sort*** -- subroutine: Bucket Sort
    Description:
        Radix sort 分成兩種:
            LSD（Least significant digit）或 MSD（Most significant digit）
        透過將一位數一位數的比較結果暫存在 "buckets" 中，自低而高 (高而低) 的
        位數分層排序。
    O((n+B) * log_B(m)) = O((n+B) * k)
        n: 元素數
        B: 基數，此處為 10，即進位制 (B 為 log... 的底數)
        m: 元素總堆數，此處為最大數值 => log_B(m) = 9
        k: 最高位數
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 9; // 假設最大位數 9 位 (base 10 -> 1e9)
    const int base = 10;
    vector<int> arr = {98, 410, 54, 32, 68, 74, 1, 25, 66, 4};
    vector<vector<int> > bucket(base); // 暫存的桶子
    
    // radix sort
    for(int i=1, pow=1; i<=N; ++i, pow*=10) {
        for(int j=0, l=arr.size(); j<l; ++j) {
            // (arr[j]/pow) % 10 : get i-th digit
            bucket[(arr[j]/pow) % 10].push_back(arr[j]);
        }
        int cnt = 0;
        // update from buckets: O(n+B)
        for(auto &b : bucket) {
            for(auto &v : b) {
                arr[cnt++] = v;
            }
            b.clear();
        }
        cout << "Step " << i << ":\n";
        for(auto &v : arr) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}