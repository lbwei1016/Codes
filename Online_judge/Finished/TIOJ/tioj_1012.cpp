/*
***Stack***
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    vector<int> a, rep, sta; // stack
    for(int i=1; i<=n; ++i) {
        int t; scanf("%d", &t);
        a.push_back(t);
    }
    sta.push_back(0); rep.push_back(0);
    int end = n;
    while(!a.empty()) {
        int x = a.back(); a.pop_back();
        while(sta.back() > x) {
            int tmp = sta.back(); sta.pop_back();
            rep.push_back(tmp);
            if(rep.size()-1 > m) {
                puts("no"); return 0;
            }
        }
        sta.push_back(x);
        while(rep.back() > sta.back()) {
            sta.push_back(rep.back()); rep.pop_back();
        }
        while(sta.back() == end) {
            sta.pop_back(); --end;
        }
        while(rep.back() == end) {
            rep.pop_back(); --end;
        }
    }
    puts("yes");
    return 0;
}