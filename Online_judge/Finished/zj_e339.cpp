#include <bits/stdc++.h>

using namespace std;

long long a[200000+5], b[200000+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    b[0] = a[0];
    for(int i=1; i<n; i++)
    {
        b[i] = b[i-1] + a[i];
    }
    for(int i=0; i<n; i++)
        cout << b[i] << ' ';
    cout << '\n';
    
    return 0;
}