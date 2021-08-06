/*
    利用BIT計算：將一數列(1 ~ n)以Bubble Sort升冪排列時所需的交換次數
    (若單純使用模擬則需O(n * n))

    O(n * log n)
*/
#include <iostream>

using namespace std;

int n, arr[101];
int bit[101];

void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
int sum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

void solve()
{
    int ans = 0;
    for (int j=0; j<n; j++)
    {
        /*
            是否要交換由後面的數字決定；
            sum(arr[j])代表在arr[j]之前已經有多少比arr[j]小的數字出現過，
            而這些是不需要交換的，所以ans += j - sum(arr[j])
        */
        ans += j - sum(arr[j]);

        //代表arr[j]這個數字已經被用過
        
        add(arr[j], 1);
    }
    cout << ans << '\n';
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    solve();
    return 0;
}