/*
***Greedy***
    TIME OUT!!!
*/
#include <stdio.h>

int n, m, p, q, r, s;
int coin[1000001], value[1000001];
int main()
{
    int i, j;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
        value[i] = 1;

    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d%d", &p, &q, &r, &s);
        if(r & 1)
        {
            for(j=p; j<=q; j++)
                coin[j] += s;
        }
        else
        {
            for(j=p; j<=q; j++)
                value[j] *= s;
        }
            
    }
    int sum = 0, index = 1000001;
    for(i=1; i<=n; i++)
    {
        int temp = coin[i] * value[i];
        if(temp > sum)
        {
            sum = temp;
            index = i;
        }
        else if(temp == sum)
        {
            if(i < index)
            {
                sum = temp;
                index = i;
            }
        }
    }
    printf("%d %d\n", index, sum);
    return 0;
}
/*
    #include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m, p, q, r, s;
pii chest[1000001]; //number, times of value

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    //chest.resize(n+1); //skip index 0
    for(int i=1; i<=n; i++)
        chest[i].second = 1; //for multiplication
    for(int i=0; i<m; i++)
    {
        cin >> p >> q >> r >> s;
        if(r == 1)
        {
            for(int j=p; j<=q; j++)
            {
                chest[j].first += s;
            }
        }
        else   
        {
            for(int j=p; j<=q; j++)
            {
                chest[i].second *= s;
            }
        } 
    }
    int sum = 0, index = 1e6+1;
    for(int i=1; i<=n; i++)
    {
        int temp = chest[i].first * chest[i].second;
        
        if(temp > sum)
        {
            sum = temp;
            index = i;
        }
        else if(temp == sum)
        {
            if(i < index)
            {
                sum = temp;
                index = i;
            }
        }
    }
    cout << index << ' ' << sum << '\n';


    
    return 0;
}
*/