/*
***Data*** --unordered_map
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000+2;
string s[MAX_N];
unordered_map<string, int> S;
int M, N;
int res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i=0; i<N; i++) {
        cin >> s[i];
    }
    for(int i=0; i<M; i++) {
        if(!S.count(s[i])) S[s[i]] = 1;
        else S[s[i]]++;
    }
    if(S.size() == M) res++;
    for(int i=0; i<N-M; i++) {
        if(--S[s[i]] == 0) S.erase(s[i]);
        if(!S.count(s[M+i])) S[s[M+i]] = 1;
        else S[s[M+i]]++;
        if(S.size() == M) res++;
    }
    cout << res << '\n';
    return 0;
}