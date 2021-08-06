/*
***爬行法***

    O(P * log P)
*/
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_P = 1000000;
int P;
int p[MAX_P+5];


void solve()
{
    set<int> ideas;
    for(int i=0; i<P; i++)
        ideas.insert(p[i]);

    int res = P;
    int f = 0, t = 0, num = 0;
    int n = ideas.size();
    map<int, int> read; //category, times
    while(true)//O(P)
    {
        while(t < P && num < n) 
        {
            if(read[p[t++]]++ == 0) //O(log P): binary search tree
            {
                num++; //a new category emerged
            }
                
        }
        if(num < n) break;
        res = min(res, t - f);
        if(--read[p[f++]] == 0) //O(log P): binary search tree
        {
            num--;
        }
    }
    printf("%d", res);
}

int main()
{
    scanf("%d", &P);
    for(int i=0; i<P; i++)
        scanf("%d", &p[i]);
    solve();
    return 0;
}