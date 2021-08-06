/*
    O(n ^ 2);
*/
#include <bits/stdc++.h>

using namespace std;

string mat[40];
int last_one[40]; //last_one[i]: the last position that "1" appears in row i

//main diagonal: i=j
long solve(int n)
{
    for(int i=0; i<n; i++)
    {
        last_one[i] = -1; //if there is no "1"
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == '1')
                last_one[i] = j;
        }
    }

    long res = 0;

    //先滿足限制比較嚴格的(愈上面的列限制愈嚴格)
    for(int i=0; i<n ;i++)
    {
        //不交換預設為-1
        int pos = -1;
        for(int j=i; j<n ;j++)
        {
            //找滿足第 i 列的最近的第 j 列
            //滿足第 i 列必定滿足第 i+1 列
            if(last_one[j] <= i)
            {
                pos = j;
                break;
            }   
        }

        for(int j=pos; j>i; j--)
        {
            //往上交換
            //不需操作 mat
            swap(last_one[j], last_one[j-1]);
            res++;
        }
    } 
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        int n;
        cin >> n;
        string temp;
        getline(cin, temp); //eat '\n'
        
        for(int i=0; i<n ;i++)
            getline(cin, mat[i]);

        long res = solve(n);
        cout << "Case #" << cnt << ": " << res << '\n';
    }
    
    return 0;
}