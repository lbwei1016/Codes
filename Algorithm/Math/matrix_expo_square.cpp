#include <iostream>

using namespace std;

const int MOD = 1e9+7;

typedef long long ll;
struct Mat
{
    ll mat[2][2] = 
    {
        {1, 1},
        {1, 0}
    };
	friend Mat operator* (const Mat &l, const Mat &r); //"friend" is necessary
    friend Mat operator% (Mat , const int);
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
                res.mat[i][j] += (l.mat[i][k] * r.mat[k][j]) % MOD;
            }
        }
    }
    return res;
}
// Mat operator% (Mat m, const int mod)
// {
//     for(int i=0; i<2; i++)
//     {
//         for(int j=0; j<2; j++)
//         {
//             m.mat[i][j] %= mod;
//         }
//     }
//     return m;
// }
Mat expo(Mat m, ll n)
{
    Mat res;
    while(n > 0)
    {
        if(n & 1)
            res = (res * m);
        m = (m * m);
        n >>= 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    Mat fib;
    Mat res = expo(fib, n);
    cout << res.mat[0][0] << '\n';

    return 0;
}