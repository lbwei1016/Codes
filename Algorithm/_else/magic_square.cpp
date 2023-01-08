/*
    Description:
        To produce a square whose elements' sum of rows, columns, and 
        diagonals are all identical.
            e.g.
                6 7 2
                1 5 9
                8 3 4
    Solution:
        This is a solution from Wiki, not knowing how to prove.

    Note: 
        This solution is for n that is odd.
        
    O(N^2)
*/
#include <iostream>

using namespace std;

int n, N;
int G[5+1][5+1];
int x, y;

int main() {
    cin >> n;
    N = n * n;
    x = 0, y = 1; //fixed position: must tart from here
    int cnt = 1;
    while(cnt <= N) {
        G[x][y] = cnt++;

        int ny = (y+1) % n;
        int nx = (x-1+n) % n;
        if(G[nx][ny] == 0) {
            x = nx, y = ny;
        }
        else {
            x = (x+1) % n;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d%c", G[i][j], j==n-1 ? '\n' : ' ');
        }
    }
    return 0;
}