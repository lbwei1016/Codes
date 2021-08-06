/*
***Divide and Conquer***

    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> v;
unordered_set<int> st;

int seg(int l, int r) {
    if(r-l < m) return 0;
    int mid = (l+r) / 2;
    int div = seg(l, mid) + seg(mid+1, r);

    st.clear();
    st.insert(v[mid]);
    int cross = 0, j;
    //先往右搜尋到底
    for(j=mid+1; j<r; j++) {
        if(st.count(v[j])) break;
        st.insert(v[j]);
    }
    j--;
    //再從中間往左擴展
    for(int i=mid-1; i>=l; i--) {
        while(j>mid && st.count(v[i])) {
            st.erase(v[j--]);
        }
        if(st.count(v[i])) break;
        st.insert(v[i]);
        if(st.size() == m) cross++;
    }     
    return cross + div;
}
int main() {
    scanf("%d%d", &m, &n);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    printf("%d\n", seg(0, n));
    return 0;
}