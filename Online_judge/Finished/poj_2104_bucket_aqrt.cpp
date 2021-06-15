/*
***K-th Number*** --Bucket method & Sqrt decomposition
    Solution:
        Find out a specific number "x" where there are precisely
        "k" numbers whose value is no larger than "x", which is 
        the answer.

        Another solution uses "Range Tree"

    O(n*logn + m*sqrt(n)*(logn)^(3/2))
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000+5;
const int MAX_M = 5000+5;

const int B = 1000; //size of buckets, slightly larger than sqrt(MAX_N * log(MAX_N))

int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; //sorted A[]
vector<int> buckets[MAX_N/B];

void solve() {
    for(int i=0; i<N; i++) {
        buckets[i/B].push_back(A[i]);
        nums[i] = A[i];
    }
    sort(nums, nums + N);

    /*
        Here, we didn't sort the last bucket, which is not full,
        and everything is still fine. That's because we search 
        one by one for answer in the last bucket.
    */
    for(int i=0; i < N/B; i++) 
        sort(buckets[i].begin(), buckets[i].end());

    //[l, r)
    for(int i=0; i<M; i++) {
        int l = I[i] - 1, r = J[i], k = K[i]; 

        int lb = -1, ub = N - 1;
        while(ub-lb > 1) {
            int mid = (lb+ub) / 2;
            int x = nums[mid];
            int tl = l, tr = r;
            int cnt = 0;
            
            //check one by one for elements outside fully range-covered buckets
            while(tl<tr && tl%B != 0) //tl%B != 0 : before encountering a fully range-covered bucket
                if(A[tl++] <= x)
                    cnt++;
            while(tl<tr && tr%B != 0)
                if(A[--tr] <= x) //[l, r), so --tr
                    cnt++;
            
            while(tl < tr) {
                int b = tl / B; //which bucket
                cnt += upper_bound(
                    buckets[b].begin(), buckets[b].end(), x) - buckets[b].begin();
                tl += B; //move to next bucket
            }

            if(cnt >= k)
                ub = mid;
            else
                lb = mid;
        }
        printf("%d\n", nums[ub]);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) //0-indexed
        scanf("%d", &A[i]);
    for(int i=0; i<M; i++)
        scanf("%d%d%d", &I[i], &J[i], &K[i]);
    
    solve();
    
    return 0;
}