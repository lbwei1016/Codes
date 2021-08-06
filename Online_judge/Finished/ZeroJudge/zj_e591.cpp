/*
***Greedy***
*/
#include <bits/stdc++.h>

using namespace std;

int t, n;
int coin[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int sum, cnt = 2; //為了得到最大值，最大和最小的硬幣一定會被使用
        for(int i=0; i<n; i++)
            cin >> coin[i];
        sum = coin[0];
        for(int i=1; i<n-1; i++) //為了得到最大值，最大和最小的硬幣一定會被使用
        {
            //原則:逐一檢視各幣值，由小到大(只需剛好擁有各幣值的面額，因為多餘的錢是無意義的)，
            //接著若目前金額 >= 下一個幣值，則必須被代換為該較大的硬幣(此時cnt不必減少，因為該
            //較大硬幣只取代比他稍小的那個硬幣，因此cnt不變)
            if(sum + coin[i] < coin[i+1])
            {
                sum += coin[i];
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}