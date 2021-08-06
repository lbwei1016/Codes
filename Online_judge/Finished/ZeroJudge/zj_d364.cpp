/*
    UAa 10637: Coprimes (DFS)
*/

//if gcd(a, b) = 1 --> COPRIME!!!
//原本打算用set來處理因數問題，但其實只要求gcd即可確認兩數是否互質
//gcd先製作表格，且利用「__gcd()」
#include <bits/stdc++.h>

using namespace std;

#define N 101
vector<int> coprime;
//set<int> divisor[N];
int GCD[N][N];
int S, T;

// void find_divisor(int x, int n)
// {
//     for(int i=2; i<=x; i++)
//         if((x%i) == 0)
//             divisor[n].insert(i);
// }
void dfs(int s, int t, int k)
{
    if(t == 0)
    {
        // for(int a=0; a<T; a++)
        // {
        //     int num = coprime[a];
        //     find_divisor(num, a);
        // }

        bool flag = false;
        for(int a=0; a<T; a++)
        {
            for(int b=a+1; b<T; b++)
            {
                // set<int> intersect;
                // set_intersection(divisor[a].begin(), divisor[a].end(),
                //                  divisor[b].begin(), divisor[b].end(),
                //                  inserter(intersect, intersect.begin()));
                // if(intersect.size() != 0)
                // {
                //     flag = true;
                //     break;;
                // } 
                int m = coprime[a],
                    n = coprime[b];
                if(GCD[m][n] != 1) //if a, b 並不互質
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }

        if(!flag)
        {
            for(int i : coprime)
                cout << i << ' ';
            cout << '\n';
        }
        //clear previous data
        coprime[T-1] = 0;
        //divisor[T-1].clear();
        return;
    }
    if(t == 1)
    {
        coprime[T-1] = s;
        dfs(0, 0, 0);

        if(T > 1)
        {
            coprime[T-2] = 0;
            //divisor[T-2].clear();
        }
        return;
    }

    for(int i=k; i<=s/2; i++)
    {
        coprime[T-t] = i;
        if(T-t > 0)
        {
            int m = coprime[T-t],
                n = coprime[T-t-1];
            if(GCD[m][n] != 1)
                continue;
        }
        dfs(s-i, t-1, i);
        coprime[T-t] = 0;
        //divisor[T-t].clear();
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    for(int i=1; i<N; i++)
        for(int j=1; j<N; j++)
            GCD[i][j] = __gcd(i, j); // <algorithm>: __gcd()
    int n;
    while(cin >> n) //多筆測資~~
    {
        for(int i=1; i<=n; i++)
        {
            cout << "Case " << i << ":\n";
            cin >> S >> T;
            coprime.resize(T);
            dfs(S, T, 1);
        }
    }
    return 0;
}