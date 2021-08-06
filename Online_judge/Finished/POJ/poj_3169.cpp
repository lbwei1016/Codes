/*
***Bellman-Ford***
(不得不用中文說明)
    題目:
        有 N 頭牛，依序編號為 1~N，彼此有喜歡與討厭的關係: 若 A 喜歡 B，則 d[A] - d[B] <= D；
        若 B 討厭 C，則 d[B] - d[C] >= D'。求 1 號牛與 N 號牛之間的最大距離(d[N] - d[1] = ?)
    思路: (參考圖: 間距問題轉化為最短路徑問題)
        # 已知求「最大」間距，所以:
        一、 喜歡的盡量拉遠
        二、 討厭的盡量靠近!! 為什麼??
            => 假設討厭的互相遠離。因為可求出最大間距的序列之中，「互相討厭」必定被「互相喜歡」
            所包圍(否則牛隻將可以無限分離)，因此若使假設成立，「互相討厭」分離的代價將是把「互相
            喜歡」給拉近，亦即將第 N 隻牛往前移動，(因為第 N 隻牛必定被某牛喜歡，否則間距將無限大)
            而減小最大間距。(此兩點可參考圖並想像「兩個卡榫」)
        三、 由前述兩點以及題目不等式可知，「互相喜歡」的距離將是 D；「互相討厭」的距離將是 -D'。
             依此可將問題轉化為「圖的最短路徑問題」(邊的權重及方向參考圖)
             (若兩牛之間是可到達的，則設權重為0，並由後指向前)
        四、 因為可能有負的權重，所以使用 Bellman-Ford 而非 Dijkstra
    測資: (對應圖)
        4 2 1
        1 3 10
        2 4 20
        2 3 3
    O(N * (N + ML + MD))
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_ML 10001
#define MAX_N 1001
#define INF 1e9
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_ML], BD[MAX_ML], DD[MAX_ML];

int d[MAX_N]; //shortest path

void bellman_ford()
{
    fill(d, d + N, INF);
    d[0] = 0; //start from 0 to N-1

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i + 1 < N; i++) //set weight 0
        {
            if (d[i + 1] < INF)
                d[i] = min(d[i], d[i + 1]);
        }
        for (int i = 0; i < ML; i++) //like
        {
            if (d[AL[i] - 1] < INF)
                d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
        }
        for (int i = 0; i < MD; i++) //dislike
        {
            if (d[BD[i] - 1] < INF)
                d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
        }
    }
    int res = d[N - 1];
    if (d[0] < 0) //negative cyclic paths exist
        res = -1;
    else if (res == INF) //infinite distance
        res = -2;

    printf("%d\n", res);
}
int main()
{
    scanf("%d%d%d", &N, &ML, &MD);
    for (int i = 0; i < ML; i++)
        scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
    for (int i = 0; i < MD; i++)
        scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);

    bellman_ford();

    return 0;
}