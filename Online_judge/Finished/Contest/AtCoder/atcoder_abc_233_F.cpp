/*
***Segement Tree***
    Solution:
        用線段樹做區間修改和單點查詢，最後再以大數運算進位上去。
    Note:
        大數運算別再用 string 了!!!
    O(M logN)
*/
#include <bits/stdc++.h>
using namespace std;
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)

string X;
struct P {
    int val, tag;
} seg[1<<20];

void pull(int v) {
    if (seg[v].tag) {
        seg[LC(v)].tag += seg[v].tag;
        seg[RC(v)].tag += seg[v].tag;
        seg[v].tag = 0;
    }
}
void update(int v, int l, int r, int ul, int ur, int val) {
    if (ul<=l && r<=ur) {
        seg[v].tag += val;
        return;
    }    
    pull(v);
    int mid = (l+r) >> 1;
    if (ur <= mid) 
        update(LC(v), l, mid, ul, ur, val);
    else if (ul >= mid)
        update(RC(v), mid, r, ul, ur, val);
    else {
        update(LC(v), l, mid, ul, ur, val);
        update(RC(v), mid, r, ul, ur, val);
    }
}
int query(int v, int l, int r, int qv) {
    if (r-l == 1) return seg[v].tag;
    pull(v);
    int mid = (l+r) >> 1;
    if (qv < mid) return query(LC(v), l, mid, qv);
    else return query(RC(v), mid, r, qv);
}

int main() {
    cin >> X;
    int len = X.size();
    for (int i=0; i<len; ++i) {
        update(0, 0, len, 0, len-i, X[i]-'0');
    }
    vector<int> res(len+1);
    for (int i=0; i<len; ++i) {
        int val = query(0, 0, len, i);
        res[i] += val % 10;
        int car = res[i] / 10;
        res[i] %= 10;
        res[i+1] = (val / 10) + car;
    }
    int at = len;
    while (res[at] > 10) {
        res.push_back(res[at]/10);
        res[at] %= 10;
        ++at;
    }
    reverse(res.begin(), res.end());
    at = 0;
    while (res[at] == 0) ++at;
    len = res.size();
    for (int i=at; i<len; ++i) {
        cout << res[i];
    }
    return 0;
}