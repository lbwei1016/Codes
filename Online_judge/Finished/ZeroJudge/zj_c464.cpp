/*
***Greedy***
    Solution: 
        如 comp 所示，兩兩比較即可，直接利用排序達到目的
    O(nlogn) : for sorting
*/
#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

struct stuff
{
    long long w, f;
}item[MAX_N+5];

bool comp(const stuff &s1, const stuff &s2)
{
    return (s1.f * s2.w) < (s2.f * s1.w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> item[i].w;
    for(int i=0; i<n; i++)
        cin >> item[i].f;
    sort(item, item+n, comp); //let back is up

    long long sum = 0;
    long long w = 0;
    for(int i=n-1; i>=0; i--)
    {
        sum += item[i].f * w;
        w += item[i].w;
    }
    cout << sum << '\n';

    return 0;
}