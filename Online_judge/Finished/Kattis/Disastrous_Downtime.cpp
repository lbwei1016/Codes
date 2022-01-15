#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, TASK = 1000;
int n, k, _time[N];

bool check(int ser) {
    int st;
    for(int i=0; i<n; ++i) {
        st = _time[i];
        double tasks = upper_bound(_time+i+1, _time+n, st+TASK-1) - _time - i;
        if(int(ceil(tasks / k)) > ser) return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i) {
        cin >> _time[i];
    }
    
    int lb = 0, ub = N;
    while(ub-lb > 1) {
        int mid = (lb + ub) >> 1;
        if(check(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub << '\n';
    return 0;
}