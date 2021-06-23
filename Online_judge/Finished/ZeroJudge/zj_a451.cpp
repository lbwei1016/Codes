#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD;
struct Mat
{
    ll mat[2][2] = 
    {
        {1, 1},
        {1, 0}
    };
    friend Mat operator* (const Mat &l, const Mat &r);
    friend Mat operator% (Mat l, const ll mod);
};
Mat operator* (const Mat &l, const Mat &r)
{
    Mat res;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            res.mat[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                res.mat[i][j] += l.mat[i][k] * r.mat[k][j];
            }
        }
    }
    return res;
}
Mat operator% (Mat m, const ll mod)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            m.mat[i][j] %= mod;
        }
    }
    return m;
}
Mat power(Mat &m, int n)
{
    Mat res;
    while(n > 0)
    {
        if(n & 1)
            res = (res * m) % MOD;
        m = (m * m) % MOD;
        n >>= 1;
    }
    return res;
}
ll power(ll x, ll n)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1)
            res *=  x ;
        x *= x;
        n >>= 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while(cin >> n >> m)
    {   
        Mat temp;
        if(n == 0)
        {
            cout << "0\n";
            continue;
        }
        MOD = power(2, m);
        Mat fib = power(temp, n-2);
        ll ans = fib.mat[0][0];
        cout << ans << '\n';
    }
    return 0;
}