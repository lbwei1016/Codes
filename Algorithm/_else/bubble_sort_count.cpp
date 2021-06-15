/*
    ノBIT璸衡盢计(1 ~ n)Bubble Sortど经逼┮惠ユ传Ω计
    (璝虫ㄏノ家览玥惠O(n * n))

    O(n * log n)
*/
#include <iostream>

using namespace std;

int n, arr[101];
int bit[101];

void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
int sum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

void solve()
{
    int ans = 0;
    for (int j=0; j<n; j++)
    {
        /*
            琌璶ユ传パ计∕﹚
            sum(arr[j])arr[j]ぇ玡竒Τぶゑarr[j]计瞷筁
            τ硂ㄇ琌ぃ惠璶ユ传┮ans += j - sum(arr[j])
        */
        ans += j - sum(arr[j]);

        //arr[j]硂计竒砆ノ筁
        
        add(arr[j], 1);
    }
    cout << ans << '\n';
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    solve();
    return 0;
}