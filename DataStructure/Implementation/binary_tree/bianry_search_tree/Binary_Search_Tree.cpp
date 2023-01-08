#include <iostream>

#define MAX_N 1000

using namespace std;

struct node
{
    int value;
    node *left, *right;
}nodes[MAX_N+1];

int N;
//vector<node> bst;

void build_tree()
{
    for(int i=1; i<N; i++)
    {
        int temp;
        cin >> temp;
        nodes[i] = {.value = temp, .left = nullptr, .right = nullptr};
        node *search = &nodes[0];
        while(true)
        {
            if(nodes[i].value < (*search).value)
            {
                if((*search).left == nullptr)
                {
                    (*search).left = &nodes[i];
                    break;
                }
                else
                {
                    search = (*search).left;
                    continue;
                }
            }
            else
            {
                if((*search).right == nullptr)
                {
                    (*search).right = &nodes[i];
                    break;
                }
                else
                {
                    search = (*search).right;
                    continue;
                }
            }
        }
    }
}

void traversal(node *n)
{
    cout << (*n).value << ' ';
    if((*n).left != nullptr)
        traversal((*n).left);
    if((*n).right != nullptr)
        traversal((*n).right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N)
    {
        int temp;
        cin >> temp;
        nodes[0] = {.value = temp, .left = nullptr, .right = nullptr};
        build_tree();
        traversal(&nodes[0]);
        cout << '\n';
    }
    
    return 0;
}