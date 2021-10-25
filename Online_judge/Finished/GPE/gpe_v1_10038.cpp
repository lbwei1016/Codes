/*
***Tree***
    Description:
        Build a dynamic tree.
    Note:
        Range-based for loop (for(auto x:k)) isn't accepted, neither is "auto".
*/
#include <bits/stdc++.h>
using namespace std;

struct Tree {
    string s;
    vector<Tree*> chl;
    Tree(string s_) {
        s = s_;
    }
};
map<string, Tree*> mp; // record the roots

void add(Tree* t, int k, int j, string dir[]) {
    if(k >= j) return;
    for(int i=0, l=t->chl.size(); i<l; ++i) {
        Tree* x = t->chl[i];
        // if such directory has existed
        if(x->s == dir[k]) {
            add(x, k+1, j, dir);
            return;
        }
    }
    Tree* chl = new Tree(dir[k]);
    t->chl.push_back(chl);
    add(chl, k+1, j, dir);
}

bool cmp(const Tree* tp1, const Tree* tp2) {
    return tp1->s < tp2->s;
}

void dfs(Tree* t, int d) {
    if(t->chl.empty()) return;
    sort(t->chl.begin(), t->chl.end(), cmp);
    for(int i=0, l=t->chl.size(); i<l; ++i) {
        Tree* chl = t->chl[i];
        for(int i=0; i<d; ++i) cout << ' ';
        cout << chl->s << '\n';
        dfs(chl, d+1);
    }
}

int main() {
    int n;
    string s, dir[100];
    cin >> n;
    for(int i=0, j=0; i<n; ++i) {
        cin >> s;
        s += "\\"; // for convenience
        j = 0;
        for(int l=s.size(), k=0; k<l; ++j) {
            int tmp = s.find('\\', k); // search from "k-th" char for '\'
            dir[j] = s.substr(k, tmp-k); // start for pos "k", containing "tmp-k" chars
            k = tmp+1;
        }
        if(!mp.count(dir[0])) {
            mp.insert(make_pair(dir[0], new Tree(dir[0])));
        }
        add(mp[dir[0]], 1, j, dir);
    }
    map<string, Tree*>::iterator it;
    for(it=mp.begin(); it!=mp.end(); ++it) {
        pair<string, Tree*> x = *it;
        cout << x.first << '\n';
        sort(x.second->chl.begin(), x.second->chl.end(), cmp);
        dfs(x.second, 1); // to print
    }
    return 0;
}