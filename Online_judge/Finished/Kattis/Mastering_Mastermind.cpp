#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r = 0, s = 0;
    string code, gues;
    cin >> n >> code >> gues;
    for(int i=0; i<n; ++i) {
        if(code[i] == gues[i]) {
            ++r;
            code[i] = '#';
            gues[i] = '$';
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(i == j) continue;
            if(code[i] == gues[j]) {
                ++s;
                gues[j] = '*';
                break;
            }
        }
    }
    cout << r << ' ' << s << '\n';
    return 0;
}