/*
    DFS + backtracking
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, sum;
vector<pii> v; //value, number
void solve(int sum, int index)
{
    if(index == n && sum > 0)
        return;
    if(sum == 0)
    {
        cout << '(';
        for(int i=0; i<n-1; i++)
        {
            cout << v[i].second << ',';
        }
        cout << v[n-1].second << ")\n";   
        return;
    }
    else
    {
        for(int j=0; v[index].first*j <= sum; j++) //一次選一種幣值來遞迴
        {
            sum -= v[index].first*j;
            v[index].second = j;
            solve(sum, index+1);
            //restoration
            v[index].second = 0;
            sum += v[index].first*j;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin >> v[i].first;
    cin >> sum; 
    solve(sum, 0);
    
    return 0;
}
