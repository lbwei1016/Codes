#include <iostream>
#define SIZE 7

using namespace std;

// input
int n = 3; // 提示數
int hint[] = {1, 1, 1};

int com_num;
int hint_sum[13+5]; // hint_sum[i] 代表第 i 個提示的右邊有多少個 1
// 可能組合 (要放幾個空白)
int arr[][13+5] =  
{
    {0, 0, 1, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {2, 0, 0, 0},
    {0, 2, 0, 0},
    {0, 0, 2, 0},
    {0, 0, 0, 2}
}; 
int com[50388*25];

int bit() // 算出基本型態；i.e. 010101....: 1 和 1 中間只放一個 0
{
    int res = 0;
    for(int i=0; i<n; i++)
    {
        res <<= 1;
        for(int j=0; j<hint[i]; j++)
        {
            res <<= 1; 
            res |= 1;
        }
    }
    return res;
}
void comb(int b) // 列舉
{
    for(int i=0; i<com_num; i++) // 方法數
    {
        int res = b, temp, k;
        for(int j=1; j<n; j++)
        {
            if(arr[i][j])
            {
                temp = res;
                temp >>= (hint_sum[j-1] + n-j);
                temp <<= (hint_sum[j-1] + n-j);
                k = res - temp;
                res = (temp << arr[i][j]) + k;
            }
        }
        res <<= arr[i][n]; // 最後一處，不可以再放空白在後
        cout << res << '\n';
        com[i] = res;
    }
}
void trans() // 將數字的位元表示出來
{
    int cnt = 0;
    for(int i=0; i<com_num; i++)
    {
        cout << ++cnt << ": "; 
        for(int j=SIZE-1; j>=0; j--)
        {
            int temp = com[i];
            if(temp & (1 << j)) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
}
int H(int n,int k)
{
	int dp[SIZE+1][SIZE+1];
	for(int i=1;i<SIZE+1;i++)
	{
		dp[i][0]=1;
		dp[0][i]=1;
	}
	for(int i=1;i<SIZE+1;i++)
		for(int j=1;j<SIZE+1;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		
	return dp[n][k];
}
int main()
{
    hint_sum[n-1] = 0;
    for(int i=n-1-1; i>=0; i--)
    {
        hint_sum[i] += hint_sum[i+1] + hint[i+1];
    }

    int b = bit();

    com_num = H(n, SIZE-n-(n-1)); // H(每列有幾個提示, 可自由填空個數)

    cout << "b is: " << b << '\n';
    comb(b);
    trans();
    
    return 0;
}