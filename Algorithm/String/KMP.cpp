/*
***String*** -- Knuth-Morris-Pratt Algorithm
    Description:
        定義 F(i) --「失敗函數」（failure function）：
            從字串 S 中的 i 位置往前延伸，最多可以往前幾個字元(< i) 使得往前
            所包含的子字串 (含自己) 是 S 的前綴。亦即：
                F(i) = 最大的 p 滿足 S[i-p+1:i] = S[0:p-1] 且 F(i)<i
        F(i) 的意義：
            F(i) 意味著，以 i 為結尾的，在原字串 S 中的最大重複區段，
            而該區段是以 S 的首字元開始，為的就是要在字串匹配時，不必每次都從頭
            開始匹配，只需要跳至 F(i) 處繼續往下匹配即可
    O(La + Lb)
        Li: i 字串長度
*/
#include <iostream>
#include <string>
using namespace std;

const int MAX_B = 100;
int match(const string A, const string B) {
    // Note: 以下編號，F() 是從 1 開始，0 是邊界，而字串則是從 0 開始
    int F[MAX_B+1]; // failure function
    F[0] = -1; // 邊界
    F[1] = 0; // B 的第一個字元的「失敗函數」（failure function）
    // 找出 failure function (自己和自己匹配)
    for(int i=1, j=0; i<B.size(); F[++i] = ++j) {
        // 若字元相同，直接 ++i, ++j，否則跳至 F(i) 處繼續往下匹配即可
        while(j != -1 && B[i] != B[j]) 
            j = F[j];
    }
    for(int i=0, j=0; i-j+B.size()<=A.size(); ++i, ++j) {
        // 若字元相同，直接 ++i, ++j，否則跳至 F(i) 處繼續往下匹配即可
        while(j != -1 && A[i] != B[j]) 
            j = F[j];
        if(j == B.size()-1) 
            return i - j; // 當完成匹配，回傳 A 的子字串中等於 B 的起始位置
    }
    return -1;
}
int main() {
    string A, B;
    cin >> A >> B;
    int res = match(A, B);
    if(res == -1) cout << "Matching failed !!";
    else {
        cout << "Matched:\nFrom: " << res << '\n'; 
        cout << A.substr(res, B.size()); 
    }
    return 0;
}