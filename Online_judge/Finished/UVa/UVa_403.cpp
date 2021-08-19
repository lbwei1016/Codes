/*
    Solution: 
        耐心 + 邊界處理
*/
#include <bits/stdc++.h>
using namespace std;

char G[65][70];
void input1(int row, int col, string s) {
    for(int i=0, l=s.size(); i<l; ++i) {
        if(s[i] == ' ' || i+col<=1) continue;
        if(i+col > 65) break;
        G[row][i+col] = s[i];
    }
}
void input5(int row, int col, string s) {
    for(int i=0, l=s.size(); i<l; ++i) {
        if(i*6+col <= 1) continue;
        if(i*6+col > 65) break;
        if(s[i] == 'A') {
            G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = G[row+2][i*6+col+3] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        } 
        else if(s[i] == 'B') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = G[row+2][i*6+col+3] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'C') {
            G[row][i*6+col+4] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = '*';
            G[row+3][i*6+col] = '*';
            G[row+4][i*6+col+4] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';        
        }
        else if(s[i] == 'D') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'E') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'F') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col] = '*';
            G[row+4][i*6+col] = '*';
        }
        else if(s[i] == 'G') {
            G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+3] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'H') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = G[row+2][i*6+col+3] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'I') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col+2] = '*';
            G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col+2] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'J') {
            G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col+3] = '*';
            G[row+2][i*6+col+3] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+3] = '*';
            G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = '*';
        }
        else if(s[i] == 'K') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+3] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+3] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'L') {
            G[row][i*6+col] = '*';
            G[row+1][i*6+col] = '*';
            G[row+2][i*6+col] = '*';
            G[row+3][i*6+col] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'M') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+1] = G[row+1][i*6+col+3] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+2] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'N') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+1] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+2] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+3] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'O') {
            G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'P') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = G[row+2][i*6+col+3] = '*';
            G[row+3][i*6+col] = '*';
            G[row+4][i*6+col] = '*';
        }
        else if(s[i] == 'Q') {
            G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+3] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'R') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = G[row+2][i*6+col+3] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+3] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'S') {
            G[row][i*6+col+4] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = '*';
            G[row+1][i*6+col] = '*';
            G[row+2][i*6+col+1] = G[row+2][i*6+col+2] = G[row+2][i*6+col+3] = '*';
            G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'T') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+2] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col+2] = '*';
            G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'U') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = '*';
        }
        else if(s[i] == 'V') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col+1] = G[row+2][i*6+col+3] = '*';
            G[row+3][i*6+col+1] = G[row+3][i*6+col+3] = '*';
            G[row+4][i*6+col+2] = '*';
        }
        else if(s[i] == 'W') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col] = G[row+1][i*6+col+4] = '*';
            G[row+2][i*6+col] = G[row+2][i*6+col+2] = G[row+2][i*6+col+4] = '*';
            G[row+3][i*6+col] = G[row+3][i*6+col+1] = G[row+3][i*6+col+3] = G[row+3][i*6+col+4] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'X') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col+1] = G[row+1][i*6+col+3] = '*';
            G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col+1] = G[row+3][i*6+col+3] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+4] = '*';
        }
        else if(s[i] == 'Y') {
            G[row][i*6+col] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col+1] = G[row+1][i*6+col+3] = '*';
            G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col+2] = '*';
            G[row+4][i*6+col+2] = '*';
        }
        else if(s[i] == 'Z') {
            G[row][i*6+col] = G[row][i*6+col+1] = G[row][i*6+col+2] = G[row][i*6+col+3] = G[row][i*6+col+4] = '*';
            G[row+1][i*6+col+3] = '*';
            G[row+2][i*6+col+2] = '*';
            G[row+3][i*6+col+1] = '*';
            G[row+4][i*6+col] = G[row+4][i*6+col+1] = G[row+4][i*6+col+2] = G[row+4][i*6+col+3] = G[row+4][i*6+col+4] = '*';
        }
    }
}
void output() {
    for(int i=1; i<=60; ++i) {
        for(int j=6; j<=65; ++j) {
            cout << G[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0; i<60; ++i) cout << '-';
    cout << "\n\n"; 
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    stringstream ss;
    string S;
    memset(G, '.', sizeof(G));
    while(getline(cin, S)) {
        ss.str(""); ss.clear();
        ss << S;
        string ty, f, tmp, str; 
        int r, c;
        ss >> ty;
        if(ty == ".EOP") {
            output();
            memset(G, '.', sizeof(G));
            continue;
        }
        str = S.substr(S.find('|'));
        if(ty == ".P") {
            ss >> f >> r >> c;
            if(f == "C1") input1(r, 5+c, str.substr(1, str.size()-2));
            else input5(r, 5+c, str.substr(1, str.size()-2));
        }
        else if(ty == ".L") {
            ss >> f >> r;
            if(f == "C1") input1(r, 5+1, str.substr(1, str.size()-2));
            else input5(r, 5+1, str.substr(1, str.size()-2));
        }
        else if(ty == ".R") {
            ss >> f >> r;
            if(f == "C1") input1(r, 5+60-str.size()+3, str.substr(1, str.size()-2));
            else input5(r, 5+60-6*(str.size()-2)+1, str.substr(1, str.size()-2));
        }
        else if(ty == ".C") {
            ss >> f >> r;
            if(f == "C1") input1(r, 5+31-(str.size()-2)/2, str.substr(1, str.size()-2));
            else input5(r, 5+31-6*(str.size()-2)/2, str.substr(1, str.size()-2));
        }
    }
    return 0;
}