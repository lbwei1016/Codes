/*
***String*** --  Gusfield’s Algorithm, a.k.a "Z algorithm"
    Description:
        定義 Z(i)：
            一個子字串的某個後綴可以和字串本身匹配到多長，除了 Z(0) = 0。亦即：
                Z(i) = 最大的 p 滿足 S[i:i+p) = S[0:p)。
        Z(i) 的意義：
            設計此函數的緣由，是因為進行字串搜尋的時候，我們總是希望兩字串的
            開頭盡可能長得一樣。
        實作：
            要進行字串匹配的話，只要令字串　C = pattern (B) + $ + text (A)，其中 $ 是一個從
            未在 text, pattern 中出現過的字元，然後看是否存在 0 <= k < LA 使得 
            Zc(LB + 1 + k) = LB 就可以了。
            （事實上，若將 pattern 的 Z 函數與 text 的 Z 函數分開計算就不必宣告新的串接兩者的字串 C）
    O(La + Lb)
        Li: i 字串長度
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const int MAX_C = 100;
int match(const string, const string);
int match_2(const string, const string);

int main() {
    string text, pattern;
    while(cin >> text >> pattern) {
        int res = match_2(text, pattern);
        if(res == -1) cout << "Matching Failed!!\n";
        else {
            cout << res << '\n';
            int st = res-pattern.size()-1;
            cout << "Matched!!\n" + text.substr(st, pattern.size()) + '\n';
        }
    }
    return 0;
}

int match(const string text, const string pattern) {
    int Z[MAX_C] = {0}; // 「Z 函數」

    // 中間的 '@' 可替換為任意未在 text, pattern 中出現的字元
    // 另外，實作時未必真的要將 text, pattern 串接起來
    string C = pattern + '@' + text; 

    int l = 0, pos; // l < i 使得 l + Z(l) 最大
    for(int i=1; i<C.size(); ++i) {
        int ii = i - l; // 映射、平移
        // 之前匹配的結果無法涵蓋到 i 
        if(l+Z[l] <= i) {
            pos = i;
            // 重頭從 pattern[0] 開始匹配
            while(pos < C.size() && C[pos] == C[pos-i]) ++pos;
            Z[i] = pos - i;
        }
        else if(l+Z[l] > i+Z[ii]) { 
            // 完全涵蓋
            Z[i] = Z[ii];
        } 
        else if(l+Z[l] == i+Z[ii]) { 
            // 之前匹配的結果與 i 恰在同一位置
            pos = i + Z[ii];
            // 繼續往下匹配
            while(pos < C.size() && C[pos] == C[pos-i]) ++pos;
            Z[i] = pos - i;
        }
        else { 
            // 不完全涵蓋
            Z[i] = Z[l] - ii;
        }
        
        if(i + Z[i] > l + Z[l]) { 
            // 更新： l < i 使得 l + Z(l) 最大
            l = i;
        }
        if(Z[i] == pattern.size()) return i;
    }
    return -1;
}
// 更精簡的寫法
int match_2(const string text, const string pattern) {
    int Z[MAX_C]; // 「Z 函數」

    // 中間的 '@' 可替換為任意未在 text, pattern 中出現的字元
    // 另外，實作時未必真的要將 text, pattern 串接起來
    string C = pattern + '@' + text;
    Z[0] = 0; // Z(0) 無意義
    int bst = 0; // 最大的 bst + Z[bst]
    // 必須從 i = 1 開始
    for(int i=1; i<C.size(); ++i) {
        int rb = bst + Z[bst]; // right-most bound
        if(rb <= i) Z[i] = 0;
        else Z[i] = min(rb - i, Z[i - bst]); // 畫圖看看！
        /*
            std::string 在存取 s[s.length()] 時，
            會回傳 "a reference to the null character"，因此這裡不需要邊界檢查，
            但再超過就是 "undefined behavior"
        */
        while(C[Z[i]] == C[i + Z[i]]) ++Z[i]; // 對於未知情形繼續往後匹配
        if(i + Z[i] > rb) bst = i; // 更新
        
        if(Z[i] == pattern.size()) return i;
    }
    return -1;
}