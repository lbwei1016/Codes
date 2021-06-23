/*
***4 Values whose Sum is 0***
    Solution:
        Initially, if we do not divide the four lists into two groups, 
        the time complexity is O(N^4). However, after we do it, with
        searching the excat values by "binary search", we can reach a 
        time complexity O(N^2 logN). Amazing!
    O(N^2 log N)
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4000;
int A[MAX_N+5], B[MAX_N+5], C[MAX_N+5], D[MAX_N+5];
int CD[MAX_N*MAX_N+5]; //enumerate the sum of C and D
int n;

long long solve()
{
    //enumerate the sum of C and D
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            CD[i*n+j] = C[i] + D[j];
        }
    }
    //we should sort first before applying binary search
    sort(CD, CD+n*n);
    long long res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int cd = -(A[i] + B[j]);

            //to find out the values excatly equal to cd
            //this is a impressive technique
            res += upper_bound(CD, CD+n*n, cd) - lower_bound(CD, CD+n*n, cd); 
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n ;i++) {
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
    }
    long long res = solve();
    printf("%d\n", res);
    return 0;
}