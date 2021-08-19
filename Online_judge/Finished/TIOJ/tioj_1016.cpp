#include <bits/stdc++.h>
using namespace std;

struct TEAM { 
    int sc, out; int base[4]; 
    void clear() {
        out = 0;
        memset(base, 0, sizeof(base));
    }
};

int game(const string &s, int i, TEAM &T) {
    for(int l=s.size(); T.out<3 && i<l; ++i) {
        if(s[i] == 'K' || s[i] == 'O') ++T.out;
        else if(s[i] == 'H') {
            for(int k=0; k<3; ++k) 
                if(T.base[k]) {
                    T.base[k] = 0; ++T.sc;
                }
            ++T.sc; 
        }
        else if(s[i] == 'W') {
            int k;
            for(k=0; k<4; ++k) if(!T.base[k]) break;
            ++T.base[k];
        }
        else if(s[i] == 'S') {
            for(int k=3; k>0; --k) {
                if(T.base[k-1]) {
                    ++T.base[k]; T.base[k-1] = 0;
                }
            }
            T.base[0] = 1;
        }
        else if(s[i] == 'D') {
            if(T.base[2]) {
                T.base[2] = 0; ++T.sc;
            }
            if(T.base[1]) {
                T.base[1] = 0; ++T.sc;
            }
            if(T.base[0]) {
                T.base[0] = 0; T.base[2] = 1;
            }
            T.base[1] = 1;
        }
        else { // Three-base hit
            for(int k=0; k<3; ++k) {
                if(T.base[k]) {
                    T.base[k] = 0; ++T.sc;
                }
            }
            T.base[2] = 1;
        }

        if(T.base[3]) {
            T.sc += T.base[3]; T.base[3] = 0;
        }
    }
    T.clear();
    return i;
}
int main() {
    string s;
    TEAM A, B;
    while(cin >> s) {
        A.clear(), B.clear();
        A.sc = B.sc = 0;
        for(int i=0, l=s.size(), j=1; i<l; ++j) {
            if(j & 1) i = game(s, i, A);
            else i = game(s, i, B);
        }
        cout << A.sc << ' ' << B.sc << '\n';
    }

    return 0;
}