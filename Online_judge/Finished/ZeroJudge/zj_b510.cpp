/*
    M-Queen-N-Castle problem:
        The advanced version of "N-Queen problem"
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int m, n, ch, cnt;
vector<pii> que, cas; //pii: row, col
void DFS(int);
bool check(int, int, char);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n;
    ch = m+n; //棋盤大小: m+n
    cnt = 0;
    DFS(0);
    cout << cnt << '\n';
    return 0;
}
bool check(int row, int col, char sym)
{
    for(int i=0; i<que.size(); i++)
    {
        pii p = que[i];
        int q_r = p.first,
            q_c = p.second;
        if(col == q_c) return false;
        else if(q_r+q_c == row+col) return false;
        else if(q_r-q_c == row-col) return false;
    }
    for(int i=0; i<cas.size(); i++)
    {
        pii p = cas[i];
        int cas_c = p.second;
        if(col == cas_c) return false;
    }
    if(sym == 'q') //若當前放下的是皇后，需確認是否路徑上已擺放了城堡
    {
        for(int i=0; i<cas.size(); i++)
        {
            pii p = cas[i];
            int cas_r = p.first,
                cas_c = p.second;
            if(cas_r+cas_c == row+col) return false; //row-1, col+1 (右上)
            else if(cas_r-cas_c == row-col) return false; //row-1, col-1 (左上)
        }
    }
    return true;
}
void DFS(int row)
{
    for(int col=0; col<ch; col++)
    {
        if(que.size() < m && check(row, col, 'q'))
        {
            que.push_back(make_pair(row, col));
            if(que.size() == m && cas.size() == n)
            {
                cnt++;
                que.pop_back();
                return;
            }
            DFS(row+1);
            que.pop_back();
        }
        if(cas.size() < n && check(row, col, 'c'))
        {
            cas.push_back(make_pair(row, col));
            if(que.size() == m && cas.size() == n)
            {
                cnt++;
                cas.pop_back();
                return;
            }
            DFS(row+1);
            cas.pop_back();
        }
    }
}