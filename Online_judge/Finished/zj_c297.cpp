/*
***Simulation / bitwise operation***
*/
#include <bits/stdc++.h>

using namespace std;

queue<int> hit[9];
int B;

int solve() {
    int b = 0, score = 0;
    int out = 0;
    int base = 0;
    while(b < B) {
        for(int i=0; i<9; i++) {
            int t = hit[i].front(); hit[i].pop();
            if(t == 4) {
                score++;
                for(; base>0; base>>=1) {
                    if(base & 1) score++;
                }
            }
            else if(t > 0) {
                base <<= t; //push
                base |= (1 << (t-1));
                // (0111) = 7
                if(base > 7) {
                    if(base > (1 << 5)) {
                        base -= (1 << 5);
                        score++;
                    }
                    if(base > (1 << 4)) {
                        base -= (1 << 4);
                        score++;
                    }
                    if(base > (1 << 3)) {
                        base -= (1 << 3);
                        score++;
                    }
                }
            }
            else out++;

            if(b + out >= B) return score;
            if(out == 3) {
                b += 3;
                out = 0;
                base = 0;
            }
        }
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++) {
        int t;
        cin >> t;
        for(int j=0; j<t; j++) {
            string s;
            cin >> s;
            if(s == "1B") hit[i].push(1);
            else if(s == "2B") hit[i].push(2);
            else if(s == "3B") hit[i].push(3);
            else if(s == "HR") hit[i].push(4);
            else hit[i].push(-1);
        }
    }
    cin >> B;
    cout << solve() << '\n'; 
    
    return 0;
}