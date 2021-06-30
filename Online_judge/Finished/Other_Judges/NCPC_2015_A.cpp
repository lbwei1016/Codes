/*
***stringstream***
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+5;

int t;
int _prev[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream ss;
    cin >> t;
    string temp;
    getline(cin, temp);
    while(t--) {
        ss.clear();
        ss.str("");
        memset(_prev, 0, sizeof(_prev));
        long long res = 0;
        string s;
        getline(cin, s);
        ss << s;
        for(int i=1; !ss.eof(); i++) {
            int num;
            ss >> num;
            if(_prev[num] == 0) {
                _prev[num] = i;
                res += i;
            }
            else {
                res -= _prev[num];
                _prev[num] = i;
                res += i;
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}