/*
***Simulation*** --Tetris
*/
#include <bits/stdc++.h>

using namespace std;
/*
       u
    l (xy) r
       d
*/
struct tetris { 
    int x, y, u, d, l, r; 
}T;
int X, Y, n;
int op[100+5];

void rotate(tetris &T) {
    if(!T.u) {
        T.u = 1;
        T.r = 0;
    }
    else if(!T.r && T.x != X) {
        T.r = 1;
        T.d = 0;
    }
    else if(!T.d) {
        T.d = 1;
        T.l = 0;
    }
    else if(!T.l && T.x != 1) {
        T.l = 1;
        T.u = 0;
    }
}

void solve() {
    int x = X % 2 == 0 ? X/2 : X/2 + 1;
    T = {x, Y, 0, 1, 1, 1};

    T.y--;
    for(int i=0; n-- && (T.y >= 2 || (!T.d && T.y >= 1)); i++, T.y--) {
        if(op[i] == 1) {
            if(T.x == X || T.r && T.x + 1 == X) continue; 
            T.x++;
        }
        else if(op[i] == 2) {
            if(T.x == 1 || T.l && T.x -1 == 1) continue; 
            T.x--;
        }
        else if(op[i] == 3) {
            if(T.d) T.y = 2;
            else T.y = 1;
            return;
        }
        else if(op[i] == 4) {
            if(T.y == 1) return;
            rotate(T);
        }
    }
    T.y++;
}
void print() {
    int x = T.x, y = T.y;
    int x2, x3, x4, y2, y3, y4;
    if(!T.u) {
        x2 = x + 1; y2 = y;
        x3 = x; y3 = y - 1;
        x4 = x - 1; y4 = y;
    }
    else if(!T.r) {
        x2 = x; y2 = y + 1;
        x3 = x; y3 = y - 1;
        x4 = x - 1; y4 = y;
    }
    else if(!T.d) {
        x2 = x + 1; y2 = y;
        x3 = x; y3 = y + 1;
        x4 = x - 1; y4 = y;
    }
    else if(!T.l) {
        x2 = x + 1; y2 = y;
        x3 = x; y3 = y - 1;
        x4 = x; y4 = y + 1;
    }

    for(int j=Y; j>=1; j--) {
        for(int i=1; i<=X; i++) {
            if(i==x && j==y) cout << "1";
            else if(i==x2 && j==y2) cout << "1";
            else if(i==x3 && j==y3) cout << "1";
            else if(i==x4 && j==y4) cout << "1";
            else cout << "0";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X >> Y;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> op[i];
    solve();
    print();
    
    return 0;
}