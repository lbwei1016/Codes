/*
****Sort*** --acknowledgement: https://yuihuang.com/zj-b966/
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N, L, R;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        //把線段的開始端點和結束端點視為獨立的evnet
        //在線段的開始端點L處，event +1
        v.push_back({L, 1});
        //在線段的結束端點R處，event -1
        v.push_back({R, -1});
    }
    sort(v.begin(), v.end());

    //now指向目前檢視的event

    int now = 0, event = 0, ans = 0;
    for (int i = 0; i <= 1e7; i++) {
        while (now < (int)v.size() && v[now].first == i) {
            event += v[now].second;
            now++;
        }
        //當有新的範圍左端出現，event++；當有某範圍的右端出現，代表該範圍結束，event--
        //若 event > 0，代表目前仍在某段範圍之中(還沒碰觸到右端而結束)
        if (event > 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}