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
int main()
{
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
    return 0;
}
void permutation(int d)
{
    if(d == n)
    {
        cnt++;
        for(int i : perm)
            cout << i << ' ';
        cout << '\n';
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