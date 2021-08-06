/*
***Binary-Search***

    O(N)
*/
#include <cstdio>
#include <algorithm>

#define MAX_N 100000
#define INF 1e9

using namespace std;

int N, C;
int x[MAX_N+5];

bool Con(int d)
{
    int prev = 0;
    for(int i=1; i<C; i++) //put every cow into a proper stall
    {
        int curr = prev + 1;
        while(curr < N && x[curr] - x[prev] < d)
            curr++;
        if(curr == N) //curr should be in [0, N)
            return false;
        prev = curr;
    }
    return true;
}
int main()
{
    scanf("%d%d", &N, &C);
    for(int i=0; i<N; i++)
        scanf("%d", &x[i]);
    sort(x, x+N);

    int lb = 0, ub = 1e9+5;

    //binary search
    while(ub - lb > 1)
    {
        int mid = (ub + lb) / 2;
        if(Con(mid))
            lb = mid;
        else    
            ub = mid;
    }
    
    /*
        想像剩下最後三個數字: 3, 4, 5；lb = 3, ub = 5, mid = 4
        1. 此時若 solve(mid) = true，則 lb = 4, ub = 5，即代表
           4 為 true，因此答案即為 lb = 4。
           假設答案取 ub，如果真的是 ub，那麼在 lb = 4, ub = 6時，
           就應該取 lb = 5 為答案了，所以取 ub 為答案不合
        2. 此時若 solve(mid) = false，則 lb = 3, ub = 4。
           與上述同理

        因此答案取 lb
    */
    printf("%d\n", lb);
    return 0;
}