#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct S {
    ll f, id; string name;
    bool operator <(const S &s1) const {
        return f * id > s1.f * s1.id;
    }
};

int main() {
    int n, m;
    vector<S> song;
    cin >> n >> m;
    song.resize(n);
    for(int i=0; i<n; ++i) {
        song[i].id = i+1;
        cin >> song[i].f >> song[i].name;
    }
    stable_sort(song.begin(), song.end());
    for(int i=0; i<m; ++i) {
        cout << song[i].name << '\n';
    }
    return 0;
}