#include <cstdio>

using namespace std;

int cnt = 0;
void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        printf("%d: Move from %c to %c\n", ++cnt, A, C);
    }
    else
    {
        hanoi(n-1, A, C, B); //前n-1個較小的盤子
        hanoi(1, A, B, C); //第n個最大的盤子
        hanoi(n-1, B, A, C); //前n-1個較小的盤子
    }
    
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    printf("請輸入盤數: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    
    return 0;
}