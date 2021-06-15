/*
***Union-Find Tree(Disjoint Set Union--DSU)***
**********************************************
    In this problem, the access to every element in the requiring set is
    needed, and that's why an array of "set" is used, whose elements are
    accessed by S[root[p]].
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010
int N, M;
int root[MAX_N];
set<int> S[MAX_N]; //use S[root[p]] to access the set including p
void init();
void unite(int, int);
void remove(int, int);
void print(int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N >> M)
    {
        init();
        while(M--)
        {
            int instr, p, q;
            cin >> instr;
            if(instr == 1)
            {
                cin >> p >> q;
                unite(p, q);
            }
            else if(instr == 2)
            {
                cin >> p >> q;
                remove(p, q);
            }
            else
            {
                cin >> p;
                print(p);
            }
        }
    }
    return 0;
}
void init()
{
    for(int i=1; i<=N; i++)
    {
        root[i] = i;
        S[i].clear();
        S[i].insert(i); //i = root[i]
    }
}
void unite(int p, int q) //unite the two sets including p & q
{
    p = root[p];
    q = root[q];
    if(p == q)
        return;
    if(S[p].size() > S[q].size()) //the small one merge into the big one
    {
        for(int i : S[q])
        {
            S[p].insert(i);
            root[i] = p;
        }
        S[q].clear();
    }
    else
    {
        for(int i : S[p])
        {
            S[q].insert(i);
            root[i] = q;
        }
        S[p].clear();
    }
}
void remove(int p, int q) //remove p from its current set to q's set
{
    S[root[p]].erase(p);
    root[p] = root[q]; //remember to modify p's root
    S[root[q]].insert(p);
}
void print(int p)
{
    set<int> temp = S[root[p]];
    long sum = 0;
    for(int i : temp)
    {
        sum += i;
    }
    cout << temp.size() << ' ' << sum << '\n';
}