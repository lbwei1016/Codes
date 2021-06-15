#include <bits/stdc++.h>
using namespace std;

#define MAX_S 100000
int k;
string s;
bool isCapital[MAX_S+5];

int solve()
{
    for(int i=0; i<s.size(); i++)
        isCapital[i] = (s[i] < 'a');

    int pos = 0, ans = 0;
    bool end = false;
    while(pos < s.size()-1 && !end)
    {
        int num = 0, cnt = 1;
        bool prev = isCapital[pos];
        bool should_change = false;
        if(cnt == k)
        {
            cnt = 0;
            num++;
            should_change = true;
        }
        for(int i=pos+1; i<s.size(); i++)
        {
            if(isCapital[i] == prev)
            {
                if(!should_change)
                    cnt++;
                else if(num > 1)
                {
                    pos = i;
                    break;
                }
                if(cnt == k)
                {
                    cnt = 0;
                    num++;
                    should_change = true;
                }
            }
            else
            {
                if(should_change)
                {
                    should_change = false;
                    prev = isCapital[i];
                    cnt++;
                    if(cnt == k)
                    {
                        cnt = 0;
                        num++;
                        should_change = true;
                    }
                }
                else
                {
                    pos = i;
                    break;
                }
            }
            if(i == s.size()-1)
                end = true;
        }
        ans = max(ans, num);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> s;
    int res = k * solve();
    cout << res << '\n';

    return 0;
}