/*
***Matrix Power Series***
    Description:
        Given a n * n matrix A and a positive integer k, find the sum 
        S = A + A^2 + A^3 +...+ A^k.
    Solution:
        Apply the same idea for calculating the power of a single matrix:
        Wrap the given matrix "A" into the other matrix "B" with "I"(unit-mat)
        and "0"(zero-mat) :
        -     -       -      -      -   -
        | A^k |       | A  0 |      | I |
        | Sk  |   =   | I  I |^k *  | 0 |
        -     -       -      -      -   -
        And Sk = I + A + A^2 +...A^(k-1)
    
    O(n^3 * log k)
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> v;
typedef vector<v> mat;

const int MAX_N = 30+3;
int n, k, m;
mat A;

mat mul(mat &m1, mat &m2) {

    int N = n * 2;
    mat res(N, v(N, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                res[i][j] = (res[i][j] + m1[i][k]*m2[k][j]) % m;
            }
        }
    }
    return res;
}

mat pow(mat &m, int k) {

    mat res = m;
    while(k > 0) {
        if(k & 1) {
            res = mul(res, m);
        }
        m = mul(m, m);
        k >>= 1;
    }
    return res;
}

void solve() {
    //initialize
    mat B(n * 2, v(n * 2, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            B[i][j] = A[i][j];
        }
        //
        B[n+i][i] = B[n+i][n+i] = 1;
    }

    B = pow(B, k);

    //print
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a = B[n+i][j];
            //to minus "I"(unit matrix), since the problem asks for A+....A^k
            if(i == j)
                a = (a + m - 1) % m;

            printf("%d%c", a, j == n-1 ? '\n' : ' ');
        }
    }
}


int main() {

    scanf("%d%d%d", &n, &k, &m);
    A.resize(n);
    for(int i=0; i<n; i++)
        A[i].resize(n);
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    solve();
    
    return 0;
}