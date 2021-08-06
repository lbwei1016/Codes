/*
***String***
    Description I: (求出後綴陣列)
        利用 "倍增法 + 基數排序" 來優化時間複雜度。
        (Doubling Algorithm + radix sort(counting sort as subroutine))
        倍增法: 
            在字串尾加上 '\0'，操作時想像字串是環狀的，像是:
            aabbaa$
                $aabbaa$: $
                a$aabbaa: a$
                aa$aabba: aa$
                aabbaa$a: aabbaa$
                abbaa$aa ...
                baa$aabb
                bbaa$aab
            一次檢查 2^k 個字元；以 mod 來達到環狀的效果，省去檢查邊界。
    Description II: (求出高度陣列)
        LCP: Longset Common Prefix
        首先定義:
            Suffix[i] = s[i...n]
            LCP(i, j) = lcp(Suffix[i], Suffix[j])
            後綴陣列: sa[i]: 順序第 i 的是第幾個後綴
            排名陣列: ra[i]: 第 i 個後綴的比較值 (排名，從 0 開始)
        從後綴陣列來看，具有以下性質:
            1. LCP(i, j) = LCP(j, i)
            2. LCP(i, i) = n - i
        又可得出，LCP Lemma:
            LCP(i, j) = min{LCP(i, j), LCP(j, k) | 0<=i<j<k<n}
        進而證明，LCP Theorem:
            LCP(i, j) = min{LCP(k-1, k) | i+1<=k<=j}
        再定義:
            高度陣列: height[i] = LCP(i-1, i) (相當於後綴樹形式中，(i, i-1) 的 LCA 深度)
            h[i] = height[ra[i]]
        因此 LCP Theorem 可轉化為:
            LCP(i, j) = min{height[k] | i+1<=k<=j} -- RMQ problem
        而且可證明:
            h[i] >= h[i-1] - 1 >= 0, i>1 and ra[i] > 1
        結論:
            可以在 O(n) 時間內順向算出 h[]，也就是計算出 height[]；
            在這樣的預處理之後，就能結合 RMQ 方法求出任意兩後綴的 LCP
        Note: 證明見: 国家集训队2004论文集_许智磊(后缀数组)
    I: O(L * log L)
    II: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &sa, vector<int> &ra) {
    int n = sa.size();
    //vector<int> tm(N), count(N, 0);
    int tm[n], count[n] = {0};
    for(int i=0; i<n; ++i) ++count[ra[sa[i]]];
    for(int i=1; i<n; ++i) count[i] += count[i-1];
    for(int i=n-1; i>=0; --i) tm[--count[ra[sa[i]]]] = sa[i];
    for(int i=0; i<n; ++i) sa[i] = tm[i];
}
void get_suffix(string &s, vector<int> &sa) {
    int n = s.size();
    // 後綴陣列: sa[i]: 順序第 i 的是第幾個後綴
    // 排名陣列: ra[i]: 第 i 個後綴的比較值 (排名，從 0 開始)
    // 第 i 個後綴的首字元是 s[i]
    vector<int> ra(n);
    vector<pair<char, int> > tmp(n);

    // 先對首個字元進行 ra 排序
    for(int i=0; i<n; ++i) {
        tmp[i] = {s[i], i};
    }
    sort(tmp.begin(), tmp.end());
    // 2^0
    for(int i=0; i<n; ++i) sa[i] = tmp[i].second; // 紀錄是第幾個後綴
    ra[sa[0]] = 0; 
    // 編 ra 號
    for(int i=1; i<n; ++i) {
        if(tmp[i].first == tmp[i-1].first)
            ra[sa[i]] = ra[sa[i-1]];
        else ra[sa[i]] = ra[sa[i-1]] + 1;
    }

    vector<int> new_rank(n);
    // 倍增法
    for(int k=0; 1<<k<=n; ++k) {
        //cout << "sa:\nBefore:\n";
        for(int i=0; i<n; ++i) {
            /* 
                重點:
                    因為字典排序的重要性，左邊的字元大於右邊的，因此
                        sa[i] = (sa[i] - (1<<k) + n ) % n;
                    代表原先 sa[i] "繼承" 了後來的 (左移 2^k) sa[i] 的順序。
                    舉例:
                        k=0        k=1         k=2
                        aabbaa$    aabbaa$     aabbaa$
                        6 $        6 $a        6 $aabb
                        0 a        5 a$        5 a$aa
                        1 a        0 aa        4 aa$a
                        4 a        4 aa        0 aabb
                        5 a        1 ab        1 abba
                        2 b        3 ba        3 baa$
                        3 b        2 bb        2 bbaa
                        原先的 sa[] = {6, 0, 1, 4, 5, 2, 3} 將轉變為 {5, 6, 0, 3, 4, 1, 2}
                        分別代表 {a'$', $'a', a'a', ... }，即:
                            1. 後來的 '$'(6) 繼承了 a(5)
                            2. 後來的 'a'(0) 繼承了 $(6) ...
                    簡而言之，左移之後代表的是新的 "最左端字元"，也就是最重要的字元，而在左移之前
                    的字元的功用變成決定進入箱子 (radix sort) 的順序，而會被分進哪個箱子則由左移
                    後的字元決定。
            */
            // 左移 2^k (往前跳)
            sa[i] = (sa[i] - (1<<k) + n ) % n;
        }
            
        counting_sort(sa, ra);
        new_rank[sa[0]] = 0;
        // 以 2^(k+1) 的長度 (代表已倍增) 為單位更新 ra
        for(int i=1; i<n; ++i) {
            pair<int, int> pre = {ra[sa[i-1]], ra[(sa[i-1]+(1<<k))%n]};
            pair<int, int> now = {ra[sa[i]], ra[(sa[i]+(1<<k))%n]};
            // 是否原先與後來 (倍增後) 的 ra 皆與前一 sa[] 一樣
            new_rank[sa[i]] = new_rank[sa[i-1]] + (pre != now);
            /*
                舉例:
                    k=1                               k=1
                    aabbaa$    對應Rank               aabbaa$    對應Rank
                    6 $a        0 1                   6 $a        0 1
                    0 aa        1 1                   5 a$        1 0
                    1 ab        1 2         排序Rank   0 aa        1 1
                    4 aa        1 1         =======>  4 aa        1 1
                    5 a$        1 0                   1 ab        1 2
                    2 bb        2 2                   3 ba        2 1
                    3 ba        2 1                   2 bb        2 2
            */
        }
        ra = new_rank;
    }
}
void LCP(string &s, vector<int> &ra, vector<int> &sa, vector<int> &height) {
    int n = s.size();
    //for(int i=0; i<n; ++i) ra[sa[i]] = i;
    int h = 0; // 相當於 h[i-1] (h[i] = height[ra[i]])
    height[0] = 0;
    for(int i=0; i<n; ++i) {
        // 第 i-1 小的後綴
        int j = sa[ra[i]-1];
        // h[i] >= h[i-1]-1 >= 0
        if(h > 0) --h;
        // 繼續往後比較
        for(; j+h<n && i+h<n; ++h) {
            if(s[j+h] != s[i+h]) break;
        }
        // 更新
        height[ra[i]] = h;
    }
}
int main() {
    string s = "mississippi";
    s += '\0'; // 必要 !!! ('\0' 的字典序小於任一字元)
    int n = s.size();
    vector<int> sa(n), ra(n), height(n);
    get_suffix(s, sa);
    
    // 計算 height[]
    LCP(s, ra, sa, height); 

    for(auto v : sa) cout << setw(2) << v << ": " << s.substr(v)+'\n';
    cout << "----------------------\n";
    for(int i=0; i<n; ++i)
        cout << setw(2) << i << ": " << height[i] << '\n';
    return 0;
}