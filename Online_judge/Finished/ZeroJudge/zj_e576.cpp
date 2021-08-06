/*
***Greedy***
*/
#include <bits/stdc++.h>

using namespace std;

#define N 100001
typedef pair<int, int> pii;
int T, M;
vector<pii> coor, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    while(T--)
    {
        coor.resize(N);
        ans.resize(N);
        cin >> M;
        int l, r;
        int num = 0; //number of coordinates
        for(int i=0; cin >> l >> r; i++)
        {
            if(l == 0 && r == 0)
                break;
            coor[i].first = l,
            coor[i].second = r;
            num++;
        }
        sort(coor.begin(), coor.begin()+num); //由小到大排(以左值為準)

        int left = 0, right = 0; //所要包含的左、右界
        int flag = -1; //記錄先前一點
        int cnt = 0; //共需幾點
        bool found = false; //是否有解
        while(right < M) 
        {   
            int j;
            //自最左開始，持續搜索左值小(等)於左界，且有最大右值的點
            for(j=flag+1, flag=-1; coor[j].first <= left && j<num; j++)
            {
                if(coor[j].second > right)
                {
                    flag = j;
                    right = coor[j].second;
                }   
            }
            left = right; //原本的右界變成下一點的左界
            ans[cnt].first = coor[flag].first,
            ans[cnt].second = coor[flag].second;
            cnt++;

            if(flag == -1)
                break;
            if(right >= M)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            cout << cnt << "\n";
            for(int i=0; i<cnt; i++)
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            cout << '\n';
        }
        else
            cout << "0\n\n";
    }
    return 0;
}