#include <bits/stdc++.h>

using namespace std;

int m, n, t;
int col[1000], row[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--)
    {
        int sum = 0;
        cin >> m >> n;
        for(int i=0; i<m; i++)
            cin >> col[i];
        for(int i=0; i<n; i++)
            cin >> row[i];
        //降冪排列，為了優先讓燈泡多的去抵銷
        sort(col, col+m, greater<int>());
        sort(row, row+n, greater<int>());

        for(int i=0; i<n; i++) //固定--列
        {
            for(int j=0; j<m && col[j] && row[i]; j++) //行、列互相抵消
            {
                col[j]--;
                row[i]--;
                sum++;
            }
            sum += row[i]; //列--沒被抵銷的
            sort(col, col+m, greater<int>()); //降冪排列，為了優先讓燈泡多的去抵銷，否則就會沒抵銷而直接執行"sum += row[i]"，因而高估答案
        }
        for(int i=0; i<m; i++)
        {
            sum += col[i]; //行--沒被抵銷的
        }
        cout << sum << '\n';
    }
    return 0;
}