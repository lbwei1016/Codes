/*
***爬行法***

    O(N * N)
*/
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 5000;
int N;
int dir[MAX_N+5]; //F:0; B:1
int f[MAX_N+5]; //whether to turn around cows in [i, i+k-1]

//contiguous K cows to turn around
int solve(int k)
{
    memset(f, 0, sizeof(f));
    int res = 0;
    int sum = 0;
    for(int i=0; i+k<=N; i++)
    {
        //if the turn-arounds done on the previous cows don't make
        //this cow face front, then it turns itself(f[i] = 1)
        if((dir[i] + sum)%2 != 0) 
        {
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i-k+1 >= 0) //get rid of the cow that won't affect the current cow
            sum -= f[i-k+1];
    }
    for(int i=N-k+1; i<N; i++) //check the last cows
    {
        if((dir[i]+sum)%2 != 0) //less than k cows for a turn-around
            return -1; //fail
        if(i-k+1 >= 0)
            sum -= f[i-k+1];
    }
    return res;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        char temp;
        scanf("%c", &temp); //eat '\n'
        scanf("%c", &temp);
        if(temp == 'F')
            dir[i] = 0;
        else
            dir[i] = 1;
    }

    //since turning around a cow twice is meaningless, 
    //the maximum of M is N
    int K = 1, M = N;
    for(int k=1; k<=N; k++) //O(N)
    {
        int m = solve(k); //O(N)
        if(m > 0 && m < M)
        {
            K = k;
            M = m;
        }
    }
    printf("%d %d\n", K, M);
    return 0;
}