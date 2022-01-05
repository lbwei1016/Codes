#include <bits/stdc++.h>
using namespace std;

struct P { 
    int id; string s; 
    bool operator <(const P &p) const {
        return s < p.s;
    }
};
vector<string> seq; // attribute 順序
unordered_map<string, vector<P> > mp; 
int m, n, atts;

void print(const string &q, const vector<vector<string> > &all) {
    for(auto i : seq) cout << i << ' ';
    cout << '\n';
    for(auto x : mp[q]) {
        int id = x.id;
        for(auto y : all[id]) {
            cout << y << ' ';
        }
        cout << '\n';
    }
}
int main() {
    string att;
    getline(cin, att);
    att += ' ';
    for(int i=0, l=att.size(), pre=0; i<l; ++i) {
        if(att[i]==' ') {
            string tmp = att.substr(pre, i-pre);
            seq.push_back(tmp);
            mp[tmp] = vector<P>();
            pre = i+1;
            ++atts;
        }
    }
    cin >> m;
    vector<vector<string> > all(m, vector<string>(atts));
    for(int i=0; i<m; ++i) {
        for(int j=0; j<atts; ++j) {
            cin >> all[i][j];
        }
    }
    // 依 attribute 擺放
    for(int at=0; at<atts; ++at) {
        for(int i=0; i<m; ++i) {
            mp[seq[at]].push_back(P{i, all[i][at]});
        }
    }

    cin >> n;
    string query, pre = "";
    while(n--) {
        cin >> query;
        if(pre != "") {
            vector<P> tmp = mp[query];
            // 延續前一排序
            for(int i=0; i<m; ++i) {
                int id = mp[pre][i].id;
                mp[query][i] = tmp[id];
            }
        }
        stable_sort(mp[query].begin(), mp[query].end());
        print(query, all);
        pre = query;
        if(n > 1) cout << '\n';
    }
    return 0;
}

/*
Artist Album Song_Title Length_seconds
5
Tchaikovsky Summer Lullaby 215
James_Taylor Dad_Loves_His_Work Hard_Times 192
James_Taylor Dad_Loves_His_Work London_Town 236
James_Taylor Dad_Loves_His_Work Summers_Here 163
George_Winston Summer Lullaby 215
3
Artist
Album
Song_Title

*/