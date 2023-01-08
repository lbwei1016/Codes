/*
***LCS*** -- reduce momory
    Description:
        由漸進式可以看出，計算過程中只需要當前列以及上一列的資訊。
            "from": 代表前一列 (以及代表偶數行)
            "to": 代表當前第 i 列 (奇數行)
        重複利用陣列，每算完一列再交換 from 和 to。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char s1[505], s2[505];
    scanf("%s%s", s1, s2);
    int m = strlen(s1), n = strlen(s2);
    int lcs[2][505] = {0};
    int from = 0, to = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            lcs[to][j] = s1[i-1] == s2[j-1] ? lcs[from][j-1]+1 : \
                            max(lcs[from][j], lcs[to][j-1]);
        }
        swap(from, to);
    }
    //since "from" and "to" swapped in the last step, so the result is "from"
    printf("%d\n", lcs[from][n]);
    return 0;
}