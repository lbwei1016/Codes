// WA
#include <bits/stdc++.h>
using namespace std;

struct P { string to, a, b, c, d; };
int m, cnt;
unordered_map<string, vector<P> > mp;
//unordered_map<string, bool> vis;
unordered_set<string> vis;
//fstream ff("t.out", ios::out);

bool cmp(P p, P q) {
    if(q.a!="*" && p.a!=q.a) return false;
    if(q.b!="*" && p.b!=q.b) return false;
    if(q.c!="*" && p.c!=q.c) return false;
    if(q.d!="*" && p.d!=q.d) return false;
    return true;
}
void route(P p) {
    string to = p.to;
    auto it = mp.find(to);
    while(it != mp.end()) {
        vis.insert(to);
        bool R = false;
        for(auto v : it->second) {
            if(cmp(p, v)) {
                if(to == v.to) {
                    cout << ++cnt << " -- delivered to " + to + '\n';
                    return;
                }
                if(vis.count(v.to)) {
                    cout << ++cnt << " -- circular routing detected by " + v.to + '\n';
                    return;
                }
                it = mp.find(v.to);
                if(it != mp.end()) {
                    to = v.to; R = true;
                }
                break;
            }
        }
        if(!R) {
            cout << ++cnt << " -- unable to route at " + to + '\n';
            return;
        }
    } 
}
int main() {
    string mta; 
    int n, sce = 0; 
    P p;
    while(cin >> m) {
        mp.clear(); vis.clear(); cnt = 0;
        while(m--) {
            cin >> mta >> n;
            //vis[mta] = false;
            while(n--) {
                cin >> p.to >> p.a >> p.b >> p.c >> p.d;
                mp[mta].push_back(p);
            }
        }
        cin >> n;
        cout << "Scenario # " << ++sce << '\n';
        while(n--) {
            cin >> p.to >> p.a >> p.b >> p.c >> p.d;
            //for(auto &v : vis) v.second = false;
            vis.clear();
            route(p);
        }
        cout << '\n';
    }
    //ff.close();
    return 0;
}