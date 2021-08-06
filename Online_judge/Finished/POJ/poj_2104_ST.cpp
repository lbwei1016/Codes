/*
***K-th Number*** --Range Tree
    Solution:
        Find out a specific number "x" where there are precisely
        "k" numbers whose value is no larger than "x", which is 
        the answer.

        Using segment tree whose node's values are sorted arrays
        (the tree itself looks like the process of "merge sort", 
        and this tree is also called "Range Tree"), we can find 
        out the "K-th number" within a given range.

        Another solution uses "bucket method" and "square root decomposition"

    O(n*logn + m*(logn)^3)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 100000+5;
const int MAX_M = 5000+5;
const int ST_SIZE = (1 << 18) - 1; //ST_SIZE > 2*(MAX_N) - 1
int n, m;
int A[MAX_N]; 
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; //sorted A[]
vector<int> dat[ST_SIZE];

//[l, r), node v；0-indexed
void init(int v, int l, int r) {
    if(r-1 == l)
        dat[v].push_back(A[l]);
    else {
        int lch = v * 2 + 1, rch = v * 2 + 2;
        int m = (l+r) / 2;
        init(lch, l, m);
        init(rch, m, r);
        dat[v].resize(r - l);
        
        /*
            Since the merge process starts when both vectors only possess one element
            respectively, no additional sort is needed. 
        */
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[v].begin());
    }
}

int query(int i, int j, int x, int v, int l, int r) {
    if(j <= l || i >= r)
        return 0;
    if(i <= l && r <= j)
        return upper_bound(dat[v].begin(), dat[v].end(), x) - dat[v].begin();
    else {
        int lch = v * 2 + 1, rch = v * 2 + 2;
        int m = (l+r) / 2;
        int c1 = query(i, j, x, lch, l, m);
        int c2 = query(i, j, x, rch, m, r);
        return c1 + c2;
    }
}

void solve() {
    memcpy(nums, A, sizeof(A));
    sort(nums, nums+n);
    init(0, 0, n);

    for(int p=0; p<m; p++) {
        //0-indexed
        int i = I[p] - 1, j = J[p], k = K[p];

        /*
            Why ub = n - 1 ?
            Because the final answer is nums[ub]；initializing ub = n - 1,
            can prevent seg fault.
        */
        int lb = -1, ub = n - 1;
        while(ub-lb > 1) {
            int mid = (lb + ub) / 2;
            int c = query(i, j, nums[mid], 0, 0, n);
            if(c >= k)
                ub = mid;
            else  
                lb = mid;
        }
        printf("%d\n", nums[ub]);
    }
}


int main() {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) //0-indexed
        scanf("%d", &A[i]);
    for(int i=0; i<m; i++)
        scanf("%d%d%d", &I[i], &J[i], &K[i]);
    
    solve();
    
    return 0;
}