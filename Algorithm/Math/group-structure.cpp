/*
Determine the group structure of the multiplicative group modulo n.
    Input:  a positive integer n. 
    Output: a product of cyclic groups which is isomorphic to the multiplicative group modulo n. 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int n; // input; the multi. group of n
int M; // the size of the multi. group
set<int> S;

bool isprime[MAXN];
vector<int> primes;

void sieve() {
    fill(isprime + 2, isprime + MAXN, true);
    for (int i=2; i<MAXN; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j=2*i; j<MAXN; j+=i) {
                isprime[j] = false;
            }
        }
    }
}

// fast power
int fpow(int x, int d) {
    int res = 1;
    while (d > 0) {
        if (d & 1) {
            res *= x;
            res %= n;
        }
        d >>= 1;
        x *= x;
        x %= n;
    }
    return res;
}

// multiply with itself
void torsion(int factor) {
    set<int> nS;
    for (auto x: S) {
        int at = fpow(x, factor);
        nS.insert(at);
    }
    S = nS;
}

void rec(const int cnt, vector<int> &groups, const int factor) {
    int presz = S.size();
    torsion(factor);

    // how many times the size is reduced
    int ratio = presz / S.size(); 
    
    int nowGroupNum = 0;
    while (ratio > 1) {
        ratio /= factor;
        nowGroupNum++;
    }

    // current factor has been used up!
    if (S.size() % factor != 0) {
        groups.assign(nowGroupNum, 1);
        return;
    }

    rec(cnt, groups, factor);

    int sum = 0; // cannot exceed "cnt"
    for (auto x: groups) sum += x;

    // restore group after torsion
    for (auto &x: groups) {
        if (sum == cnt) return;
        x++; sum++;
    }

    // add back eliminated groups
    while (nowGroupNum > groups.size() && sum < cnt) {
        sum++;
        groups.push_back(1);
    }
}

void print(map<int, vector<int>> &mp) {
    printf("Input: %d\n", n);
    printf("The order of this group is: %d\n\n", M);
    printf("Its structure is:\n");
    for (auto &p: mp) {
        for (int i=0; i<p.second.size(); ++i) {
            printf(" %d^%d %c", p.first, p.second[i], (i == p.second.size()-1 ? '\n' : '*'));
        }
    }
}

int main() {
    sieve();
    printf("Please input a number n:\n");
    cin >> n;
    int rr = 0;
    for (int i=1; i<n; ++i) {
        if (gcd(i, n) != 1) continue;
        S.insert(i);
    }

    int m = S.size(); M = m;
    map<int, vector<int>> mp;
    for (auto x: primes) {
        int cnt = 0;
        while (m % x == 0) {
            ++cnt;
            m /= x;
        }
        if (cnt == 0) continue;

        vector<int> groups;
        rec(cnt, groups, x);
        mp[x] = groups;
    }

    print(mp);
    return 0;
}