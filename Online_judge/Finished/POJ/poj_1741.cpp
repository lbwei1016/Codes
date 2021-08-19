/*
***Tree / Divide and Conquer*** -- tree centroid (*)
    Description:
        計算點對 (u, v) 的數量，使 u 到 v 的距離不大於 K
    Solution:
        在以 r 為根的樹中，(u, v) 的路徑有兩種可能:
            1.  經過 r
            2.  沒有經過 r
        若沒有經過 r，那麼該路徑必定經過其他子樹的根，因此不必理會，
        只需要處理第一種情形。

        要求出各點間經過 r 的距離，就以 r 為根 DFS，並記錄深度，深度
        和即為距離。將距離求出並紀錄後，排序距離陣列，使其具單調性，就
        可以在 O(n) (two pointer) 驗證是否 <= K。

        為了確保子樹的規模夠小，上述的樹根 r 必須是該樹的重心；因此每
        一棵子樹都必須要找一次重心，再以重心向下分治。如此一來，由於重心
        的性質 -- 子樹不大於 n/2 --，可以確保分治深度為 O(logn)。

        排序 + 分治: O(n logn) * O(logn) = O(n (logn)^2)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
using namespace std;

const int N = 10005;
struct P { int to, w; };
int n, K, size[N]; // size[v]: v 的子樹大小 (含 v)
vector<P> G[N];
vector<int> dis; // 到重心的距離
bitset<N> vis; // vis[v]: 是否以 v 為重心拜訪過

void init() {
    for(int i=0; i<N; ++i) G[i].clear();
    vis.reset();
}
// 求到重心的距離
void get_dis(int v, int p, int d) {
    dis.push_back(d);
    for(int i=0, s=G[v].size(); i<s; ++i) {
        int u = G[v][i].to, w = G[v][i].w;
        if(u==p || vis[u]) continue;
        get_dis(u, v, d+w);
    }
}
// 算好距離之後，計算符合距離 < K 的量
int calc(int v, int d) {
    dis.clear();  
    get_dis(v, 0, d);
    sort(dis.begin(), dis.end()); // dis[0] = d，代表由重心與其他任一點組成的點對
    int res = 0;
    // dis sort 完具單調性，可以 two pointer O(n)
    for(int l=0, r=dis.size()-1; l<r; ++l) {
        while(l<r && dis[l]+dis[r]>K) --r;
        res += r - l;
    }
    return res;
}
// first: 以重心為根的最大子樹大小；second: 重心
// sz: 要找重心的樹總共有多少節點
pair<int, int> get_cent(int v, int p, int sz) {
    size[v] = 1;
    int mx = 0;
    pair<int, int> res(1e9, -1);
    for(int i=0, s=G[v].size(); i<s; ++i) {
        int u = G[v][i].to, w = G[v][i].w;
        if(u==p || vis[u]) continue;
        res = min(res, get_cent(u, v, sz));
        size[v] += size[u];
        mx = max(mx, size[u]);
    }
    mx = max(mx, sz-size[v]);
    return min(res, make_pair(mx, v));
}
// 樹分治，每遞迴到一個子樹就先找重心
int tree_dac(int v, int sz) {
    int cent = get_cent(v, 0, sz).second; // centroid
    int res = calc(cent, 0);
    vis[cent] = 1;
    for(int i=0, s=G[cent].size(); i<s; ++i) {
        int u = G[cent][i].to, w = G[cent][i].w;
        if(vis[u]) continue;
        // 扣掉在同一子樹的路徑 (走了重複的邊，為了必經過 cent)
        res -= calc(u, w); 
        // 找重心時，u 可能是 cent 的祖先，但此時 u 必須變成 cent 的子樹
        if(size[u] > size[cent]) size[u] = sz-size[cent];
        res += tree_dac(u, size[u]);    
    }
    return res;
}
int main() {
    while(scanf("%d%d", &n, &K) == 2) {
        if(!n) break;
        init();
        for(int i=0; i<n-1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(P{v, w});
            G[v].push_back(P{u, w});
        }
        printf("%d\n", tree_dac(1, n));
    }
    return 0;
}
/*
test cases:
5 4
1 2 3
1 3 1
1 4 2
3 5 1
7 4
1 2 3
1 3 1
1 4 2
3 5 1
3 6 2
3 7 3
*/