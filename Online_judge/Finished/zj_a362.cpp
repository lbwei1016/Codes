#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10000+1;

struct sta { int num, h, w; };

int n;
vector<sta> v;

bool comp(const sta &a, const sta &b) {
    if(a.h != b.h) return a.h < b.h;
    if(a.w != b.w) return a.w < b.w;
    return a.num < b.num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        int h, w;
        cin >> h >> w;
        v[i] = (sta){i, h, w};
    }

    //Equivalent elements are not guaranteed to keep their original relative order (see stable_sort).
    sort(v.begin()+1, v.end(), comp);

    long res = 0;
    for(int i=1; i<=n; i++) {
        res += abs(v[i].num - i);
    }
    cout << res << '\n';

    return 0;
}