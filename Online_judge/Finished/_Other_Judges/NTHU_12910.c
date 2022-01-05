#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define MAXN 45

int main() {
    int N, M, is_com[MAXN] = {0}; 
    char G[MAXN][MAXN];

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) {
        scanf("%s", G[i]);
    }

    int pos = -1, cnt = 0;
    int diff; // how many pixels to fall
    for(int i=N-1; i>=0; --i) {
        for(int j=0; j<M; ++j) {
            if(G[i][j] == 'o') {
                int k = i;
                for(; G[k][j]!='x' && k<N; ++k);
                pos = max(pos, k-1);
            }
        }
        if(pos > 0) {
            diff = pos - i;
            break;
        }
    }

    for(int i=0; i<N; ++i) {
        int com = 1;
        for(int j=0; j<M; ++j) {
            if(G[i][j] == 'o') {
                G[i+diff][j] = 'x';
                G[i][j] = '.';
            }
            else if(G[i][j] != 'x') {
                com = 0; 
            }
        }
        if(com) {
            for(int j=0; j<M; ++j) G[i][j] = '.';
            is_com[i] = 1;
            ++cnt;
        }
    }
    for(int i=0; i<cnt; ++i) {
        for(int j=0; j<M; ++j) {
            putchar('.');
        }
        putchar('\n');
    }
    for(int i=0; i<N; ++i) {
        if(is_com[i]) continue;
        for(int j=0; j<M; ++j)
            putchar(G[i][j]);
        putchar('\n');
    }
    return 0;
}