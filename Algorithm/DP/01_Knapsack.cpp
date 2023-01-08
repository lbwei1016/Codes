#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100+5;
const int MAX_W = 1e5+5;
int N, W;
int v[MAX_N], w[MAX_N];
int dp[MAX_N][MAX_W];

int main() {
    scanf("%d%d", &N, &W);
    for(int i=1; i<=N; i++) {
        scanf("%d", &w[i]);
    }
    for(int i=1; i<=N; i++) {
        scanf("%d", &v[i]);
    }

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=W; j++) {
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[N][W]);
    return 0;
}
/*Reuse I:
int dp[2][100] = {0};

int from = 0, to = 1;
for(int i=0; i<N; i++) {
    for(int j=0; j<w[i]; j++) {
        dp[to][j] = dp[from][j];
    }
    for(int j=w[i]; j<=W; j++) {
        dp[to][j] = max(dp[from][j], dp[from][j-w[i]] + v[i]);
    }
    swap(to, from);
}
*/

/*Reuse II:
int dp[100] = {0};

for(int i=0; i<N; i++) {
    for(int j=W; j>=w[i]; j--) {
        dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
}
*/