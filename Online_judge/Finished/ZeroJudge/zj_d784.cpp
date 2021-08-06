#include <bits/stdc++.h>

using namespace std;

int arr[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, sum = 0;
        int max = -10000000; //將max以極小數初始化
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> arr[i];
        for(int i=0; i<n; i++)
        {
            if(sum < 0) //當前面的和<0，就歸零，即從自己開始算
                sum = 0;
            sum += arr[i];
            if(sum > max)
                max = sum;
        }
        cout << max << '\n';
    }
    return 0;
}