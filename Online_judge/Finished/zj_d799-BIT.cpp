#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 500000;
int N;
int arr[MAX_N+1];
ll bit0[MAX_N+1], bit1[MAX_N+1];

void add(ll *bit, int i, int k)
{
    while(i <= N)
    {
        bit[i] += k;
        i += i & -i;
    }
}
ll sum(ll *bit, int i)
{
    ll s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    for(int i=1; i<=N; i++)
    {
        add(bit0, i, arr[i]);
    }
    int Q;
    cin >> Q;
    while(Q--)
    {
        int v;
        cin >> v;
        if(v == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;

            add(bit0, x, -k*(x-1));
            add(bit1, x, k);
            add(bit0, y+1, k*y);
            add(bit1, y+1, -k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            ll res = 0;
            res += sum(bit0, y) + sum(bit1, y) * y;
            res -= sum(bit0, x-1) + sum(bit1, x-1) * (x-1);
            cout << res << '\n';
        }
    }
    return 0;
}