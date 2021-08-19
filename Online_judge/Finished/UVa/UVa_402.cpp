#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, cnt = 0;
    while(cin >> n >> x) {
        queue<int> deck, que;
        vector<int> sur;
        for(int i=0; i<20; ++i) {
            int t;
            cin >> t; deck.push(t);
        }
        for(int i=1; i<=n; ++i) que.push(i);
        while(que.size() > x && !deck.empty()) {
            int m = deck.front();
            for(int i=0, s=que.size(); i<s; ++i) {
                int q = que.front(); que.pop();
                if((i+1) % m) que.push(q);
                else if(que.size() == x) break;
            }
            deck.pop();
        }
        cout << "Selection #" << ++cnt << '\n';
        while(!que.empty()) {
            sur.push_back(que.front()); que.pop();
        }
        sort(sur.begin(), sur.end());
        for(int i=0, l=sur.size(); i<l; ++i) {
            cout << sur[i];
            if(i != l-1) cout << ' ';
        }
        cout << "\n\n";
    }
    return 0;
}