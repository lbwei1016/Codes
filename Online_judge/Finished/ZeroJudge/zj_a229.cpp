/*
    There is a small doubt regarding the execution time:
        Testing on this device, using vector(at the end, commented) is far "faster" 
        than using the current one; however, I got a TLE using the vector one!!
*/
#include <bits/stdc++.h>

using namespace std;

int n;
//vector<char> v;
char v[30];
clock_t s, e;
void DFS(int left, int right, int cnt)
{
    if(cnt == 2*n)
    {
        v[cnt] = '\0';
        printf("%s\n", v);
        return;
    }

    if(left+1 >= right && left < n)
    {
        v[cnt] = '(';
        DFS(left+1, right, cnt+1);
    }
    if(left >= right+1 && right < n)
    {
        v[cnt] = ')';
        DFS(left, right+1, cnt+1);
    }
        
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    while(scanf("%d", &n) != EOF)
    {
      s = clock();
      DFS(0, 0, 0);
      e = clock();
      printf("Time spent: %d\n", e-s);
    }
    
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

int n;
vector<char> v;
//clock_t s, e; //<ctime>
void DFS(int left, int right)
{
    if(left == n && right == n)
    {
        for(char c : v)
            cout << c;
        cout << '\n';
        return;
    }

    if(left+1 >= right && left < n)
    {
        v.push_back('(');
        DFS(left+1, right);
        v.pop_back();
    }
    if(left >= right+1 && right < n)
    {
        v.push_back(')');
        DFS(left, right+1);
        v.pop_back(); //這或許也是一種backtracking
    }
        
}
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    while(cin >> n)
    {
        //s = clock();
        DFS(0, 0);
        v.clear();
        //e = clock();
        cout << '\n';
        //cout << "Time spent:" << (e-s) << '\n';
    }
    
    return 0;
}
*/