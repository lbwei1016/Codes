/*
    除了 "std::__lg()" 定義在 <algorithm> (?) 之外，其他都是 GCC 內建函數
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 14;
    cout << __lg(n) << '\n'; // 返回左起第一個 1 是第幾位元, i.e. ⌊log(2)n⌋
    cout << __builtin_ffs(n) << '\n'; // 返回右起第一個 1 的位置
    cout << __builtin_clz(n) << '\n'; // 返回左起第一個 1 之前的 0 的個數
    cout << __builtin_ctz(n) << '\n'; // 返回右起第一個 1 右方的 0 的個數
    cout << __builtin_popcount(n) << '\n'; // 返回 1 的個數
    cout << __builtin_parity(n) << '\n'; // 返回 1 的個數 mod 2
    return 0;
}