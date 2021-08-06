/*
***Tree-Traversal***

    Solution: 
        用 Linked List 的概念，分別標記節點的父以及所有子節點，再由下(葉)而上走訪，並記錄高度
    O(Rank * Leaf_number)
*/
#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

struct node
{
    long h = 0, num;
    node *parent = nullptr;
    vector<node*> child;
}nodes[MAX_N+5];

long n, root_rank = 0, root;

void trav(node *n, long h) 
{
    node *p = (*n).parent;
    if(p == nullptr)
    {
        if(h > root_rank)
        {
            root = (*n).num;
            root_rank = (*n).h;
        }
        return;
    }
    (*p).h = max((*p).h, h+1);
    trav(p, h+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; //numbers
    for(int i=1; i<=n; i++)
    {
        nodes[i].num = i;
        int k;
        cin >> k;
        for(int j=0; j<k; j++)
        {
            int c;
            cin >> c;
            nodes[c].parent = &nodes[i];
            nodes[i].child.push_back(&nodes[c]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        //當該節點是「葉」的時候，向上走訪
        if(nodes[i].child.size() == 0)
            trav(&nodes[i], 0);
    }

    long sum = 0;
    for(int i=1; i<=n; i++)
        sum += nodes[i].h;
    cout << root << '\n' << sum << '\n';
    return 0;
}