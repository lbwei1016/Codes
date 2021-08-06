/*
***Graph*** -- Maximum Independent Set
    Solution:
        若 T 是我們要處理的樹，樹一定有葉，假設 v 是一個葉。我們宣稱：一定有一個最大獨
        立集挑選了 v 而沒有挑選 parent(v)。證明：假設某最大獨立集 S 沒有挑選 v，那麼
        一定有挑 parent(v)，否則可以將 v 加入 S 中變成更大的獨立集。我們可以用 v 點取
        代 S 中的 parent(v)得到另外一個獨立集 S’，就是我們宣稱包含 v 的最大獨立集。
        這樣的替換不可能造成不合法的解，因為 v 點是葉子，parent(v)是它唯一的鄰居。
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
int p[N], chosen[N];
vector<int> chl[N];

int dfs(int v) {
    int num = 0;
    for(int u : chl[v]) {
        num += dfs(u);
    }
    //從葉開始挑選，並將其 parent 取消挑選
    if(chosen[v]) {
        num += 1;
        chosen[p[v]] = 0;
    }
    return num;
}
int main() {
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d", &p[i]);
        chl[p[i]].push_back(i);
        chosen[i] = 1; //預設皆選
    }
    chosen[0] = 1; p[0] = n; //0 的 parent 設為一不可能之值
    printf("%d\n", dfs(0));
    return 0;
}