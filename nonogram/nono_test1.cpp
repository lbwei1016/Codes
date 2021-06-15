#include <cstdio>
#include <cstring>
#define SIZE 5
using namespace std;

int H(int, int);
void Combin(int, int, int);

int n; //numbers of hints of a single row
int cnt; //number of combinations
int intervals; //places to put white blocks
int no; //count for com[][]
int hints[SIZE];
int com[10000][SIZE+1]; //possible combinations

int main()
{
    int n; //numbers of hints of a single row
    scanf("%d", &n);

    int zeros = SIZE;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &hints[i]);
        zeros -= hints[i];
    }
    zeros = zeros-n+1;
    intervals = n+1;

    cnt = H(intervals-1, zeros);
    memset(com, 0, sizeof(com));

    no = 0;
    Combin(no, zeros, 0);

        
    return 0;
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
	{
		for(int j=1;j<SIZE+1;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	
	return dp[n][k]; //(n+k)! / (n! * k!)
}
void Combin(int zeros, int d)
{
    if(d == intervals-1)
    {
        com[no][d] = zeros;
        com[no][d] = 0;
        return;
    }
    else
    {
        for(int i=0; i<=zeros; i++)
        {
            com[no][d] = i;
            Combin(no, zeros-i, d+1);
            com[no][d] = 0;
        }
    }
}