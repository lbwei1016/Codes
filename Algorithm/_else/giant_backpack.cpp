/*
***Giant Backpack***
    Restrictions:
        1 <= n <= 40 (small)
        1 <= w, v <= 10^15 
        1 <= W <= 10^15 (large!!)
    Solution:
        Since "n" is small and W is too big here, we don't use "DP"(O(nW)).
        Instead, we enumerate the combinatiions of half of the elements(n/2)
        respectively to reach a time complexity: O(2^(n/2) * n)
*/
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 40;
const int INF = 1e9;
ll w[MAX_N+5], v[MAX_N+5];
int n, W;
pair<ll, ll> ps[1 << (MAX_N/2)+5]; //w, v

//important to write this comp for "lower_bound()"
bool comp(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}
void solve()
{
    int n2 = n / 2;
    //enumerate the front half part
    for(int i=0; i< (1 << n2); i++)
    {
        ll sw = 0, sv = 0;
        for(int j=0; j<n2; j++)
        {
            if(i >> j & 1)
            {
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }

    sort(ps, ps+(1 << n2));
    int m = 1;
    //take away elements not needed(w is big, but v is small)
    for(int i=1; i<(1 << n2); i++)
    {
        if(ps[m-1].second < ps[i].second)
        {
            ps[m++] = ps[i];
        }
    }

    ll res = 0;
    for(int i=0; i<(1 << (n-n2)); i++)
    {
        ll sw = 0, sv = 0;
        for(int j=0; j<(n-n2); j++)
        {
            if(i >> j & 1)
            {
                sw += w[n2+j];
                sv += v[n2+j];
            }
        }
        if(sw <= W)
        {
            ll tv = (lower_bound(ps, ps+m, make_pair(W-sw, INF), comp) - 1)->second;
            res = max(res, sv + tv);
        }
    }
    cout << res << '\n';
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> w[i];
    for(int i=0; i<n; i++)
        cin >> v[i];
    cin >> W;

    solve();
    return 0;
}