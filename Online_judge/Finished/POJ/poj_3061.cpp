/*
***爬行法***

    O(N)
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int N, S;
int num[MAX_N+5];

//minimal length of the subsequence of consecutive elements of the sequence, 
//the sum of which is greater than or equal to S.
void solve()
{
    int sum = 0;
    int from = 0, to = 0;
    int cnt = N+1;
    while(true)
    {
        while(to<N && sum<S)
            sum += num[to++];
        if(sum < S) break;
        cnt = min(cnt, to - from);
        sum -= num[from++];
    }

    if(cnt > N)
        cnt = 0;
    cout << cnt << '\n';
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;
    while(n--)
    {
        cin >> N >> S;
        for(int i=0; i<N; i++)
            cin >> num[i];
        solve();
    }   
    
    return 0;
}