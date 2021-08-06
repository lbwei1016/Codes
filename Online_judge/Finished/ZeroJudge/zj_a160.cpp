/*
    N_Queen problem:
        Using the concept of "backtracking", which is
        often carried out by DFS, with continually re-
        storing the status to the previous one. The 
        other example of "backtracking" is "permutation"
        or "zj_a229"
*/
#include <bits/stdc++.h>

using namespace std;

int n, cnt;
vector<int> queens;
void DFS(int row);
void print();
bool check(int row, int col);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> n)
    {
        if(n == 0)
            break;
        cnt = 0;
        queens.resize(n);
        DFS(0);
        cout << cnt << "\n\n";
    }
    return 0;
}
bool check(int row, int col)
{
    for(int r=0; r<row; r++)
    {
        int q_col = queens[r];
        if(col == q_col) return false;
        else if(r+q_col == row+col) return false; 
        //皇后走斜線(往左下)路徑，此時row+1，col-1，所以若在該皇后斜線路徑上，則row+col為定值
        else if(r-q_col == row-col) return false;
        //皇后走斜線(往右下)路徑，此時row+1，col+1，所以若在該皇后斜線路徑上，則row-col為定值
        // 只需考慮往下，因為遞迴由上而下
    }
    return true;
}
void print()
{
    for(auto i : queens)
        cout << i+1 << ' ';
}
void DFS(int row)
{
    for(int col=0; col<n; col++)
    {
        if(check(row, col))
        {
            queens[row] = col;
            if(row == n-1)
            {
                cnt++;
                print();
                queens[row] = 0;
                return;
            }
        DFS(row+1); //go deeper 
        queens[row] = 0; //restoration for backtracking
        }
    }
}