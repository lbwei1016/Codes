/*
***String*** -- Mathcing (KMP)
*/
#include <bits/stdc++.h>
using namespace std;

int n, q;
string T, P;

int match(const string &A, const string &B) {
    int F[10005] = {0}, cnt = 0;
    int la = A.size(), lb = B.size();
    F[0] = -1;
    for(int i=1, j=0; i<lb; F[++i] = ++j) {
        while(j != -1 && B[i] != B[j])
            j = F[j];
    }
    for(int i=0, j=0; i-j+lb<=la; ++i, ++j) {
        while(j != -1 && A[i] != B[j])
            j = F[j];
        if(j == lb-1) {
            ++cnt;
            i -= lb-1; // 子字串可能重疊，因此 A 某些部份可能需要重複判斷
            j = -1;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--) {
        cin >> T >> q;
        while(q--) {
            cin >> P;
            cout << match(T, P) << '\n';
        }
    }
    return 0;
}