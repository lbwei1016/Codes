/*
    Self-scripted permutation, slightly slower than next_permutation().
*/
#include <bits/stdc++.h>

using namespace std;

#define N 1000
int n, cnt = 0;
vector<int> v, perm;
bool used_next[N];
void permutation(int);
void perms(int, vector<list<int> >&);

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    clock_t s, e; //<ctime>
    cout << "Input n for n! :\n";
    cin >> n;
    v.resize(n);
    cout << "Input data for permutation\n";
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << '\n';

    s = clock();
    permutation(0);
    e = clock();
    cout << "n! = " << cnt << '\n';
    cout << "Time spent: " << e-s << " ms\n";


    vector<list<int> > pe;
    s = clock();
    perms(n, pe);
    // for (auto &s: pe) {
    //     for (auto &x: s) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }
    e = clock();
    cout << "n! = " << cnt << '\n';
    cout << "Time spent: " << e-s << " ms\n";
    return 0;
}

void permutation(int d) {
    if(d == n)
    {
        // cnt++;
        // for(int i : perm)
        //     cout << i << ' ';
        // cout << '\n';
        return;
    }
    int j;
    bool used_here[N];
    memset(used_here, 0, sizeof(used_here));
    for(int i=d; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(!used_next[j] && !used_here[j])
            {
                perm.push_back(v[j]);
                used_next[j] = true;
                used_here[j] = true;
                break;
            }
        }
        permutation(d+1);
        perm.pop_back();
        used_next[j] = false;
    }
    used_here[j] = false;
    return;
}

// Form TAOCP 1-2-5 p.46; lack of space management, hence plenty of time wasted on copying
void perms(int d, vector<list<int> > &perm) {
    if (d == 1) {
        perm.push_back(list<int>(1, 1));
        return;
    }
    perms(d-1, perm);
    int sz = perm.size();
    for (int j=sz-1; j>=0; --j) {
        for (int i=0; i<d; ++i) {
            auto s = perm[j];
            s.insert(next(s.begin(), i), d);
            perm.push_back(s);
        }
        perm.erase(next(perm.begin(), j));
    }
}