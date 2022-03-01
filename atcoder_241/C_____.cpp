#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
string G[N];

bool calc(vector<int> &R) {
    int cnt = 0, coda = 2;
    for (auto x: R) {
        if (x < 0 && cnt == 0) continue;
        if (x < -2) cnt = 0, coda = 2;
        else if (x < 0) {
            if (coda >= -x) {
                cnt += -x;
                coda += x;   
            }
            else cnt = 0, coda = 2;
        }
        else cnt += x;

        if (cnt >= 6) return true;
    }
    return false;
}

bool check() {
    vector<int> R;
    for (int i=0; i<n; ++i) {
        R.clear();
        for (int j=0; j<n; ++j) {
            int cnt = 0;
            while (j<n && G[i][j] == '.') {
                ++cnt; ++j;
            }
            if (cnt > 0) {
                R.push_back(-cnt);
                --j;      
                continue;   
            } 
            while (j<n && G[i][j]=='#') {
                ++cnt; ++j;
            }
            R.push_back(cnt);
            --j;
        }
        if (calc(R)) return true;
    }

    // vector<int> R;
    for (int j=0; j<n; ++j) {
        R.clear();
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            while (i<n && G[i][j] == '.') {
                ++cnt; ++i;
            }
            if (cnt > 0) {
                R.push_back(-cnt);
                --i;      
                continue;   
            } 
            while (i<n && G[i][j]=='#') {
                ++cnt; ++i;
            }
            R.push_back(cnt);
            --i;
        }
        if (calc(R)) return true;
    }

    // vector<int> R;
    for (int i=0; i<n; ++i) {
        R.clear();
        for (int j=0; j<n; ++j) {
            int cnt = 0;
            while (j<n && G[i][j] == '.') {
                ++cnt; ++j;
                ++i;
            }
            if (cnt > 0) {
                R.push_back(-cnt);
                --j;      
                continue;   
            } 
            while (j<n && G[i][j]=='#') {
                ++cnt; ++j;
                ++i;
            }
            R.push_back(cnt);
            --j;
        }
        if (calc(R)) return true;
    }

    for (int j=0; j<n; ++j) {
        R.clear();
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            while (i<n && G[i][j] == '.') {
                ++cnt; ++j;
                ++i;
            }
            if (cnt > 0) {
                R.push_back(-cnt);
                --i;      
                continue;   
            } 
            while (i<n && G[i][j]=='#') {
                ++cnt; ++j;
                ++i;
            }
            R.push_back(cnt);
            --i;
        }
        if (calc(R)) return true;
    }
    // reverse-diagonal
    for (int i=0, l=0; l<n; ++l, i=0) {
        R.clear();
        for (int j=n-1-l; j>=0; --j) {
            int cnt = 0;
            while (j>=0 && G[i][j] == '.') {
                ++cnt; --j;
                ++i;
            }
            if (cnt > 0) {
                R.push_back(-cnt);
                ++j;      
                continue;   
            } 
            while (j>=0 && G[i][j]=='#') {
                ++cnt; --j;
                ++i;
            }
            R.push_back(cnt);
            ++j;
        }
        if (calc(R)) return true;
    }

    for (int j=0; j<n; ++j) {
        R.clear();
        for (int i=n-1; i>=0; --i) {
            int cnt = 0;
            while (i>=0 && G[i][j] == '.') {
                ++cnt; ++j;
                --i;
            }
            if (cnt > 0) {
                R.push_back(-cnt);
                ++i;      
                continue;   
            } 
            while (i>=0 && G[i][j]=='#') {
                ++cnt; ++j;
                --i;
            }
            R.push_back(cnt);
            ++i;
        }
        if (calc(R)) return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i=0; i<n; ++i) cin >> G[i];
    if (check()) puts("Yes");
    else puts("No");
    return 0;
}