#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct Pr {
    int ty, val;
};

int n, k; 
int cnt;

int main() {
    scanf("%d %d", &n, &k);
    vector<Pr> P(n+1);
    for (int i=1; i<=n; ++i) {
        // string s; 
        char s[30];
        char c;
        // cin >> s >> x;
        scanf("%s %c", s, &c);
        if (s[0] == 'e') {
            P[i] = {0, int(c)};
        }
        else {
            P[i] = {1, c - '0'};
        }
    }

    queue<Pr> que;
    for (int i=1; i<=n; ++i) que.push(P[i]);

    for (int i=1; i<=k; ++i) {
        auto p = que.front(); que.pop();
        if (p.ty == 0) printf("%c", p.val);
        else {
            for (int j=1; j<=p.val && que.size() < k-i; ++j) {
                que.push(P[j]);
            }
        }
    }

    return 0;
}
/*
abaabaaabaaaabaaaaab
abaabaaabaaaabaaaaab
abaabaaabaaaabaaaaab

abaababaaababaababaaaa
abaababaaababaababaaaa
abaababaaababaababaaaa

abaaaaaaaa
abaaaaaaaa
*/