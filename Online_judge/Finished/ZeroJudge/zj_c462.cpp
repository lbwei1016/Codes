/*
***String***
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 100000+5;
bool isCap[MAX_S];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s;
    cin >> k >> s; 

    for(int i=0; i<s.size(); i++) {
        isCap[i] = (s[i] < 'a');
    }

    int ans = 0, cnt = 0;
    int step = 1; //紀錄這是第幾個連續相同大小寫的字母
    for(int i=1; i<s.size(); i++) {
        if(step == k) {
            step = 0;
            cnt++;
            ans = max(ans, cnt);
        }

        if(isCap[i] != isCap[i-1]) {
            //與前一字元不同，又不是新的循環 -> 中斷
            if(step > 0) { 
                ans = max(ans, cnt);
                cnt = 0;
            }
            //新的循環
            step = 1;
        }
        else {
            //與前一字元相同，卻該是新的開始 -> 中斷
            if(step == 0) {
                if(cnt > 1) {
                    ans = max(ans, cnt);
                    cnt = 0;
                    step = 1;
                }
                else continue; //若在此之前沒有其他已完成的循環；e.g. 2 aaaaAA
            }
            //推進一字元
            step++;
        }
    }
    //當最後一個字元剛好是循環的尾端
    if(step == k) {
        cnt++;
        ans = max(ans, cnt);
    }
    cout << ans * k << '\n';
    return 0;
}