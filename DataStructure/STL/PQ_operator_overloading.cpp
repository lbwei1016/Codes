#include <bits/stdc++.h>
using namespace std;

struct S {
    int a, b;
    // 第一個 const 非必須；第三個必須
    const bool operator < (const S &s) const {
        return a > s.a;
    }
};
int main() {
    priority_queue<S> pq;
    pq.push({1, 3}); pq.push({0, 4}); pq.push({9, 3});
    while(!pq.empty()) {
        cout << pq.top().a << ' ' << pq.top().b << '\n';
        pq.pop();
    }
    return 0;
}