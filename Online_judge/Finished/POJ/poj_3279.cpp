#include <cstdio>
#include <cstring>
#define MAX_M_N 15

using namespace std;

int M, N;
int tile[MAX_M_N+5][MAX_M_N+5]; //black:1; white:0
int opt[MAX_M_N+5][MAX_M_N+5]; //to store the optimal answeer
int flip[MAX_M_N+5][MAX_M_N+5]; //to be operated

int dx[] = {1, 0, 0, -1, 0},
    dy[] = {0, 1, 0, 0, -1};

int get_color(int x, int y) {
    int c = tile[x][y];
    for(int i=0; i<5; i++)
    {
        int nx = x + dx[i],
            ny = y + dy[i];
        if(0<=nx && nx<M && 0<=ny && ny<N)
            c += flip[nx][ny];
    }
    return c % 2;
}
int calc() {
    for(int i=1; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(get_color(i-1, j) != 0) { //檢查上一列；如果是黑色的話(1)，當前列就只好翻轉
                flip[i][j] = 1;
            }
        }
    }

    //檢查最後一列
    for(int j=0; j<N; j++) {
        if(get_color(M-1, j) != 0)
            return -1;
    }

    //計算翻轉數(當flip[][] = 1)
    int res = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            res += flip[i][j];
        }
    }
    return res;
}

int main() {
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++) { //x
        for(int j=0; j<N; j++) { //y
            scanf("%d", &tile[i][j]);
        }
    }

    int res = -1;
    //to enumerate all possible situations regarding the first row
    for(int i=0; i < 1<<N; i++) {
        memset(flip, 0, sizeof(flip));
        for(int j=0; j<N; j++) {
        /*
                以二進位位元來思考:
                    i < 1<<N，因此 i 介於 0 ~ 2^N-1；若將第 k 位元為 1 時，
                    視為 flip[0][k] = 1，則可以列舉(enumerate)單格選與不選的
                    所有情形。
        */
        //從flip[0]的右方開始排(如同位元)
        flip[0][N-j-1] = i >> j & 1;
        }
        int num = calc();
        if(num >=0 && (res < 0 || res > num)) {
            res = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }
    if(res < 0) {
        printf("IMPOSSIBLE\n");
    }
    else {
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                printf("%d%c", opt[i][j], j == N-1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}