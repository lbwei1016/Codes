/*
***String*** -- Z algorithm
    Description:
        判斷兩字串是否恰相差一個字元，其中一字串為環狀 (首 n-1 字元可移至字串尾)
    Solution:
        令 A=aabaab, B=aaaaab，他們只差 1 個字元，且將 A 拆成三段來看：
            A = aa + b + aab
        第一段和第三段是成功匹配的字串，第二段只有單一字元：匹配失敗的字元。
        這就顯示了，字串長度等於：「A, B 的最長共同前綴長度 + rev(A), rev(B) 的
        最長共同前綴長度 + 1」(rev: reverse) 因此，分別求出正、反的 Z 函數再判斷
        是否符合即可。
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+2;
int n, cnt;
int Z[3*N], rZ[3*N];
string s1, s2;
vector<int> res;

void getZ(string &s, int *z) {
    z[0] = 0;
    int bst = 0;
    for(int i=1, l=s.size(); i<l; ++i) {
        if(bst+z[bst] <= i) z[i] = 0;
        else z[i] = min(z[bst]+bst-i, z[i-bst]);

        while(i+z[i]<l && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i+z[i] > bst+z[bst]) bst = i;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s1 >> s2;
    s1 = s2 + '@' + s1 + s1; // B@AA
    getZ(s1, Z); // 正序列的 Z
    reverse(s1.begin(), s1.begin()+n);
    reverse(s1.begin()+n+1, s1.end());
    getZ(s1, rZ); // 反序列的 Z
    for(int i=n+1; i<=2*n; ++i) {
        // (把序列寫下來對照所得出)
        if(Z[i]+rZ[2*n-(i-n-1)+1]+1 == n)
            res.push_back(i-n-1);
    }
    if(res.empty()) puts("NIE");
    else {
        puts("TAK");
        for(auto v : res) printf("%d ", v);
        puts("");
    }
    return 0;
}