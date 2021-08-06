/*
***"Fake" Segment Tree*** (見演算法筆記: http://web.ntnu.edu.tw/~algo/Sequence2.html#3)
    Solution:
        因為題目所給的 N 並不保證為 2 的冪次，亦即無法保證線段樹為
        完全二元樹，因此先找到 n = 2^p >= N，來建置完全二元樹

        再來，因為所求為最大值，所以將各節點最大值初始化為[-INF]
        
    O(M * log n)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500000;
const int INF = 1e9;
int N;
int T[MAX_N+5];
int node[2*2*MAX_N+5]; //[l, r]

void init() { //O(n)
    int n = 1;
    while (n < N) {
        n *= 2;
    }
    for (int i=1; i<=2*n-1; i++) {
        node[i] = -INF;
    }
}
void build(int k, int l, int r) { //O(log n)
    if (l == r) {
        node[k] = T[l];
        return;
    }

    int m = (l+r) / 2;
    build(2*k, l, m);
    build(2*k+1, m+1, r);

    node[k] = max(node[2*k], node[2*k+1]);
}
//k: no. of node；l, r: range of the node
int query(int a, int b, int k, int l, int r) { //O(log n)
    if (a > r || b < l) return -INF;
    if (a <= l && r <= b) return node[k];
    else {
        int m = (l+r) / 2;
        int v1 = query(a, b, 2*k, l, m);
        int v2 = query(a, b, 2*k+1, m+1, r);

        return max(v1, v2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> T[i];
    }

    init();
    build(1, 1, N);
    cin >> M;
    while (M--) { //O(M)
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int ans = query(a, b, 1, 1, N); 
        cout << ans << '\n';
    }
    return 0;
}