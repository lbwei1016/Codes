/*
***Matrix***
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100

long long mat1[MAX_SIZE+1][MAX_SIZE+1];
long long mat2[MAX_SIZE+1][MAX_SIZE+1];
int a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> a >> b >> c >> d)
    {
        long long ans[a][d];
        for(int i=0; i<a; i++)
            for(int j=0; j<d; j++)
                ans[i][j] = 0;
        if(b != c)
        {
            cout << "Error\n";
            continue;
        }
            
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
                cin >> mat1[i][j];
        }
        for(int i=0; i<c; i++)
        {
            for(int j=0; j<d; j++)
                cin >> mat2[i][j];
        }

        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                for(int k=0; k<d; k++)
                {
                    ans[i][k] += mat1[i][j] * mat2[j][k];
                }
            }
        }
        for(auto &i : ans)
        {
            for(auto j : i)
                cout << j << ' ';
            cout << '\n';
        }
    }
    return 0;
}